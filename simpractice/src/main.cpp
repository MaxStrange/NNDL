#include <iostream>
#include <vector>

#include "layer.h"
#include "network.h"
#include "neuron.h"
#include "simulator.h"
#include "sink.h"
#include "source.h"
#include "synapse.h"

std::vector<Layer> create_layers(void);
std::vector<Synapse> connect_layers(std::vector<Layer>& layers);

int main(int argv, char **argc)
{
    std::cout << "Hello world" << std::endl;
    //Make a simulator object
    //Feed the simulator a network of neurons
    //A pointer to the input layer
    //A pointer to the output layer
    //An algorithm for updating the neurons after each time step

    //Just for playing around purposes, just hard code a small network
    std::vector<Layer> layers = create_layers();
    std::vector<Synapse> connections = connect_layers(layers);
    Network network(layers, connections);
    Source source;
    Sink sink;
    Simulator simulator(network, source, sink);

    simulator.run();
}

std::vector<Layer> create_layers(void)
{
    std::vector<Layer> layers;
    for (int i = 0; i < NUM_LAYERS; i++)
    {
        Layer layer;
        for (int j = 0; j < NUM_NEURONS; j++)
        {
            Neuron n;
            layer.add_neuron(n);
        }
        layers.push_back(layer);
    }
    return layers;
}

std::vector<Synapse> connect_layers(std::vector<Layer>& layers)
{
    std::vector<Synapse> connections;
    for (int i = 0; i < NUM_LAYERS; i++)
    {
        if (i != NUM_LAYERS - 1)
        {
            //We are not the last layer, so add forward connections
            Layer layer_i = layers.at(i);
            for (int j = 0; j < NUM_NEURONS; j++)
            {
                //TODO: must make sure that the neurons I put into Synapses are actually
                //references or pointers to the same neurons that are in the layers, which
                //themselves should probably be pointers or references to neurons created
                //in the main method or elsewhere on the heap, so that there are no copies
                //floating about
                Neuron neuron_j = layer_i.at(j);
                Layer layer_next = layers.at(i + 1);
                //Connect neuron_j to each neuron_l in layer i + 1
                for (int l = 0; l < NUM_NEURONS; l++)
                {
                    Neuron neuron_l = layer_next.at(l);
                    //Synapse from j to l
                    Synapse s(neuron_j, neuron_l);
                    connections.push_back(s);
                }
            }
        }
    }
    return connections;
}










