#include <iostream>
#include <stdexcept>
#include <vector>

#include "connection_map.h"
#include "debug.h"
#include "layer.h"
#include "signal.h"
#include "synapse.h"
#include "unit_tests.h"

#include "network.h"

#include NEURON_HEADER
#include SYNAPSE_HEADER


Network::Network()
{
}

Network::Network(const Network &to_copy)
{
    *this = to_copy;
}

Network::Network(std::vector<Layer *> *layers,
        std::vector<Synapse *> *connections)
{
    this->layers = layers;
    std::cout << "Setting up hashes for the network..." << std::endl;
    this->initialize_connection_map(connections);
    std::cout << "Doing a topological sort of the whole network..." << std::endl;
    this->top_sorted_network = this->topological_sort();
}

Network::~Network()
{
}

std::ostream& operator<<(std::ostream &outstream, const Network &nw)
{
    outstream << debug_print_header("Network") << std::endl;
    outstream << "Layers: " << std::endl;
    for (unsigned int i = 0; i < nw.layers->size(); i++)
    {
        Layer *l = nw.layers->at(i);
        outstream << *l << std::endl;
    }
    outstream << "ConnectionMap: " << std::endl;
    outstream << nw.connection_map << std::endl;
    outstream << debug_print_closing("Network") << std::endl;

    return outstream;
}

Network& Network::operator=(const Network &rhs)
{
    if (this != &rhs)
    {
        this->layers = rhs.layers;
        this->connection_map = rhs.connection_map;
        this->top_sorted_network = this->topological_sort();
    }

    return *this;
}

std::vector<Signal> Network::fire_backward(uint64_t t, std::vector<Signal> input)
{
    std::vector<std::tuple<Neuron *, Signal>> outputs;

    for (int i = this->top_sorted_network.size() - 1; i >= 0; i--)
    {
        //for each node in the sorted network, going backwards
        Neuron *n = this->top_sorted_network.at(i);

        //get that node's inputs and fire synapses
        //this is going backwards though - so the output layer will take in
        //the input vector, and then output tuples into outputs
        std::vector<Signal> inputs;
        inputs = this->get_node_inputs_backward(t, n, outputs, inputs, input);

        //inputs is now a vector of signals going into n (again, going from
        //output layer toward input layer)

        //So now get the Signal that n fires when going backward
        n = dynamic_cast<NEURON *>(n);
        Signal output = n->fire_backward(t, inputs);

        //Now pair that signal with n and put it into the list that we are using
        //to figure out what values each Neuron gets as its backwards input
        outputs.push_back(std::make_tuple(n, output));
    }

    //After each node in the list fires,
    //filter the list of Neurons to Signals so that it only contains those
    //Neurons which are in the input layer
    std::vector<std::tuple<Neuron *, Signal>> input_neurons;
    input_neurons = this->filter_for_input_neurons(outputs, input_neurons);

    //Now organize that layer into a vector of Signals coming out of the input
    //layer
    std::vector<Signal> output;
    output = this->map_to_input(input_neurons, output);

    return output;
}

std::vector<Signal> Network::fire_forward(uint64_t t, std::vector<Signal> input)
{
    std::vector<std::tuple<Neuron *, Signal>> outputs;

    for (unsigned int i = 0; i < this->top_sorted_network.size(); i++)
    {
        //for each node in the topologically sorted network
        Neuron *n = this->top_sorted_network.at(i);

        //get that node's inputs (which includes firing the synapses)
        std::vector<Signal> inputs;
        inputs = this->get_node_inputs(t, n, outputs, inputs, input);

        //put those values into the node to get its outputs
        n = dynamic_cast<NEURON *>(n);
        Signal output = n->fire_forward(t, inputs);
        outputs.push_back(std::make_tuple(n, output));
    }

    //once you are done with the whole list,
    //filter it to get only the nodes that are from the output layer
    std::vector<std::tuple<Neuron *, Signal>> output_neurons;
    output_neurons = this->filter_for_output_neurons(outputs, output_neurons);

    //then organize that layer into a vector
    std::vector<Signal> output;
    output = this->map_to_output(output_neurons, output);

    return output;
}

Layer* Network::get_input_layer() const
{
    return this->layers->front();
}

Layer* Network::get_output_layer() const
{
    return this->layers->back();
}

