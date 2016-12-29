#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#include "debug.h"
#include "neuron.h"
#include "synapse.h"

#include "connection_map.h"


ConnectionMap::ConnectionMap()
{
}

ConnectionMap::ConnectionMap(std::vector<Synapse *> &connections,
        std::vector<Neuron *> &neurons)
{
    this->connections = connections;
    this->create_const_map(neurons);
    this->create_forward_synapses(neurons, connections);
    this->create_forward_map_synapses(neurons, connections);
    this->create_reverse_map_synapses(neurons, connections);
    //These two rely on the other ones, so they come last
    this->create_forward_map(neurons, connections);
    this->create_reverse_map(neurons, connections);
}

ConnectionMap::~ConnectionMap()
{
}

std::ostream& operator<<(std::ostream &outstream, const ConnectionMap &cm)
{
    outstream << debug_print_header("ConnectionMap") << std::endl;
    outstream << debug_print_closing("ConnectionMap") << std::endl;

    return outstream;
}

void ConnectionMap::create_const_map(std::vector<Neuron *> &neurons)
{
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        Neuron *n = neurons.at(i);
        this->const_map[n] = n;
    }
}

void ConnectionMap::create_forward_map(std::vector<Neuron *> &neurons,
        std::vector<Synapse *> &connections)
{
    //Neuron -> Neurons it is connected TO
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        Neuron *a = neurons.at(i);
        std::vector<Synapse *> synapses = this->forward_map_synapses[a];
        std::vector<Neuron *> neurons_from_a;
        for (unsigned int j = 0; j < synapses.size(); j++)
        {
            Synapse *s = synapses.at(j);
            const Neuron *to = s->get_to();
            neurons_from_a.push_back(this->const_map[to]);
        }
        this->forward_map[a] = neurons_from_a;
    }
}

void ConnectionMap::create_reverse_map(std::vector<Neuron *> &neurons,
        std::vector<Synapse *> &connections)
{
    //Neuron -> Neurons that connect TO IT
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        Neuron *a = neurons.at(i);
        std::vector<Synapse *> synapses = this->reverse_map_synapses[a];
        std::vector<Neuron *> neurons_to_a;
        for (unsigned int j = 0; j < synapses.size(); j++)
        {
            Synapse *s = synapses.at(j);
            const Neuron *from = s->get_from();
            neurons_to_a.push_back(this->const_map[from]);
        }
        this->reverse_map[a] = neurons_to_a;
    }
}

void ConnectionMap::create_forward_synapses(std::vector<Neuron *> &neurons,
        std::vector<Synapse *> &connections)
{
    //Neuron a, Neuron b -> Synapse that connects FROM a TO b
    for (unsigned int i = 0; i < connections.size(); i++)
    {
        Synapse *s = connections.at(i);
        const Neuron *a = s->get_from();
        const Neuron *b = s->get_to();
        std::tuple<const Neuron *, const Neuron *> ab = std::make_tuple(a, b);
        this->forward_synapses[ab] = s;
    }
}

void ConnectionMap::create_forward_map_synapses(std::vector<Neuron *> &neurons,
        std::vector<Synapse *> &connections)
{
    //Neuron -> All outgoing Synapses from it
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        Neuron *n = neurons.at(i);
        std::vector<Synapse *> ns_synapses;
        for (unsigned int j = 0; j < connections.size(); j++)
        {
            Synapse *s = connections.at(j);
            const Neuron *from = s->get_from();
            const Neuron *to = s->get_to();

            if (n == from)
                ns_synapses.push_back(s);
        }
        this->forward_map_synapses[n] = ns_synapses;
    }
}

void ConnectionMap::create_reverse_map_synapses(std::vector<Neuron *> &neurons,
        std::vector<Synapse *> &connections)
{
    //Neuron -> All incoming Synapses going into it
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        Neuron *n = neurons.at(i);
        std::vector<Synapse *> ns_synapses;
        for (unsigned int j = 0; j < connections.size(); j++)
        {
            Synapse *s = connections.at(j);
            const Neuron *from = s->get_from();
            const Neuron *to = s->get_to();

            if (n == to)
                ns_synapses.push_back(s);
        }
        this->forward_map_synapses[n] = ns_synapses;
    }
}

void ConnectionMap::get_inputs(const Neuron *n,
        std::vector<Neuron *> &inputs)
{
    inputs = this->reverse_map[n];
}

void ConnectionMap::get_outputs(const Neuron *n,
        std::vector<Neuron *> &outputs)
{
    outputs = this->forward_map[n];
}

void ConnectionMap::get_output_synapses(const Neuron *n,
        std::vector<Synapse *> &syns)
{
    syns = this->forward_map_synapses[n];
}

void ConnectionMap::get_synapse(const Neuron *from, const Neuron *to,
        Synapse &syn)
{
    auto tup = std::make_tuple(from, to);
    syn = *this->forward_synapses[tup];
}

bool ConnectionMap::neuron_synapses_onto(const Neuron *n, const Neuron *m)
{
    auto tup = std::make_tuple(n, m);
    return (this->forward_synapses.find(tup) != this->forward_synapses.end());
}









