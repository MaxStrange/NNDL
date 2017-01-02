/*
 * This is how I have chosen to implement Bias nodes in the
 * MNIST example network - they are just synapses that
 * are linked into the network like any others, but there is
 * one for each non-input node, and they ignore their input
 * and simply multiply a constant by their weight instead.
 */

#ifndef __BIAS_SYNAPSE_H__
#define __BIAS_SYNAPSE_H__

#include "simple_synapse.h"

class BiasSynapse
    : public SimpleSynapse
{
public:
    BiasSynapse();
    BiasSynapse(const Neuron *from, const Neuron *to, const Signal &w);
    ~BiasSynapse();

    friend std::ostream& operator<<(std::ostream &outstream, const BiasSynapse &s);

    Signal fire_forward(float t, const Signal &incoming);
};



#endif //header guard





