/*
 * Header for a Layer ADT.
 * A Layer is essentially a vector of NEURONs.
 */

#ifndef __LAYER_H__
#define __LAYER_H__

#include <iostream>

#include "config.h"
#include "unit_tests.h"

#include NEURON_HEADER

class Layer
{
public:
    Layer();
    Layer(const Layer &other);
    ~Layer();

    friend std::ostream& operator<<(std::ostream &outstream, const Layer &l);

    Layer& operator=(const Layer &rhs);
    NEURON* operator[](const int index) const;

    void add_neuron(const NEURON &n);

    NEURON* at(int index) const;

    bool contains(const NEURON *n) const;

    /*
     * Gets a copy of the NEURON at the given index.
     */
    NEURON copy_at(int index) const;

    bool get_by_id(NEURON *&to_ret, std::string id) const;

    /*
     * Gets the index of the NEURON in the layer or -1 if not found.
     */
    int get_neuron_index(const NEURON *n) const;

    static UnitTestResult run_tests();

    size_t size() const;

private:
    std::vector<NEURON *> neurons;

    static void test_add_neuron(UnitTestResult &result);
    static void test_contains(UnitTestResult &result);
};



#endif //header guard








