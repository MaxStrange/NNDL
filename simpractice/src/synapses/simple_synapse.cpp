#include <iostream>

#include "signal.h"

#include "simple_synapse.h"

#include NEURON_HEADER

SimpleSynapse::SimpleSynapse()
{
}

SimpleSynapse::SimpleSynapse(const NEURON *from, const NEURON *to, const Signal &w)
{
    this->from = from;
    this->to = to;
    this->last_fired = Signal(0);
    this->weight = w;
}

SimpleSynapse::~SimpleSynapse()
{
}

std::ostream& operator<<(std::ostream &outstream, const SimpleSynapse &s)
{
    outstream << "Synapse: " << s.get_weight() << " (";
    outstream << s.get_from()->get_id();
    outstream << ", " << s.get_to()->get_id() << ")";

    return outstream;
}

Signal SimpleSynapse::fire_backward(float t, const Signal &incoming)
{
    Signal delta = incoming - Signal(t);
    Signal new_w = this->weight -
            (Signal(LEARNING_RATE) * delta * this->last_fired);
    this->weight = new_w;

    //TODO Figure out how back prop works exactly
    return incoming;
}

Signal SimpleSynapse::fire_forward(float t, const Signal &incoming)
{
    this->last_fired = incoming * this->weight;
    return this->last_fired;
}








