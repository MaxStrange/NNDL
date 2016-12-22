/*
 * A class to hold a synapse - its behavior and its two connections.
 */

#ifndef __SYNAPSE_H__
#define __SYNAPSE_H__

class Synapse
{
public:
    Synapse(const Neuron &from, const Neuron &to);
    ~Synapse();

    const Signal& fire(float t, const Signal& incoming);

private:
    const Neuron &from;
    const Neuron &to;
};





#endif //header guard



