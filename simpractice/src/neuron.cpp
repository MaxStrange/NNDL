#include <vector>

#include "signal.h"

#include "neuron.h"



Neuron::Neuron()
{
}

Neuron::Neuron(const Neuron& to_copy)
{
    *this = to_copy;
}

Neuron::~Neuron()
{
}

Neuron& Neuron::operator=(const Neuron &rhs)
{
    if (this != &rhs)
    {
    }

    return *this;
}

Signal Neuron::fire_backward(std::vector<Signal> input_vector)
{
    //TODO
    return Signal();
}

Signal Neuron::fire_forward(std::vector<Signal> input_vector)
{
    //TODO
    return Signal();
}







