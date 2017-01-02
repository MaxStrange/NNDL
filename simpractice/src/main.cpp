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

#include NEURON_HEADER
#include SINK_HEADER
#include SOURCE_HEADER


std::vector<Layer *> create_layers(void);
std::vector<SYNAPSE *>& connect_layers(const std::vector<Layer *> &layers,
        std::vector<SYNAPSE *> &connections);
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

        //result = NEURON::run_tests();
        //result.print();

        result = Simulator::run_tests();
        result.print();

        //result = SINK::run_tests();
        //result.print();

        result = SOURCE::run_tests();
        result.print();

        //result = SYNAPSE::run_tests();
        //result.print();
*/
    #else
        std::cout << "Initializing..." << std::endl;

        std::vector<Layer *> layers = create_layers();
        std::vector<SYNAPSE *> connections;
        connections = connect_layers(layers, connections);
        std::cout << "Creating network..." << std::endl;
        Network network(&layers, &connections);
        //std::cout << "Created network: " << network << std::endl;
        SOURCE source;
        SINK sink;
        Simulator simulator(&network, &source, &sink);
        //std::cout << "Created simulator: " << simulator << std::endl;

        simulator.run();

        std::cout << "Simulator has been run!" << std::endl;
    #endif
}

std::vector<Layer *> create_layers(void)
{
    std::cout << "Creating the layers..." << std::endl;

    std::vector<Layer *> layers;
    Layer *input = new Layer();
    Layer *hidden = new Layer();
    Layer *output = new Layer();
    for (unsigned int i = 0; i < NUM_NEURONS_INPUT; i++)
    {
        NEURON n("in_" + std::to_string(i));
        input->add_neuron(n);
    }
    for (unsigned int i = 0; i < NUM_NEURONS_HIDDEN; i++)
    {
        NEURON n("h_" + std::to_string(i));
        hidden->add_neuron(n);
    }
    for (unsigned int i = 0; i < NUM_NEURONS_OUTPUT; i++)
    {
        NEURON n("out_" + std::to_string(i));
        output->add_neuron(n);
    }

    layers.push_back(input);
    layers.push_back(hidden);
    layers.push_back(output);

    return layers;
}

std::vector<SYNAPSE *>& connect_layers(const std::vector<Layer *> &layers,
        std::vector<SYNAPSE *> &connections)
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
                NEURON *neuron_j_pointer = layer_i->at(j);
                Layer *layer_next = layers.at(i + 1);
                //Connect neuron_j to each neuron_l in layer i + 1
                for (unsigned int l = 0; l < layer_next->size(); l++)
                {
                    Signal w = generate_random_weight();
                    NEURON *neuron_l_pointer = layer_next->at(l);
                    //SYNAPSE from j to l
                    SYNAPSE *s = new SYNAPSE(neuron_j_pointer, neuron_l_pointer, w);
                    connections.push_back(s);
                }
            }
        }
    }
    return connections;
}

Signal generate_random_weight()
{
    //generate a weight between -1 and +1
    static std::random_device rand;
    std::mt19937 rng(rand());
    double min = -1.0f;
    double max = 1.0f;
    std::uniform_real_distribution<double> uni(min, max);

    double rn = uni(rng);

    return Signal(rn);
}










