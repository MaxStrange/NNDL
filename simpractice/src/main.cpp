#include <iostream>
#include <random>
#include <vector>

#include "config.h"
#include "connection_map.h"
#include "headers.h"
#include "layer.h"
#include "network.h"
#include "simulator.h"
#include "synapse.h"
#include "unit_tests.h"

#include SINK_HEADER
#include SOURCE_HEADER


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








