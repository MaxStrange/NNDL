/*
 * This is the Signal abstract data type. It represents a value that
 * is passed into or out of a single Neuron (or Synapse).
 * So that it looks like this:
 * Neuron -> Synapse -> Neuron
 * Where the first Neuron sends a Signal and the Synapse receives that Signal,
 * then (potentially) modifies it and sends it to the next Neuron, which takes
 * it as its input along with all of its other Signal inputs.
 */

#ifndef __SIGNAL_H__
#define __SIGNAL_H__

#include "config.h"



class Signal
{
public:
    Signal();
    Signal(fpoint_t val);
    ~Signal();

    fpoint_t get_value() const;
    void set_value(fpoint_t val);
private:
    fpoint_t value;
};






#endif //header guard
