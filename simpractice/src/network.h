/*
 * This is the network ADT - it is class that holds information and functions
 * relating to the Neural Network created by the NNDL file.
 */
#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <iostream>

#include "layer.h"
#include "synapse.h"



class Network
{
public:
    Network(std::vector<Layer *> *layers, std::vector<Synapse *> *connections);
    ~Network();

    friend std::ostream& operator<<(std::ostream &outstream, const Network &nw);

    /*
     * Loads the given vector of Signals (which must of size equal to
     * to the output layer of the network) into the output layer
     * and triggers each Synapse backwards.
     *
     * The result is a vector of Signals coming from the input layer.
     */
    std::vector<Signal> fire_backward(std::vector<Signal> input);

    /*
     * This is the standard mechanism for computing a result from the network.
     * The input must be of size equal to the number of input neurons.
     */
    std::vector<Signal> fire_forward(std::vector<Signal> input);


private:
    std::vector<Layer *> *layers;
    std::vector<Synapse *> *connections;
};



#endif //header guard



