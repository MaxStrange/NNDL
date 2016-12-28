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
    this->connection_map = ConnectionMap(*connections, neurons);
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

    //List of tuples of the form output Neuron to the signal it is sending
    //but not necessarily in the right order
    std::vector<std::tuple<Neuron *, Signal>> output_neurons;

    //For each input neuron,
    //fire that neuron and pair its signal with the neurons the signal will go to
    tuples = this->fire_input_layer(tuples, already_fired, forward, output_neurons);

    //Now you should have a vector of tuples of each neuron's result paired
    //with the neurons that that result is going to


    //As long as there are still non-output neurons that have signals being
    //sent to them AND as long as those neurons haven't already fired once
    //this time step,
    while (this->keep_going(tuples))
    {
        //Fire the neurons who are indicated by the list of signal/neurons pairs
        tuples = fire_neurons_in_list(tuples, already_fired,
                forward, output_neurons);

        //Again you are left with a vector of tuples of each neuron's result
        //paired with the neurons that the result is going to

        //But there are a couple of differences this time:
        //first, you also may have some output neurons paired with their outgoing
        //signals
        //second, the number of new neurons to fire has changed - and it will
        //eventually go to zero, at which point the algorithm is complete for
        //this timestep
    }

    //We now have a vector of tuples of the form: <Neuron *, Signal>
    //We need to use the first values in these tuples to arrange the Signals
    //to be in the right order for the network's output vector
    std::vector<Signal> output;
    output = this->map_to_output(output_neurons, output);

    return output;
}

/*
 * Fires each neuron in the input layer and returns the result as
 * a vector of signals paired with which neurons those signals need
 * to go to.
 */
std::tuple<Signal, std::vector<Neuron *> *>& Network::fire_input_layer(
        std::tuple<Signal, std::vector<Neuron *> *> &tuples,
        std::set<Neuron *> &already_fired, bool forward,
        std::vector<std::tuple<Neuron *, Signal>> &output_neurons)
{
    for (unsigned int i = 0; i < this->get_input_layer()->size(); i++)
    {
        Neuron *n_i = this->get_input_layer()->at(i);
        Signal s_i = input.at(i);
        std::vector<Signal> signals;
        signals.push_back(s_i);
        auto output_to_neurons =
                this->fire_neuron(n_i, signals, already_fired, forward);
        if (this->neuron_is_output_neuron(n_i))
        {
            auto tup = std::make_tuple(n_i, s_i);
            output_neurons.push_back(tup);
        }
        tuples.push_back(output_to_neurons);
    }

    return tuples;
}

std::tuple<Signal, std::vector<Neuron *> *> Network::fire_neuron(
        Neuron *n_i, const std::vector<Signal> &signals,
        std::set<Neuron *> &already_fired, bool forward)
{
    Signal n_i_output;
    if (forward)
        n_i_output = n_i->fire_forward(s_i);
    else
        n_i_output = n_i->fire_backward(s_i);

    std::vector<Neuron *> n_i_output_neurons;
    std::vector<Synapse *> output_synapses;
    if (forward)
    {
        this->connection_map->get_outputs(n_i, n_i_output_neurons);
        this->connection_map->get_synapses_from_neuron(n_i, output_synapses);
    }
    else
    {
        this->connection_map->get_inputs(n_i, n_i_output_neurons);
        this->connection_map->get_synapses_to_neuron(n_i, output_synapses);
    }

    //Now give each synapse a chance to do model-specific stuff
    for (unsigned int i = 0; i < output_synapses.size(); i++)
    {
        if (forward)
            n_i_output
    }

    auto output_to_neurons = std::make_tuple(n_i, n_i_output_neurons);

    already_fired.insert(n_i);

    return output_to_neurons;
}

std::tuple<Signal, std::vector<Neuron *> *>& Network::fire_neurons_in_list(
        std::tuple<Signal, std::vector<Neuron *> *> &tuples,
        std::set<Neuron *> &already_fired, bool forward,
        std::vector<std::tuple<Neuron *, Signal>> &output_neurons)
{
    std::vector<std::tuple<Signal, std::vector<Neuron *> *>> tmp_tuples;

    //Take the list of signals and the neurons those signals are going into
    //and:
    //for each signal,
    for (unsigned int i = 0; i < tuples.size(); i++)
    {
        std::tuple<Signal, std::vector<Neuron *> *>> tup = tuples.at(i);
        Signal outgoing = std::get<0>(tup);

        //for each neuron that that signal is going into
        std::vector<Neuron *> *into = std::get<1>(tup);
        for (unsigned int j = 0; j < into->size(); j++)
        {
            Neuron *n_j = into->at(j);

            //If that neuron hasn't already fired this round
            if (already_fired.find(n_j) == already_fired.end())
            {
                //have that neuron fire, using the signal
                auto this_neurons_output_tup = this->get_neuron_output(
                        n_j, outgoing, already_fired, forward);

                tmp_tuples.push_back(this_neurons_output_tup);
            }
        }
    }

    tuples.clear();
    tuples = tmp_tuples;
}

Layer* Network::get_input_layer()
{
    return this->layers->front();
}

std::tuple<Signal, std::vector<Neuron *> *>& get_neuron_output(
        Neuron *n_j, const Signal &outgoing, std::set<Neuron *> &already_fired,
        bool forward)
{
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
}


Layer* Network::get_output_layer()
{
    return this->layers->back();
}

bool Network::keep_going(std::vector<std::tuple<Signal, std::vector<Neuron *> *>> &t)
{
    for (unsigned int i = 0; i < t.size(); i++)
    {
        auto tup = t.at(i);
        std::vector<Neuron *> *vec = std::get<1>(tup);
        if (vec->size() > 0)
            return true;
    }
    return false;
}

/*
 * Takes the output vector and populates it in order of output neuron 0 to
 * output neuron layer.size() - 1.
 */
std::vector<Signal>& map_to_output(std::vector<std::tuple<
        Neuron *, Signal>> &output_neurons, std::vector<Signal> &output)
{
    for (unsigned int i = 0; i < this->get_output_layer()->size(); i++)
    {
        //Figure out which neuron in the output_neurons list is
        //the ith one in the output layer and get its signal
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
            throw runtime_error("Could not find neuron.");

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










