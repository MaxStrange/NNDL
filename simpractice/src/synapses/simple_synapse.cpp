#include <iostream>

#include "signal.h"

#include "simple_synapse.h"


SimpleSynapse::SimpleSynapse()
{
}

SimpleSynapse::SimpleSynapse(const Neuron *from, const Neuron *to, const Signal &w)
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

Signal SimpleSynapse::fire_backward(uint64_t t, const Signal &incoming)
{
    //Only adjust weights after each batch
    if (t % 10 == 0)
    {
        static const Signal learning_rate(0.3);
        this->weight -= learning_rate * incoming * this->last_input;
    }
    return incoming * this->weight;
}

Signal SimpleSynapse::fire_forward(uint64_t t, const Signal &incoming)
{
    this->last_input = incoming;
    this->last_fired = incoming * this->weight;
    return this->last_fired;
}








