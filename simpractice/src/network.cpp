#include <iostream>
#include <vector>

#include "debug.h"
#include "layer.h"
#include "signal.h"
#include "synapse.h"

#include "network.h"


Network::Network(std::vector<Layer> *layers, std::vector<Synapse> *connections)
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
        Layer l = nw.layers->at(i);
        outstream << l << std::endl;
    }
    outstream << "Synapses: " << std::endl;
    for (unsigned int i = 0; i < nw.connections->size(); i++)
    {
        Synapse s = nw.connections->at(i);
        outstream << s << std::endl;
    }
    outstream << debug_print_closing("Network") << std::endl;

    return outstream;
}

std::vector<Signal> fire_backward(std::vector<Signal> input)
{
    //TODO
    return std::vector<Signal>();
}

std::vector<Signal> fire_forward(std::vector<Signal> input)
{
    //TODO
    return std::vector<Signal>();
}



