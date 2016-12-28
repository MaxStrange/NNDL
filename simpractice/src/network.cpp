#include <iostream>
#include <vector>

#include "debug.h"
#include "layer.h"
#include "signal.h"
#include "synapse.h"

#include "network.h"


Network::Network(std::vector<Layer *> *layers, std::vector<Synapse *> *connections)
{
    this->layers = layers;
    std::vector<Neuron *> neurons;
    for (unsigned int i = 0; i < layers->size(); i++)
    {
        Layer *layer = layers->at(i);
        for (unsigned int j = 0; j < layer->size(); j++)
        {
            Neuron *n = layer->at(j);
            neurons.push_back(n);
        }
    }
    this->connection_map = ConnectionMap(connections, neurons);
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
    outstream << this->connection_map << std::endl;
    outstream << debug_print_closing("Network") << std::endl;

    return outstream;
}

std::vector<Signal> Network::fire_backward(std::vector<Signal> input)
{
    //TODO
    //Do fire_forward's algorithm, but backwards
    return input;
}

std::vector<Signal> Network::fire_forward(std::vector<Signal> input)
{
    const bool forward = true;

    //a vector of tuples
    //the tuples are of type: Signal, vector<Neuron *> *
    //These tuples are going to be the list of outgoing signals paired
    //with which Neurons they are going into
    std::vector<std::tuple<Signal, std::vector<Neuron *> *>> tuples;

    //Set of neurons that has already fired during this round of firing
    std::set<Neuron *> already_fired;

    //For each neuron in the input layer,
    Layer *input_layer = this->layers->at(0);
    for (unsigned int i = 0; i < input_layer->size(); i++)
    {
        Neuron *n_i = input_layer->at(i);
        Signal s_i = input.at(i);
        auto output_to_neurons = this->fire_neuron(n_i, s_i, already_fired, forward);
        tuples.push_back(output_to_neurons);
    }

    //Now you should have a vector of tuples of each neuron's result paired
    //with the neurons that that result is going to

    std::vector<std::tuple<Neuron *, Signal>> output_neurons;

    //repeat this until you have a vector of values that are not paired with
    //neurons - these are your output values
    while (this->keep_going(tuples))
    {
        std::vector<std::tuple<Signal, std::vector<Neuron *> *>> tmp_tuples;
        //For each neuron that the results are going to, get that neuron's output
        for (unsigned int i = 0; i < tuples.size(); i++)
        {
            std::tuple<Signal, std::vector<Neuron *> *>> tup = tuples.at(i);
            Signal outgoing = std::get<0>(tup);
            std::vector<Neuron *> *into = std::get<1>(tup);
            for (unsigned int j = 0; j < into->size(); j++)
            {
                Neuron *n_j = into->at(j);
                //Pair up that neuron's output with each of its output neurons
                if (already_in.find(n_j) == already_in.end())
                {
                    //only fire if this neuron hasn't already fired this round
                    auto this_neurons_output_tup = this->fire_neuron(
                            n_j, outgoing, already_fired, forward);

                    if (this->neuron_is_output_neuron(n_j))
                    {
                        //if this is an output neuron, we need it's output,
                        //and we need to know which particular neuron it is
                        Signal output_neuron_signal =
                                std::get<0>(this_neurons_output_tup);
                        auto output_neuron_with_signal = std::make_tuple(
                                n_j, output_neuron_signal);
                        output_neurons.push_back(output_neuron_with_signal);
                    }

                    tmp_tuples.push_back(this_neurons_output_tup);
                }
            }
        }
        tuples.clear();
        tuples = tmp_tuples;
    }

    //We now have a vector of tuples of the form: <Neuron *, Signal>
    //We need to use the first values in these tuples to arrange the Signals
    //to be in the right order for the network's output vector

    return input;
}

std::tuple<Signal, std::vector<Neuron *> *> Network::fire_neuron(
        Neuron *n_i, const Signal &s_i,
        std::set<Neuron *> &already_fired, bool forward)
{
    //get that neuron's output
    Signal n_i_output;
    if (forward)
        n_i_output = n_i->fire_forward(s_i);
    else
        n_i_output = n_i->fire_backward(s_i);

    //Pair up that neuron's output with each of its output neurons
    std::vector<Neuron *> *n_i_output_neurons =
            this->connection_map->get_outputs(n_i);
    auto output_to_neurons = std::make_tuple(n_i, n_i_output_neurons);

    //Keep track of which neurons have fired
    already_fired.insert(n_i);

    return output_to_neurons;
}

bool Network::keep_going(std::vector<std::tuple<Signal, std::vector<Neuron *> *>> &t)
{
    auto keep_going = [](
        std::vector<std::tuple<Signal, std::vector<Neuron *> *>> &t)
    {
        for (unsigned int z = 0; z < t.size(); z++)
        {
            auto tup = t.at(z);
            std::vector<Neuron *> *vec = std::get<1>(tup);
            if (vec->size() > 0)
                return true;
        }
        return false;
    }
}














