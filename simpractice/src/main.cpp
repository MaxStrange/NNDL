#include <iostream>
#include <vector>

#include "config.h"
#include "connection_map.h"
#include "layer.h"
#include "network.h"
#include "neuron.h"
#include "simulator.h"
#include "sink.h"
#include "source.h"
#include "synapse.h"
#include "unit_tests.h"

#include SOURCE_HEADER


std::vector<Layer *> create_layers(void);
std::vector<Synapse *> connect_layers(const std::vector<Layer *> &layers);

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
        std::vector<Synapse *> connections = connect_layers(layers);
        Network network(&layers, &connections);
        //std::cout << "Created network: " << network << std::endl;
        SOURCE source;
        Sink sink;
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
        Neuron n("in_" + std::to_string(i));
        input->add_neuron(n);
    }
    for (unsigned int i = 0; i < NUM_NEURONS_HIDDEN; i++)
    {
        Neuron n("h_" + std::to_string(i));
        hidden->add_neuron(n);
    }
    for (unsigned int i = 0; i < NUM_NEURONS_OUTPUT; i++)
    {
        Neuron n("out_" + std::to_string(i));
        hidden->add_neuron(n);
    }

    layers.push_back(input);
    layers.push_back(hidden);
    layers.push_back(output);

    return layers;
}

std::vector<Synapse *> connect_layers(const std::vector<Layer *> &layers)
{
    std::cout << "Connecting layers..." << std::endl;

    std::vector<Synapse *> connections;
    for (int i = 0; i < layers.size(); i++)
    {
        if (i != layers.size() - 1)
        {
            //We are not the last layer, so add forward connections
            Layer *layer_i = layers.at(i);
            for (int j = 0; j < layer_i->size(); j++)
            {
                Neuron *neuron_j_pointer = layer_i->at(j);
                Layer *layer_next = layers.at(i + 1);
                //Connect neuron_j to each neuron_l in layer i + 1
                for (int l = 0; l < layer_next->size(); l++)
                {
                    Neuron *neuron_l_pointer = layer_next->at(l);
                    //Synapse from j to l
                    Synapse *s = new Synapse(neuron_j_pointer, neuron_l_pointer);
                    connections.push_back(s);
                }
            }
        }
    }
    return connections;
}










