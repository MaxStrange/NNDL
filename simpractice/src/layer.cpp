#include <iostream>
#include <vector>

#include "debug.h"
#include "neuron.h"
#include "unit_tests.h"

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

Neuron* Layer::operator[](const int index) const
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

Neuron* Layer::at(int index) const
{
    return (*this)[index];
}

bool Layer::contains(const Neuron *n) const
{
    for (unsigned int i = 0; i < this->size(); i++)
    {
        const Neuron *m = this->at(i);
        if (n == m)
            return true;
    }

    return false;
}

Neuron Layer::copy_at(int index) const
{
    Neuron copy(*this->neurons[index]);
    return copy;
}

UnitTestResult Layer::run_tests()
{
    UnitTestResult result;
    Layer::test_add_neuron(result);
    Layer::test_contains(result);

    return result;
}

size_t Layer::size() const
{
    return this->neurons.size();
}

void Layer::test_add_neuron(UnitTestResult &result)
{
    std::string class_name = "Layer";
    std::string test_name = "add_neuron";

    Layer test_layer;
    size_t sz = test_layer.size();
    result.assert(sz == 0, class_name, test_name, "Size not equal to zero.");

    Neuron n;
    test_layer.add_neuron(n);
    sz = test_layer.size();
    result.assert(sz == 1, class_name, test_name, "Size not equal to one.");
}

void Layer::test_contains(UnitTestResult &result)
{
    std::string class_name = "Layer";
    std::string test_name = "contains";

    Layer test_layer;
    Neuron n;
    test_layer.add_neuron(n);

    Neuron m;
    test_layer.add_neuron(m);

    Neuron *np = test_layer.at(0);
    Neuron *mp = test_layer.at(1);

    result.assert(test_layer.contains(np), class_name, test_name,
            "Layer does not contain neuron n");
    result.assert(test_layer.contains(mp), class_name, test_name,
            "Layer does not contain neuron m");
    Neuron o;
    result.assert(! test_layer.contains(&o), class_name, test_name,
            "Layer contains neuron o, and it shouldn't.");
}
























