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
 * neurons and sends them to the to neurons. The Synapses objects don't
 * ask the NEURONs for Signals and they don't update the NEURONs with
 * new Signals.
 */

#ifndef __SYNAPSE_H__
#define __SYNAPSE_H__

#include <iostream>

#include NEURON_HEADER

class Synapse
{
public:
    Synapse();
    Synapse(const NEURON *from, const NEURON *to, const Signal &w);
    virtual ~Synapse();

    friend std::ostream& operator<<(std::ostream &outstream, const Synapse &s);

    const NEURON* get_from() const;
    const NEURON* get_to() const;
    Signal get_weight() const;

    virtual Signal fire_backward(float t, const Signal &incoming);
    virtual Signal fire_forward(float t, const Signal &incoming);

protected:
    const NEURON *from;
    const NEURON *to;
    Signal last_fired;
    Signal last_input;
    Signal weight;
};





#endif //header guard



