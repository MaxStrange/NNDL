/*
 * A class to hold a synapse - its behavior and its two connections.
 *
 * This class contains constant references to its two neurons - this is so
 * that it can't actually modify the neurons. Really the purpose of this
 * class is two fold. One is that it computes the result of receiving a
 * an incoming signal and returns an outgoing signal, and two is that it
 * also shows that from is connected to to. These behaviors are completely
 * separate by design.
 *
 * The network uses the Synapses to figure out which neurons are connected
 * to which other ones, and then it sends Signals into them from the from
 * neurons and sends them to the to neurons. The Synapse objects don't
 * ask the Neurons for Signals and they don't update the Neurons with
 * new Signals.
 */

#ifndef __SYNAPSE_H__
#define __SYNAPSE_H__

#include <iostream>

#include "neuron.h"

class Synapse
{
public:
    Synapse();
    Synapse(const Neuron *from, const Neuron *to);
    Synapse(const Synapse &other);
    ~Synapse();

    friend std::ostream& operator<<(std::ostream &outstream, const Synapse &s);

    Synapse& operator=(const Synapse &other);

    Signal fire_backward(float t, const Signal &incoming);
    Signal fire_forward(float t, const Signal &incoming);

private:
    const Neuron *from;
    const Neuron *to;
};





#endif //header guard



