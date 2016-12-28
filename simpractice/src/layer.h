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
    Neuron* operator[](const int index);

    void add_neuron(const Neuron &n);
    Neuron* at(int index);
    /*
     * Places the given input vector into the neurons and has them execute
     * their fire_backwards functions.
     */
    std::vector<Signal>& back(std::vector<Signal> &input);
    /*
     * Places the given input vector into the neurons and has them execute
     * their fire_forwards functions.
     */
    std::vector<Signal>& input(std::vector<Signal> &input);
    /*
     * Gets a copy of the Neuron at the given index.
     */
    Neuron copy_at(int index) const;

private:
    std::vector<Neuron *> neurons;
};



#endif //header guard








