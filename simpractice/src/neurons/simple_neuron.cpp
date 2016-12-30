#include <iostream>
#include <vector>

#include "signal.h"

#include "simple_neuron.h"



SimpleNeuron::SimpleNeuron()
{
}

SimpleNeuron::SimpleNeuron(const SimpleNeuron &to_copy)
{
    *this = to_copy;
}

SimpleNeuron::SimpleNeuron(const std::string &id)
{
    this->id = id;
}

SimpleNeuron::~SimpleNeuron()
{
}

std::ostream& operator<<(std::ostream &outstream, const SimpleNeuron &n)
{
    outstream << "Neuron " << n.get_id();
    return outstream;
}

SimpleNeuron& SimpleNeuron::operator=(const SimpleNeuron &rhs)
{
    if (this != &rhs)
    {
        this->id = rhs.id;
    }

    return *this;
}

std::string SimpleNeuron::get_id() const
{
    return this->id;
}

Signal SimpleNeuron::fire_backward(uint64_t t, const std::vector<Signal> &input)
{
    //TODO
    return Signal();
}

Signal SimpleNeuron::fire_forward(uint64_t t, const std::vector<Signal> &input)
{
    //TODO
    return Signal();
}











