#include <iostream>
#include <vector>

#include "debug.h"
#include "neuron.h"

#include "layer.h"



Layer::Layer()
{
}

Layer::Layer(const Layer &other)
{
    *this = other;
}

Layer::~Layer()
{
    for (unsigned int i = 0; i < this->neurons.size(); i++)
    {
        delete this->neurons.at(i);
    }
}

std::ostream& operator<<(std::ostream &outstream, const Layer &l)
{
    outstream << debug_print_header("Layer") << std::endl;
    outstream << "Neurons: " << std::endl;
    for (unsigned int i = 0; i < l.neurons.size(); i++)
    {
        Neuron *n = l.neurons.at(i);
        outstream << *n << std::endl;
    }
    outstream << debug_print_closing("Layer") << std::endl;

    return outstream;
}

Layer& Layer::operator=(const Layer &rhs)
{
    if (this != &rhs)
    {
        for (unsigned int i = 0; i < rhs.neurons.size(); i++)
        {
            Neuron n = rhs.copy_at(i);
            this->add_neuron(n);
        }
    }

    return *this;
}

Neuron* Layer::operator[](const int index)
{
    Neuron *n = this->neurons[index];
    return n;
}

void Layer::add_neuron(const Neuron &n)
{
    //This class is responsible for holding on to and doling
    //out references or pointers to neurons. It allocates the heap
    //memory for them and frees that memory as well.
    Neuron *heap_n_pointer = new Neuron(n);
    this->neurons.push_back(heap_n_pointer);
}

Neuron* Layer::at(const int index)
{
    return (*this)[index];
}

Neuron Layer::copy_at(int index) const
{
    Neuron copy(*this->neurons[index]);
    return copy;
}







