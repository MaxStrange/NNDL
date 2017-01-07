/*
 * Neuron ADT.
 *
 * The Neuron is the mathematical unit of the neural network. It contains
 * two functions that must be implemented by the user: the fire_forward
 * and the fire_backward functions.
 *
 * Generally, the fire_forward function is used for calculating a value,
 * whereas the fire_backward function is used for training the Neuron.
 *
 * TODO:
 * Ultimately, this class should be made into an abstract base class
 * for all the different types of Neuron.
 */

#ifndef __Neuron_H__
#define __Neuron_H__

#include <iostream>
#include <vector>

#include "signal.h"


class Neuron
{
public:
    Neuron();
    Neuron(const std::string &id, bool is_input, bool is_output);
    virtual ~Neuron();

    friend std::ostream& operator<<(std::ostream &outstream, const Neuron &n);

    Neuron& operator=(const Neuron &rhs);

    virtual std::string get_id() const;
    virtual bool is_input_neuron() const;
    virtual bool is_output_neuron() const;

    virtual Signal fire_backward(uint64_t time,
            const std::vector<Signal> &input_vector) {return Signal();};
    virtual Signal fire_forward(uint64_t time,
            const std::vector<Signal> &input_vector) {return Signal();};

protected:
    std::string id;
    bool is_input;
    bool is_output;
    Signal last_fired;
};




#endif //header guard








