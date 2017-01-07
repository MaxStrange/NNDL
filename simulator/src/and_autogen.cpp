#include <iostream>
#include <vector>
#include <random>
#include "layer.h"
#include "neuron.h"
#include "synapse.h"
#include SYNAPSE_HEADER
#include NEURON_HEADER
#include BIAS_HEADER

static Signal generate_random_weight();

Signal generate_random_weight()
{
    static auto seed = 5;
    std::mt19937 rng(seed++);
    double min = -0.5;
    double max = -0.5;
    std::uniform_real_distribution<double> uni(min, max);

    double rn = uni(rng);

    return Signal(rn);
}

std::vector<Layer *> create_layers(void)
{
    std::cout << "Creating the layers..." << std::endl;

    std::vector<Layer *> layers;

    Layer *layer_0 = new Layer();
    for (unsigned int i = 0; i < 2; i++)
    {
        Neuron n("neuron_0_" + std::to_string(i), true, false);
        layer_0->add_neuron(n);
    }
    layers.push_back(layer_0);

    Layer *layer_1 = new Layer();
    for (unsigned int i = 0; i < 1; i++)
    {
        Neuron n("neuron_1_" + std::to_string(i), false, true);
        layer_1->add_neuron(n);
    }
    layers.push_back(layer_1);

    return layers;
}

std::vector<Synapse *>& connect_layers(const std::vector<Layer *> &layers,
        std::vector<Synapse *> &connections)
{
    std::cout << "Connecting layers..." << std::endl;

    for (unsigned int i = 0; i < layers.size(); i++)
    {
        std::cout << "Connecting layer " << std::to_string(i) << std::endl;
        std::cout << "Number of neurons in this layer: " <<
                std::to_string(layers.at(i)->size()) << std::endl;
        if (i != layers.size() - 1)
        {
            //We are not the last layer, so add forward connections
            Layer *layer_i = layers.at(i);
            for (unsigned int j = 0; j < layer_i->size(); j++)
            {
                Neuron *neuron_j_pointer = layer_i->at(j);
                Layer *layer_next = layers.at(i + 1);
                //Connect neuron_j to each neuron_l in layer i + 1
                for (unsigned int l = 0; l < layer_next->size(); l++)
                {
                    Signal w = generate_random_weight();
                    std::cout << "Weight (" << i << "_" << j << ", " << i + 1
                            << "_" << l << "): " << w << std::endl;
                    Neuron *neuron_l_pointer = layer_next->at(l);
                    //Synapse from j to l
                    Synapse *s = new SYNAPSE(neuron_j_pointer, neuron_l_pointer, w);
                    if (j == 0)
                    {
                        std::cout << "Bias weight (" << i << "_" << j << ", " << i + 1
                                << "_" << l << "): " << w << std::endl;

                        Synapse *b = new BIAS(neuron_j_pointer, neuron_l_pointer, w);
                        connections.push_back(b);
                    }
                    connections.push_back(s);
                }
            }
        }
    }
    return connections;
}