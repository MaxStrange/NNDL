
#include "neuron.h"
#include "signal.h"

#include "synapse.h"


Synapse::Synapse(const Neuron &from, const Neuron &to)
{
    this->from = from;
    this->to = to;
}

Synapse::~Synapse()
{
}

const Signal& Synapse::fire_backward(float t, const Signal &incoming)
{
    return Signal();
}

const Signal& Synapse::fire_forward(float t, const Signal &incoming)
{
    return Signal();
}


