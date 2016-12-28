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

#include <iostream>
#include <vector>

#include "signal.h"


class Neuron
{
public:
    Neuron();
    Neuron(const Neuron& to_copy);
    virtual ~Neuron();

    friend std::ostream& operator<<(std::ostream &outstream, const Neuron &n);

    Neuron& operator=(const Neuron &rhs);

    virtual Signal fire_backward(Signal input_value);
    virtual Signal fire_forward(Signal input_value);

private:
};




#endif //header guard








