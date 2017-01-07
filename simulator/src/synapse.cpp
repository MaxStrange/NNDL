#include <iostream>

#include "debug.h"
#include "signal.h"

#include "synapse.h"


Synapse::Synapse()
{
}

Synapse::Synapse(const Neuron *from, const Neuron *to, const Signal &w)
{
    this->from = from;
    this->to = to;
    this->last_fired = Signal(0);
    this->weight = w;
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

const Neuron* Synapse::get_from() const
{
    return this->from;
}

const Neuron* Synapse::get_to() const
{
    return this->to;
}

Signal Synapse::get_weight() const
{
    return this->weight;
}

Signal Synapse::fire_backward(uint64_t t, const Signal &incoming)
{
    //TODO
    return Signal(incoming);
}

Signal Synapse::fire_forward(uint64_t t, const Signal &incoming)
{
    //TODO
    return incoming * this->weight;
}


