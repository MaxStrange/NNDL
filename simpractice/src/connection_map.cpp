#include <iostream>
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
    //TODO -> must create each of the maps
    //this->create_forward_map(neurons, connections);
    //this->create_reverse_map(neurons, connections);
    //this->create_forward_synapses(neurons, connections);
    //this->create_reverse_synapses(neurons, connections);
    //this->create_forward_map_synapses(neurons, connections);
    //this->create_reverse_map_synapses(neurons, connections);
}

ConnectionMap::~ConnectionMap()
{
}

std::ostream& operator<<(std::ostream &outstream, const ConnectionMap &cm)
{
    outstream << debug_print_header("ConnectionMap") << std::endl;
    outstream << "Connections: " << std::endl;
    outstream << this->connections << std::endl;
    outstream << "Neurons: " << std::endl;
    outstream << this->neurons << std::endl;
    outstream << debug_print_closing("ConnectionMap") << std::endl;

    return outstream;
}

void ConnectionMap::get_inputs(const Neuron *n,
        std::vector<Neuron *> &inputs) const
{
    inputs = this->reverse_map[n];
}

void ConnectionMap::get_outputs(const Neuron *n,
        std::vector<Neuron *> &outputs) const
{
    outputs = this->forward_map[n];
}

void ConnectionMap::get_output_synapses(const Neuron *n,
        std::vector<Synapse *> &syns) const
{
    syns = this->forward_map_synapses[n];
}

void ConnectionMap::get_synapse(const Neuron *from, const Neuron *to,
        Synapse &syn) const
{
    syn = this->forward_synapses[std::make_tuple(from, to)];
}











