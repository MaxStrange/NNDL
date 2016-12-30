#include <iostream>
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

Neuron::Neuron(const std::string &id)
{
    this->id = id;
}

Neuron::~Neuron()
{
}

std::ostream& operator<<(std::ostream &outstream, const Neuron &n)
{
    outstream << "Neuron here";
    return outstream;
}

Neuron& Neuron::operator=(const Neuron &rhs)
{
    if (this != &rhs)
    {
        this->id = rhs.id;
    }

    return *this;
}

std::string Neuron::get_id() const
{
    return this->id;
}

Signal Neuron::fire_backward(uint64_t t, const std::vector<Signal> &input_value)
{
    //TODO
    return Signal();
}

Signal Neuron::fire_forward(uint64_t t, const std::vector<Signal> &input_value)
{
    //TODO
    return Signal();
}