std::vector<std::tuple<Neuron *, Signal>>& Network::filter_for_input_neurons(
        std::vector<std::tuple<Neuron *, Signal>> &outputs,
        std::vector<std::tuple<Neuron *, Signal>> &input_neurons) const
{
    for (unsigned int i = 0; i < outputs.size(); i++)
    {
        auto t = outputs.at(i);
        const Neuron *n = std::get<0>(t);
        if (this->neuron_is_input_neuron(n))
            input_neurons.push_back(t);
    }

    return input_neurons;
}

/*
 * Filters the output list so that it only contains output neurons.
 */
std::vector<std::tuple<Neuron *, Signal>>& Network::filter_for_output_neurons(
        std::vector<std::tuple<Neuron *, Signal>> &outputs,
        std::vector<std::tuple<Neuron *, Signal>> &output_neurons) const
{
    for (unsigned int i = 0; i < outputs.size(); i++)
    {
        auto t = outputs.at(i);
        const Neuron *n = std::get<0>(t);
        if (this->neuron_is_output_neuron(n))
            output_neurons.push_back(t);
    }

    return output_neurons;
}

/*
 * Gets all the Neurons in this network that have no incoming
 * Synapses.
 */
std::set<Neuron *> Network::get_all_nodes_no_incoming()
{
    std::set<Neuron *> ret;

    for (unsigned int i = 0; i < this->layers->size(); i++)
    {
        Layer *l = this->layers->at(i);
        for (unsigned int j = 0; j < l->size(); j++)
        {
            Neuron *n = l->at(j);
            std::vector<Neuron *> input_neurons;
            this->connection_map.get_inputs(n, input_neurons);
            if (input_neurons.size() == 0)
                ret.insert(n);
        }
    }

    return ret;
}

/*
 * Gets the given Neuron's input Signals and returns them.
 * Gets these Signals from the so far calculated Signals found in outputs.
 * Also fires any Signals it retrieves through the appropriate Synapses
 * before adding them to the list to return.
 * If the Neuron is in the input layer, it actually gets its Signal from
 * the network_input vector.
 */
std::vector<Signal>& Network::get_node_inputs(uint64_t t, const Neuron *n,
        std::vector<std::tuple<Neuron *, Signal>> &outputs,
        std::vector<Signal> &inputs, const std::vector<Signal> &network_input)
{
    if (this->neuron_is_input_neuron(n))
    {
        //if this neuron is an input layer neuron, its vector of inputs
        //is simply a single Signal that corresponds to its place in the
        //vector of network_inputs
        int index = this->get_input_layer()->get_neuron_index(n);
        Signal s = network_input.at(index);
        inputs.push_back(s);
    }
    else
    {
        for (unsigned int i = 0; i < outputs.size(); i++)
        {
            Neuron *m;
            Signal s;
            std::tie(m, s) = outputs.at(i);
            if (this->connection_map.neuron_synapses_onto(m, n))
            {
                Synapse *syn;
                this->connection_map.get_synapse(m, n, syn);
                syn = dynamic_cast<SYNAPSE *>(syn);
                s = syn->fire_forward(t, s);
                inputs.push_back(s);
            }
        }
    }

    return inputs;
}

std::vector<Signal>& Network::get_node_inputs_backward(uint64_t t, const Neuron *n,
        std::vector<std::tuple<Neuron *, Signal>> &outputs,
        std::vector<Signal> &inputs, const std::vector<Signal> &network_input)
{
    if (this->neuron_is_output_neuron(n))
    {
        //if this neuron is an output layer neuron, its vector of inputs
        //is simply a single Signal that corresponds to its place in the
        //vector of network_inputs
        int index = this->get_output_layer()->get_neuron_index(n);
        Signal s = network_input.at(index);
        inputs.push_back(s);
    }
    else
    {
        for (unsigned int i = 0; i < outputs.size(); i++)
        {
            Neuron *m;
            Signal s;
            std::tie(m, s) = outputs.at(i);
            if (this->connection_map.neuron_synapses_onto(n, m))
            {
                Synapse *syn;
                this->connection_map.get_synapse(n, m, syn);
                syn = dynamic_cast<SYNAPSE *>(syn);
                s = syn->fire_backward(t, s);
                inputs.push_back(s);
            }
        }
    }

    return inputs;
}

