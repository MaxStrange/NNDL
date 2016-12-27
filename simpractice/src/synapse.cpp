
#include "neuron.h"
#include "signal.h"

#include "synapse.h"


Synapse::Synapse(const Neuron *from, const Neuron *to)
{
    this->from = from;
    this->to = to;
}

Synapse::Synapse(const Synapse &other)
{
    *this = other;
}

Synapse::~Synapse()
{
}

Synapse& Synapse::operator=(const Synapse &rhs)
{
    if (this != &rhs)
    {
        this->from = rhs.from;
        this->to = rhs.to;
    }

    return *this;
}

Signal Synapse::fire_backward(float t, const Signal &incoming)
{
    //TODO
    return Signal();
}

Signal Synapse::fire_forward(float t, const Signal &incoming)
{
    //TODO
    return Signal();
}


