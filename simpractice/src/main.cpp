#include <iostream>
#include <vector>

#include "layer.h"
#include "network.h"


int main(int argv, char **argc)
{
    std::cout << "Hello world" << std::endl;
    //Make a simulator object
    //Feed the simulator a network of neurons
    //A pointer to the input layer
    //A pointer to the output layer
    //An algorithm for updating the neurons after each time step

    //Just for playing around purposes, just hard code a small network
    //Create the layers
    std::vector<Layer> layers;
    for (int i = 0; i < NUM_LAYERS; i++)
    {
        Layer layer;
        for (int j = 0; j < NUM_NEURONS; n++)
        {
            Neuron n;
            layer.add_neuron(n);
        }
        layers.push_back(layer);
    }
    //Create the connections - make it fully connected, feedforward
    for (int i = 0; i < NUM_LAYERS; i++)
    {
        if (i != NUM_LAYERS - 1)
        {
            //We are not the last layer, so add forward connections
            Layer layer_i = layers.at(i);
            for (int j = 0; j < NUM_NEURONS; j++)
            {
                Neuron neuron_j = layer_i.at(j);
                Layer layer_next = layers.at(i + 1);
                //Connect neuron_j to each neuron_l in layer i + 1
                for (int l = 0; l < NUM_NEURONS; l++)
                {
                    Neuron neuron_l = layer_next.at(l);
                    //Synapse from j to l
                    Synapse s(neuron_j, neuron_l);
                }
            }
        }
    }

    //Network network = Network(layers);
    //Simulator simulator = Simulator(network, &input_layer, &output_layer);
}






