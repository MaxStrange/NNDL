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
    this->initialize_connection_map(connections);
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
    std::cout << "Copying..." << std::endl;
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
    //TODO
    //Do fire_forward's algorithm, but backwards
    return input;
}

std::vector<Signal> Network::fire_forward(uint64_t t, std::vector<Signal> input)
{
    std::vector<std::tuple<Neuron *, Signal>> outputs;

    //for each node in the topologically sorted network
    for (unsigned int i = 0; i < this->top_sorted_network.size(); i++)
    {
        Neuron *n = this->top_sorted_network.at(i);

        //get that node's inputs (which includes firing the synapses)
        std::vector<Signal> inputs;
        inputs = this->get_node_inputs(t, n, outputs, inputs);

        //put those values into the node to get its outputs
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
 * Gets the given Neuron's input Signals and returns them.
 * Gets these Signals from the so far calculated Signals found in outputs.
 * Also fires any Signals it retrieves through the appropriate Synapses
 * before adding them to the list to return.
 */
std::vector<Signal>& Network::get_node_inputs(uint64_t t, const Neuron *n,
        std::vector<std::tuple<Neuron *, Signal>> &outputs,
        std::vector<Signal> &inputs)
{
    for (unsigned int i = 0; i < outputs.size(); i++)
    {
        Neuron *m;
        Signal s;
        std::tie(m, s) = outputs.at(i);
        if (this->connection_map.neuron_synapses_onto(m, n))
        {
            Synapse syn;
            this->connection_map.get_synapse(m, n, syn);
            s = syn.fire_forward(t, s);
            inputs.push_back(s);
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

bool Network::is_all_synapses(const std::set<Synapse *> &G)
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
    return G == all;
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

    std::vector<Neuron *> L;
    std::set<Neuron *> S;
    std::set<Synapse *> G;

    while (S.size() > 0)
    {
        Neuron *n = *S.begin();
        L.push_back(n);

        std::vector<Neuron *> to;
        this->connection_map.get_outputs(n, to);
        for (unsigned int i = 0; i < to.size(); i++)
        {
            Neuron *m = to.at(i);
            Synapse e;
            this->connection_map.get_synapse(n, m, e);
            G.insert(&e);

            //if each of m's outgoing synapses are in G,
            //add m to S
            std::vector<Neuron *> m_outgoing;
            this->connection_map.get_outputs(m, m_outgoing);
            bool m_has_no_more_edges = true;
            for (unsigned int j = 0; j < m_outgoing.size(); j++)
            {
                Neuron *p = m_outgoing.at(j);
                Synapse m_syn;
                this->connection_map.get_synapse(m, p, m_syn);
                if (G.find(&m_syn) == G.end())
                    m_has_no_more_edges = false;
            }

            if (m_has_no_more_edges)
                S.insert(m);
        }
    }

    //if G does not contain all the synapses,
    //then there is at least one cycle in the network, and our algorithm
    //cannot handle that
    if (this->is_all_synapses(G))
    {
        return L;
    }
    else
    {
        throw std::runtime_error("The network has a cycle in it.");
    }
}

UnitTestResult Network::run_tests()
{
    UnitTestResult result;
    Network::test_filter_for_output_neurons(result);
    Network::test_get_node_inputs(result);
    Network::test_is_all_synapses(result);
    Network::test_map_to_output(result);
    Network::test_neuron_is_output_neuron(result);
    Network::test_topological_sort(result);

    return result;
}

void Network::test_filter_for_output_neurons(UnitTestResult &result)
{
}

void Network::test_get_node_inputs(UnitTestResult &result)
{
}

void Network::test_is_all_synapses(UnitTestResult &result)
{
}

void Network::test_map_to_output(UnitTestResult &result)
{
}

void Network::test_neuron_is_output_neuron(UnitTestResult &result)
{
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

    Neuron a("a"), b("b"), c("c"), d("d"), e("e");

    std::vector<Layer *> test_layers;
    Layer input, hidden, output;
    input.add_neuron(a); input.add_neuron(b);
    hidden.add_neuron(c); hidden.add_neuron(d);
    output.add_neuron(e);
    test_layers.push_back(&input); test_layers.push_back(&hidden);
            test_layers.push_back(&output);

    Neuron *ap, *bp, *cp, *dp, *ep;
    ap = input.at(0);
    bp = input.at(1);
    cp = hidden.at(0);
    dp = hidden.at(1);
    ep = output.at(0);

    std::vector<Synapse *> test_connections;
    Synapse *ba = new Synapse(bp, ap);
    Synapse *ac = new Synapse(ap, cp);
    Synapse *ad = new Synapse(ap, dp);
    Synapse *dc = new Synapse(dp, cp);
    Synapse *ce = new Synapse(cp, ep);
    test_connections.push_back(ba); test_connections.push_back(ac);
    test_connections.push_back(ad); test_connections.push_back(dc);
    test_connections.push_back(dc); test_connections.push_back(ce);

    test_network = Network(&test_layers, &test_connections);
}









