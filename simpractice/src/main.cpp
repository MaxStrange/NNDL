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
    std::cout << "Initializing..." << std::endl;

    //Just for playing around purposes, just hard code a small network
    std::vector<Layer> layers = create_layers();
    std::vector<Synapse> connections = connect_layers(layers);
    Network network(&layers, &connections);
    //std::cout << "Created network: " << network << std::endl;
    Source source;
    Sink sink;
    Simulator simulator(&network, &source, &sink);
    //std::cout << "Created simulator: " << simulator << std::endl;

    simulator.run();

    std::cout << "Simulator has been run!" << std::endl;
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
                Neuron *neuron_j_pointer = layer_i.at(j);
                Layer layer_next = layers.at(i + 1);
                //Connect neuron_j to each neuron_l in layer i + 1
                for (int l = 0; l < NUM_NEURONS; l++)
                {
                    Neuron *neuron_l_pointer = layer_next.at(l);
                    //Synapse from j to l
                    Synapse s(neuron_j_pointer, neuron_l_pointer);
                    connections.push_back(s);
                }
            }
        }
    }
    return connections;
}










