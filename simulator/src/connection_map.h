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
#include "unit_tests.h"


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
     * Gets all the Neurons that synapse onto this one.
     */
    void get_inputs(const Neuron *n, std::vector<Neuron *> &inputs);

    /*
     * Gets all the Synapses that the given Neuron has coming into it.
     */
    void get_input_synapses(const Neuron *n, std::vector<Synapse *> &syns);

    /*
     * Gets all the Neurons that the given one synapses ONTO.
     */
    void get_outputs(const Neuron *n, std::vector<Neuron *> &outputs);

    /*
     * Gets all the Synapses that the given Neuron has leaving it.
     */
    void get_output_synapses(const Neuron *n, std::vector<Synapse *> &syns);

    void get_synapses(const Neuron *from, const Neuron *to, std::vector<Synapse *> &syn);

    void get_weights(std::vector<Signal> &weights) const;

    /*
     * Gets whether or not n synapses onto m.
     */
    bool neuron_synapses_onto(const Neuron *n, const Neuron *m);

    static UnitTestResult run_tests();

private:
    //Neuron -> Neurons it is connected TO
    std::map<const Neuron *, std::vector<Neuron *>> forward_map;
    //Neuron -> Neurons that connect TO IT
    std::map<const Neuron *, std::vector<Neuron *>> reverse_map;
    //Neuron a, Neuron b -> Synapses that connects FROM a TO b
    std::map<std::tuple<const Neuron *, const Neuron *>, std::vector<Synapse *>> forward_synapses;
    //Neuron -> All outgoing synapses from it
    std::map<const Neuron *, std::vector<Synapse *>> forward_map_synapses;
    //Neuron -> All incoming synapses going into it
    std::map<const Neuron *, std::vector<Synapse *>> reverse_map_synapses;
    //Neuron to itself, but one is const and the other isn't
    std::map<const Neuron*, Neuron *> const_map;

    std::vector<Synapse *> connections;
    std::vector<Neuron *> neurons;

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
    static void test_forward_map(UnitTestResult &result);
    static void test_reverse_map(UnitTestResult &result);
    static void test_forward_synapses(UnitTestResult &result);
    static void test_forward_map_synapses(UnitTestResult &result);
    static void test_reverse_map_synapses(UnitTestResult &result);
    static void test_const_map(UnitTestResult &result);
    static void create_test_connection_map(ConnectionMap &cm);
};



#endif //header guard







