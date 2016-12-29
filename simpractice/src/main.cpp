#include <iostream>
#include <vector>

#include "config.h"
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
std::vector<Synapse *> connect_layers(std::vector<Layer *> &layers);

int main(int argv, char **argc)
{
    #if RUN_UNIT_TESTS
        //TODO:
        //Run each class's unit tests
        //Only bother making unit tests for the classes that are acting
        //up and for those that are data structures or have complicated
        //algorithms
        UnitTestResult result;

        result = Layer::run_tests();
        result.print();

        result = Network::run_tests();
        result.print();
/*
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
    std::vector<Layer *> layers;
    for (int i = 0; i < NUM_LAYERS; i++)
    {
        Layer *layer = new Layer();
        for (int j = 0; j < NUM_NEURONS; j++)
        {
            Neuron n;
            layer->add_neuron(n);
        }
        layers.push_back(layer);
    }
    return layers;
}

std::vector<Synapse *> connect_layers(std::vector<Layer *> &layers)
{
    std::vector<Synapse *> connections;
    for (int i = 0; i < NUM_LAYERS; i++)
    {
        if (i != NUM_LAYERS - 1)
        {
            //We are not the last layer, so add forward connections
            Layer *layer_i = layers.at(i);
            for (int j = 0; j < NUM_NEURONS; j++)
            {
                Neuron *neuron_j_pointer = layer_i->at(j);
                Layer *layer_next = layers.at(i + 1);
                //Connect neuron_j to each neuron_l in layer i + 1
                for (int l = 0; l < NUM_NEURONS; l++)
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










