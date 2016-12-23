#include <vector>

#include "neuron.h"

#include "layer.h"



Layer::Layer()
{
}

Layer::~Layer()
{
#if 0
    for (unsigned int i = 0; i < this->neurons.size(); i++)
    {
        delete this->neurons.at(i);
    }
#endif
}

Neuron& Layer::operator[] (const int index)
{
    return this->neurons[index];
}

void Layer::add_neuron(const Neuron &n)
{
    //This class is responsible for holding on to and doling
    //out references or pointers to neurons. It allocates the heap
    //memory for them and frees that memory as well.
    //Neuron *local_n_pointer = new Neuron(n);
    //this->neurons.push_back(local_n);
}

Neuron& Layer::at(const int index)
{
    return (*this)[index];
}







