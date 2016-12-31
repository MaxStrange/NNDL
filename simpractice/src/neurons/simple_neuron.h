/*
 */
#ifndef __SIMPLE_NEURON_H__
#define __SIMPLE_NEURON_H__

#include "neuron.h"

class SimpleNeuron :
    public Neuron
{
public:
    SimpleNeuron();
    SimpleNeuron(const SimpleNeuron &to_copy);
    SimpleNeuron(const std::string &id);
    virtual ~SimpleNeuron();

    friend std::ostream& operator<<(std::ostream &outstream, const SimpleNeuron &n);

    SimpleNeuron& operator=(const SimpleNeuron &rhs);

    std::string get_id() const;

    Signal fire_backward(uint64_t time,
            const std::vector<Signal> &input_vector);

    Signal fire_forward(uint64_t time,
            const std::vector<Signal> &input_vector);
};


#endif //header guard



