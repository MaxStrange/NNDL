/*
 * This is uses Synapses to compute a constant-time lookup map between
 * neurons and their connections, backwards and forwards.
 */
#ifndef __CONNECTION_MAP_H__
#define __CONNECTION_MAP_H__

#include <iostream>
#include <map>
#include <tuple>
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

    void create_const_map(std::vector<Neuron *> &neurons);

    void create_forward_map(std::vector<Neuron *> &neurons,
            std::vector<Synapse *> &connections);

    void create_reverse_map(std::vector<Neuron *> &neurons,
            std::vector<Synapse *> &connections);

    void create_forward_synapses(std::vector<Neuron *> &neurons,
            std::vector<Synapse *> &connections);

    void create_forward_map_synapses(std::vector<Neuron *> &neurons,
            std::vector<Synapse *> &connections);

    void create_reverse_map_synapses(std::vector<Neuron *> &neurons,
            std::vector<Synapse *> &connections);

    /*
     * Gets all the Neurons that the given one synapses FROM.
     * That is, gets all the Neurons that synapse onto this one.
     */
    void get_inputs(const Neuron *n, std::vector<Neuron *> &inputs);

    /*
     * Gets all the Neurons that the given one synapses ONTO.
     */
    void get_outputs(const Neuron *n, std::vector<Neuron *> &outputs);

    void get_output_synapses(const Neuron *n, std::vector<Synapse *> &syns);

    void get_synapse(const Neuron *from, const Neuron *to, Synapse &syn);

    /*
     * Gets whether or not n synapses onto m.
     */
    bool neuron_synapses_onto(const Neuron *n, const Neuron *m);
private:
    //Neuron -> Neurons it is connected TO
    std::map<const Neuron *, std::vector<Neuron *>> forward_map;
    //Neuron -> Neurons that connect TO IT
    std::map<const Neuron *, std::vector<Neuron *>> reverse_map;
    //Neuron a, Neuron b -> Synapse that connects FROM a TO b
    std::map<std::tuple<const Neuron *, const Neuron *>, Synapse *> forward_synapses;
    //Neuron -> All outgoing synapses from it
    std::map<const Neuron *, std::vector<Synapse *>> forward_map_synapses;
    //Neuron -> All incoming synapses going into it
    std::map<const Neuron *, std::vector<Synapse *>> reverse_map_synapses;
    //Neuron to itself, but one is const and the other isn't
    std::map<const Neuron*, Neuron *> const_map;

    std::vector<Synapse *> connections;
};



#endif //header guard







