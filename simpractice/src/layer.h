/*
 * Header for a Layer ADT.
 * A Layer is essentially a vector of Neurons.
 */

#ifndef __LAYER_H__
#define __LAYER_H__

#include <iostream>

#include "neuron.h"

class Layer
{
public:
    Layer();
    Layer(const Layer &other);
    ~Layer();

    friend std::ostream& operator<<(std::ostream &outstream, const Layer &l);

    Layer& operator=(const Layer &rhs);
    Neuron* operator[](const int index) const;

    void add_neuron(const Neuron &n);

    Neuron* at(int index) const;

    bool contains(const Neuron *n) const;

    /*
     * Gets a copy of the Neuron at the given index.
     */
    Neuron copy_at(int index) const;

    size_t size() const;

private:
    std::vector<Neuron *> neurons;
};



#endif //header guard








