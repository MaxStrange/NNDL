#include <vector>

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



