#include <iostream>
#include <random>
#include <vector>

#include "config.h"
#include "connection_map.h"
#include "layer.h"
#include "network.h"
#include "simulator.h"
#include "synapse.h"
#include "unit_tests.h"

#include SINK_HEADER
#include SOURCE_HEADER
#include BIAS_HEADER
#include SYNAPSE_HEADER


std::vector<Layer *> create_layers(void);
std::vector<Synapse *>& connect_layers(const std::vector<Layer *> &layers,
        std::vector<Synapse *> &connections);
Signal generate_random_weight();

int main(int argv, char **argc)
{
    #if RUN_UNIT_TESTS
        //Run each class's unit tests
        //Only bother making unit tests for the classes that are acting
        //up and for those that are data structures or have complicated
        //algorithms
        UnitTestResult result;

        result = Layer::run_tests();
        result.print();

        result = ConnectionMap::run_tests();
        result.print();

        result = Network::run_tests();
        result.print();
/*
        //TODO: Implement any or all of these if you want

        //result = Neuron::run_tests();
        //result.print();

        result = Simulator::run_tests();
        result.print();

        //result = SINK::run_tests();
        //result.print();

        result = SOURCE::run_tests();
        result.print();

        //result = Synapse::run_tests();
        //result.print();
*/
    #else
        std::cout << "Initializing..." << std::endl;

        std::vector<Layer *> layers = create_layers();
        std::vector<Synapse *> connections;
        connections = connect_layers(layers, connections);
        std::cout << "Creating network..." << std::endl;
        Network network(&layers, &connections);
        SOURCE source;
        SINK sink;
        Simulator simulator(&network, &source, &sink);

        simulator.run();

        std::cout << "Simulator has been run!" << std::endl;
    #endif
}

std::vector<Layer *> create_layers(void)
{
    std::cout << "Creating the layers..." << std::endl;

    std::vector<Layer *> layers;
    Layer *input = new Layer();
#if ! AND_EXAMPLE
    Layer *hidden = new Layer();
#endif
    Layer *output = new Layer();
    for (unsigned int i = 0; i < NUM_NEURONS_INPUT; i++)
    {
        Neuron n("in_" + std::to_string(i), true, false);
        input->add_neuron(n);
    }
#if ! AND_EXAMPLE
    for (unsigned int i = 0; i < NUM_NEURONS_HIDDEN; i++)
    {
        Neuron n("h_" + std::to_string(i), false, false);
        hidden->add_neuron(n);
    }
#endif
    for (unsigned int i = 0; i < NUM_NEURONS_OUTPUT; i++)
    {
        Neuron n("out_" + std::to_string(i), false, true);
        output->add_neuron(n);
    }

    layers.push_back(input);
#if ! AND_EXAMPLE
    layers.push_back(hidden);
#endif
    layers.push_back(output);

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

Signal generate_random_weight()
{
    static auto seed = 5;
    std::mt19937 rng(seed++);
    double min = -0.5;
    double max = 0.5;
    std::uniform_real_distribution<double> uni(min, max);

    double rn = uni(rng);

    return Signal(rn);
}










