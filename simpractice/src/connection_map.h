/*
 * This is uses SYNAPSEs to compute a constant-time lookup map between
 * neurons and their connections, backwards and forwards.
 */
#ifndef __CONNECTION_MAP_H__
#define __CONNECTION_MAP_H__

#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#include "neuron.h"
#include "unit_tests.h"

#include SYNAPSE_HEADER


class ConnectionMap
{
public:
    ConnectionMap();
    ConnectionMap(std::vector<SYNAPSE *> &connections,
            std::vector<NEURON *> &neurons);
    ~ConnectionMap();

    friend std::ostream& operator<<(std::ostream &outstream,
            const ConnectionMap &cm);

    /*
     * Gets all the NEURONs that synapse onto this one.
     */
    void get_inputs(const NEURON *n, std::vector<NEURON *> &inputs);

    /*
     * Gets all the SYNAPSEs that the given NEURON has coming into it.
     */
    void get_input_synapses(const NEURON *n, std::vector<SYNAPSE *> &syns);

    /*
     * Gets all the NEURONs that the given one synapses ONTO.
     */
    void get_outputs(const NEURON *n, std::vector<NEURON *> &outputs);

    /*
     * Gets all the SYNAPSEs that the given NEURON has leaving it.
     */
    void get_output_synapses(const NEURON *n, std::vector<SYNAPSE *> &syns);

    void get_synapse(const NEURON *from, const NEURON *to, SYNAPSE *&syn);

    /*
     * Gets whether or not n synapses onto m.
     */
    bool neuron_synapses_onto(const NEURON *n, const NEURON *m);

    static UnitTestResult run_tests();

private:
    //NEURON -> NEURONs it is connected TO
    std::map<const NEURON *, std::vector<NEURON *>> forward_map;
    //NEURON -> NEURONs that connect TO IT
    std::map<const NEURON *, std::vector<NEURON *>> reverse_map;
    //NEURON a, NEURON b -> SYNAPSE that connects FROM a TO b
    std::map<std::tuple<const NEURON *, const NEURON *>, SYNAPSE *> forward_synapses;
    //NEURON -> All outgoing synapses from it
    std::map<const NEURON *, std::vector<SYNAPSE *>> forward_map_synapses;
    //NEURON -> All incoming synapses going into it
    std::map<const NEURON *, std::vector<SYNAPSE *>> reverse_map_synapses;
    //NEURON to itself, but one is const and the other isn't
    std::map<const NEURON*, NEURON *> const_map;

    std::vector<SYNAPSE *> connections;
    std::vector<NEURON *> neurons;

    void create_const_map(std::vector<NEURON *> &neurons);
    void create_forward_map(std::vector<NEURON *> &neurons,
            std::vector<SYNAPSE *> &connections);
    void create_reverse_map(std::vector<NEURON *> &neurons,
            std::vector<SYNAPSE *> &connections);
    void create_forward_synapses(std::vector<NEURON *> &neurons,
            std::vector<SYNAPSE *> &connections);
    void create_forward_map_synapses(std::vector<NEURON *> &neurons,
            std::vector<SYNAPSE *> &connections);
    void create_reverse_map_synapses(std::vector<NEURON *> &neurons,
            std::vector<SYNAPSE *> &connections);
    static void test_forward_map(UnitTestResult &result);
    static void test_reverse_map(UnitTestResult &result);
    static void test_forward_synapses(UnitTestResult &result);
    static void test_forward_map_synapses(UnitTestResult &result);
    static void test_reverse_map_synapses(UnitTestResult &result);
    static void test_const_map(UnitTestResult &result);
    static void create_test_connection_map(ConnectionMap &cm);
};



#endif //header guard







