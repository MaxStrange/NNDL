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
    this->connections = connections;
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
    outstream << "Synapses: " << std::endl;
    for (unsigned int i = 0; i < nw.connections->size(); i++)
    {
        Synapse *s = nw.connections->at(i);
        outstream << *s << std::endl;
    }
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
    //TODO
    //For each neuron in the input layer,
    Layer *input_layer = this->layers->at(0);
    for (unsigned int i = 0; i < input_layer->size(); i++)
    {
        Neuron *n_i = input_layer->at(i);
        //get that neuron's output
        Signal n_i_output = n_i->fire_forward(input.at(i));

        //TODO
        //Pair up that neuron's output with each of its output neuron indexes
    }

    //Now you should have a vector of tuples of each neuron's result paired
    //with the neurons that that result is going to

    //For each neuron that the results are going to, get that neuron's output
    //Pair up that neuron's output with each of its output neuron indexes
    //Unless a neuron is in the output layer, if it doesn't have any output
    //neurons to connect to, just discard its result

    //repeat until you have a vector of values that are not paired with
    //neurons - these are your output values

    //It is very important to remember to check each neuron for whether or
    //not we have already fired it in this method. If we have, don't fire
    //it again - this is a recurrency, and it will result in an infinite loop

    return input;
}


















