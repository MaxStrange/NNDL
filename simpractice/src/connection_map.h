/*
 * This is uses Synapses to compute a constant-time lookup map between
 * neurons and their connections, backwards and forwards.
 */
#ifndef __CONNECTION_MAP_H__
#define __CONNECTION_MAP_H__

#include <iostream>
#include <vector>

#include "neuron.h"
#include "synapse.h"


class ConnectionMap
{
public:
    ConnectionMap();
    ConnectionMap(std::vector<Synapse *> &connections,
            std::vector<Neuron *> &neurons);
    ~ConnectionMap();

    friend std::ostream& operator<<(std::ostream &outstream,
            const ConnectionMap &cm);

    /*
     * Gets all the Neurons that the given one synapses FROM.
     * That is, gets all the Neurons that synapse onto this one.
     */
    void get_inputs(const Neuron *n, std::vector<Neuron *> &inputs) const;

    /*
     * Gets all the Neurons that the given one synapses ONTO.
     */
    void get_outputs(const Neuron *n, std::vector<Neuron *> &outputs) const;

    void get_output_synapses(const Neuron *n, std::vector<Synapse *> &syns) const;

    void get_synapse(const Neuron *from, const Neuron *to, Synapse &syn) const;

    /*
     * Gets whether or not n synapses onto m.
     */
    bool neuron_synapses_onto(const Neuron *n, const Neuron *m) const;

private:
    //Neuron -> Neurons it is connected TO
    std::map<const Neuron *, std::vector<Neuron *>> forward_map;
    //Neuron -> Neurons that connect TO IT
    std::map<const Neuron *, std::vector<Neuron *>> reverse_map;
    //Neuron a, Neuron b -> Synapse that connects FROM a TO b
    std::map<std::tuple<const Neuron *, const Neuron *>, Synapse *> forward_synapses;
    //Neuron a, Neuron b -> Synapse that connects TO a FROM b
    std::map<std::tuple<const Neuron *, const Neuron *>, Synapse *> reverse_synapses;
    //Neuron -> All outgoing synapses from it
    std::map<const Neuron *, std::vector<Synapse *>> forward_map_synapses;
    //Neuron -> All incoming synapses going into it
    std::map<const Neuron *, std::vector<Synapse *>> reverse_map_synapses;
};



#endif //header guard







