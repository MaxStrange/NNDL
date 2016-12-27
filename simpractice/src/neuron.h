/*
 * Neuron ADT.
 *
 * The Neuron is the mathematical unit of the neural network. It contains
 * two functions that must be implemented by the user: the fire_forward
 * and the fire_backward functions.
 *
 * Generally, the fire_forward function is used for calculating a value,
 * whereas the fire_backward function is used for training the Neuron.
 *
 * TODO:
 * Ultimately, this class should be made into an abstract base class
 * for all the different types of Neurons.
 */

#ifndef __NEURON_H__
#define __NEURON_H__

#include <vector>

#include "signal.h"


class Neuron
{
public:
    Neuron();
    Neuron(const Neuron& to_copy);
    virtual ~Neuron();

    Neuron& operator=(const Neuron &rhs);

    virtual Signal fire_backward(std::vector<Signal> input_vector);
    virtual Signal fire_forward(std::vector<Signal> input_vector);

private:
};




#endif //header guard








