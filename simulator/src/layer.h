/*
 * Header for a Layer ADT.
 * A Layer is essentially a vector of Neurons.
 */

#ifndef __LAYER_H__
#define __LAYER_H__

#include <iostream>

#include "config.h"
#include "neuron.h"
#include "unit_tests.h"

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

    bool get_by_id(Neuron *&to_ret, std::string id) const;

    /*
     * Gets the index of the Neuron in the layer or -1 if not found.
     */
    int get_neuron_index(const Neuron *n) const;

    static UnitTestResult run_tests();

    size_t size() const;

private:
    std::vector<Neuron *> neurons;

    static void test_add_neuron(UnitTestResult &result);
    static void test_contains(UnitTestResult &result);
};



#endif //header guard








