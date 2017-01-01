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

std::ostream& operator<<(std::ostream &outstream, const Synapse &s)
{
    outstream << "Synapse: " << this->weight << " (" << this->from->get_id();
    outstream << ", " << this->to->get_id() << ")";

    return outstream;
}

Signal Synapse::fire_backward(float t, const Signal &incoming)
{
    Signal delta = incoming - Signal(t);
    Signal new_w = this->weight - (LEARNING_RATE * delta * this->last_fired);
    this->weight = new_w;
}

Signal Synapse::fire_forward(float t, const Signal &incoming)
{
    this->last_fired = incoming * this->weight;
    return this->last_fired;
}
