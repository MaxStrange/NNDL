#include <iostream>

#include "signal.h"

#include "bias_synapse.h"


BiasSynapse::BiasSynapse()
{
}

BiasSynapse::BiasSynapse(const Neuron *from, const Neuron *to, const Signal &w)
{
    this->from = from;
    this->to = to;
    this->last_fired = Signal(0);
    this->weight = w;
}

BiasSynapse::~BiasSynapse()
{
}

std::ostream& operator<<(std::ostream &outstream, const BiasSynapse &s)
{
    outstream << "Bias: " << s.get_weight() << "(x,";
    outstream << s.get_to()->get_id() << ")";

    return outstream;
}

Signal BiasSynapse::fire_forward(uint64_t t, const Signal &incoming)
{
    static const Signal bias(-0.1);
    this->last_input = incoming;
    this->last_fired = bias * this->weight;
    return this->last_fired;
}