void Network::initialize_connection_map(std::vector<Synapse *> *connections)
{
    std::vector<Neuron *> neurons;
    for (unsigned int i = 0; i < this->layers->size(); i++)
    {
        Layer *layer = this->layers->at(i);
        for (unsigned int j = 0; j < layer->size(); j++)
        {
            Neuron *n = layer->at(j);
            neurons.push_back(n);
        }
    }
    this->connection_map = ConnectionMap(*connections, neurons);
}

bool Network::is_all_synapses(const std::set<Synapse *> &graph)
{
    //Get all the synapses in the network
    std::set<Synapse *> all;
    for (unsigned int i = 0; i < this->layers->size(); i++)
    {
        Layer *l = this->layers->at(i);
        for (unsigned int j = 0; j < l->size(); j++)
        {
            Neuron *n = l->at(j);
            std::vector<Synapse *> syns;
            this->connection_map.get_output_synapses(n, syns);
            for (unsigned int k = 0; k < syns.size(); k++)
            {
                Synapse *s = syns.at(k);
                all.insert(s);
            }
        }
    }

    //Now check if the two sets G and all are the same
    return graph == all;
}

std::vector<Signal>& Network::map_to_input(std::vector<std::tuple<
        Neuron *, Signal>> &input_neurons, std::vector<Signal> &output)
{
    for (unsigned int i = 0; i < this->get_input_layer()->size(); i++)
    {
        //Figure out which Neuron in the input_neurons list is the
        //ith one in the input layer and get its signal
        Neuron *n_i = this->get_input_layer()->at(i);
        int index = -1;
        for (unsigned int j = 0; j < input_neurons.size(); j++)
        {
            auto input_neuron_and_signal = input_neurons.at(j);
            Neuron *n_j = std::get<0>(input_neuron_and_signal);
            if (n_j == n_i)
            {
                index = j;
                break;
            }
        }
        if (index == -1)
            throw std::runtime_error("Could not find neuron on back firing");

        auto input_neuron_and_signal = input_neurons.at(index);
        Signal s_i = std::get<1>(input_neuron_and_signal);
        output.push_back(s_i);
    }

    return output;
}

/*
 * Takes the output vector and populates it in order of output neuron 0 to
 * output neuron layer.size() - 1.
 */
std::vector<Signal>& Network::map_to_output(std::vector<std::tuple<
        Neuron *, Signal>> &output_neurons, std::vector<Signal> &output)
{
    for (unsigned int i = 0; i < this->get_output_layer()->size(); i++)
    {
        //Figure out which neuron in the output_neurons list is
        //the ith one in the output layer and get its signal
        Neuron *n_i = this->get_output_layer()->at(i);
        int index = -1;
        for (unsigned int j = 0; j < output_neurons.size(); j++)
        {
            auto output_neuron_and_signal = output_neurons.at(j);
            Neuron *n_j = std::get<0>(output_neuron_and_signal);
            if (n_j == n_i)
            {
                index = j;
                break;
            }
        }
        if (index == -1)
            throw std::runtime_error("Could not find neuron.");

        auto output_neuron_and_signal = output_neurons.at(index);
        Signal s_i = std::get<1>(output_neuron_and_signal);
        output.push_back(s_i);
    }

    return output;
}

bool Network::neuron_is_input_neuron(const Neuron *n) const
{
    const Layer *layer = this->get_input_layer();
    return layer->contains(n);
}

bool Network::neuron_is_output_neuron(const Neuron *n) const
{
    const Layer *layer = this->get_output_layer();
    return layer->contains(n);
}

/*
 * Topologically sorts the network into a vector, so that
 * the first item in the vector is a Neuron that requires no
 * inputs but outside inputs, etc. Ties are decided arbitrarily.
 */
