/*
 * Header for a Layer ADT.
 * A Layer is essentially a vector of Neurons.
 */

#ifndef __LAYER_H__
#define __LAYER_H__

#include "neuron.h"

class Layer
{
public:
    Layer();
    Layer(const Layer &other);
    ~Layer();

    Layer& operator=(const Layer &rhs);
    Neuron* operator[](const int index);

    void add_neuron(const Neuron &n);
    Neuron* at(int index);
    /*
     * Gets a copy of the Neuron at the given index.
     */
    Neuron copy_at(int index) const;

private:
    std::vector<Neuron *> neurons;
};



#endif //header guard








