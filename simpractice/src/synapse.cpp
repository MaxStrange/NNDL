#include <iostream>

#include "debug.h"
#include "neuron.h"
#include "signal.h"

#include "synapse.h"


Synapse::Synapse()
{
}

Synapse::Synapse(const NEURON *from, const NEURON *to)
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

std::ostream& operator<<(std::ostream &outstream, const Synapse &s)
{
    outstream << debug_print_header("Synapse") << std::endl;
    outstream << "From: " << std::endl;
    outstream << *(s.from) << std::endl;
    outstream << "To: " << std::endl;
    outstream << *(s.to) << std::endl;
    outstream << debug_print_closing("Synapse") << std::endl;

    return outstream;
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

const NEURON* Synapse::get_from() const
{
    return this->from;
}

const NEURON* Synapse::get_to() const
{
    return this->to;
}

Signal Synapse::fire_backward(float t, const Signal &incoming)
{
    //TODO
    return Signal(incoming);
}

Signal Synapse::fire_forward(float t, const Signal &incoming)
{
    //TODO
    return Signal(incoming);
}

