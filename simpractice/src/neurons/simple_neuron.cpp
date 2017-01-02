#include <cmath>
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
    if (this->is_output_neuron())
    {
        //input is the value that this->last_fired should have been
        //and input is a single value
        assert((input.size() == 1));
        Signal label = input.at(0);
        Signal del_output = (this->last_fired - label) *
                this->last_fired * (Signal(1) - this->last_fired);
        return del_output;
    }
    else
    {
        Signal sum;
        for (unsigned int i = 0; i < input.size(); i++)
        {
            sum += input.at(i);
        }
        Signal del_hidden = this->last_fired *
                (Signal(1) - this->last_fired) * sum;
        return del_hidden;
    }
}

Signal SimpleNeuron::fire_forward(uint64_t t, const std::vector<Signal> &input)
{
    Signal sum;
    for (unsigned int i = 0; i < input.size(); i++)
    {
        Signal s = input.at(i);
        sum += s;
    }

    Signal exponent = -Signal(BETA) * sum;
    Signal denom = Signal(1) + Signal(exp((fpoint_t)exponent));
    Signal activation = Signal(1) / denom;

    this->last_fired = activation;
    return activation;
}













