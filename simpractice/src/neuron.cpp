#include <iostream>
#include <vector>

#include "signal.h"

#include "neuron.h"



Neuron::Neuron()
{
}

Neuron::Neuron(const std::string &id, bool is_input, bool is_output)
{
    this->id = id;
    this->is_input = is_input;
    this->is_output = is_output;
}

Neuron::~Neuron()
{
}

std::ostream& operator<<(std::ostream &outstream, const Neuron &n)
{
    outstream << "Neuron " << n.get_id();
    return outstream;
}

std::string Neuron::get_id() const
{
    return this->id;
}

bool Neuron::is_input_neuron() const
{
    return this->is_input;
}

bool Neuron::is_output_neuron() const
{
    return this->is_output;
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







