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
    SimpleNeuron(const std::string &id, bool is_input, bool is_output);
    virtual ~SimpleNeuron();

    friend std::ostream& operator<<(std::ostream &outstream, const SimpleNeuron &n);

    std::string get_id() const;

    Signal fire_backward(uint64_t time,
            const std::vector<Signal> &input_vector);

    Signal fire_forward(uint64_t time,
            const std::vector<Signal> &input_vector);
};


#endif //header guard