std::vector<Neuron *> Network::topological_sort()
{
    //Kahn's algorithm, see Wikipedia

    std::vector<Neuron *> top_sorted;
    std::set<Neuron *> nodes_no_incoming = this->get_all_nodes_no_incoming();
    //Graph is a set of edges, which should eventually contain all of the edges
    //in the network
    std::set<Synapse *> graph;

    //While nodes_no_incoming is not empty
    while (nodes_no_incoming.size() > 0)
    {
        //remove a node form nodes_no_incoming
        Neuron *n = *nodes_no_incoming.begin();
        nodes_no_incoming.erase(n);

        //Add that node to the end of top_sorted
        top_sorted.push_back(n);

        //For each edge e from n to m
        std::vector<Neuron *> to;
        this->connection_map.get_outputs(n, to);
        for (unsigned int i = 0; i < to.size(); i++)
        {
            Neuron *m = to.at(i);

            //Remove edge e from the graph
            //(we don't remove anything - instead, we add the edges that
            //we should remove to a set and check the set before attempting to
            //use an edge that should have been removed)
            Synapse *e;
            this->connection_map.get_synapse(n, m, e);

            //If e has not been removed from the network
            if (graph.find(e) == graph.end())
            {
                //remove it from the network
                graph.insert(e);

                //if m has no other incoming edges
                std::vector<Synapse *> incoming_edges;
                this->connection_map.get_input_synapses(m, incoming_edges);
                bool m_has_no_other_incoming_edges = true;
                //If all incoming_edges have been added to graph,
                //then m has no other incoming edges
                for (unsigned int j = 0; j < incoming_edges.size(); j++)
                {
                    Synapse *incoming_edge = incoming_edges.at(j);
                    if (graph.find(incoming_edge) == graph.end())
                        m_has_no_other_incoming_edges = false;
                }

                //insert m into nodes_no_incoming
                if (m_has_no_other_incoming_edges)
                    nodes_no_incoming.insert(m);
            }
        }
    }

    //if graph does not contain all the synapses,
    //then there is at least one cycle in the network, and our algorithm
    //cannot handle that
    if (this->is_all_synapses(graph))
    {
        return top_sorted;
    }
    else
    {
        throw std::runtime_error("The network has a cycle in it.");
    }
}

UnitTestResult Network::run_tests()
{
    UnitTestResult result;
    Network::test_neuron_is_output_neuron(result);
    Network::test_topological_sort(result);

    return result;
}

void Network::test_neuron_is_output_neuron(UnitTestResult &result)
{
    std::string class_name = "Network";
    std::string test_name = "neuron_is_output_neuron";

    Network test_network;
    Network::create_test_network(test_network);

    Neuron *n = *test_network.top_sorted_network.end();
    bool is_output_neuron = test_network.neuron_is_output_neuron(n);
    result.assert(is_output_neuron, class_name, test_name,
            "The last Neuron in the topological list must be an output neuron");
}

void Network::test_topological_sort(UnitTestResult &result)
{
    std::string class_name = "Network";
    std::string test_name = "topological_sort";

    Network test_network;
    Network::create_test_network(test_network);
    std::vector<Neuron *> top_sorted = test_network.top_sorted_network;

    //Topologically sorted:
    //b -> a -> d -> c -> e
    bool ordered = top_sorted.at(0)->get_id() == "b" &&
            top_sorted.at(1)->get_id() == "a" &&
            top_sorted.at(2)->get_id() == "d" &&
            top_sorted.at(3)->get_id() == "c" &&
            top_sorted.at(4)->get_id() == "e";
    result.assert(ordered, class_name, test_name, "Not sorted topologically");
}

void Network::create_test_network(Network &test_network)
{
    //Create a test network:
    //a -> c -> e
    //^ \  ^
    //b -> d
    //Including a synapse from a to d

    Neuron a("a", true, false), b("b", true, false), c("c", false, false),
            d("d", false, false), e("e", false, true);

    std::vector<Layer *> test_layers;
    Layer *input = new Layer();
    Layer *hidden = new Layer();
    Layer *output = new Layer();
    input->add_neuron(a);
    input->add_neuron(b);
    hidden->add_neuron(c);
    hidden->add_neuron(d);
    output->add_neuron(e);
    test_layers.push_back(input);
    test_layers.push_back(hidden);
    test_layers.push_back(output);

    Neuron *ap, *bp, *cp, *dp, *ep;
    ap = input->at(0);
    bp = input->at(1);
    cp = hidden->at(0);
    dp = hidden->at(1);
    ep = output->at(0);

    Signal w(1);

    std::vector<Synapse *> test_connections;
    Synapse *ba = new Synapse(bp, ap, w);
    Synapse *ac = new Synapse(ap, cp, w);
    Synapse *ad = new Synapse(ap, dp, w);
    Synapse *dc = new Synapse(dp, cp, w);
    Synapse *ce = new Synapse(cp, ep, w);
    Synapse *bd = new Synapse(bp, dp, w);
    test_connections.push_back(ba); test_connections.push_back(ac);
    test_connections.push_back(ad); test_connections.push_back(dc);
    test_connections.push_back(bd); test_connections.push_back(ce);

    test_network = Network(&test_layers, &test_connections);
}









