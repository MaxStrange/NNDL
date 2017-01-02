#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#include "debug.h"
#include "layer.h"
#include "neuron.h"
#include "synapse.h"
#include "unit_tests.h"

#include "connection_map.h"


ConnectionMap::ConnectionMap()
{
}

ConnectionMap::ConnectionMap(std::vector<SYNAPSE *> &connections,
        std::vector<NEURON *> &neurons)
{
    this->neurons = neurons;
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

void ConnectionMap::create_const_map(std::vector<NEURON *> &neurons)
{
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *n = neurons.at(i);
        this->const_map[n] = n;
    }
}

void ConnectionMap::create_forward_map(std::vector<NEURON *> &neurons,
        std::vector<SYNAPSE *> &connections)
{
    //NEURON -> NEURONs it is connected TO
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *a = neurons.at(i);
        std::vector<SYNAPSE *> synapses = this->forward_map_synapses[a];
        std::vector<NEURON *> neurons_from_a;
        for (unsigned int j = 0; j < synapses.size(); j++)
        {
            SYNAPSE *s = synapses.at(j);
            const NEURON *to = s->get_to();
            neurons_from_a.push_back(this->const_map[to]);
        }
        this->forward_map[a] = neurons_from_a;
    }
}

void ConnectionMap::create_reverse_map(std::vector<NEURON *> &neurons,
        std::vector<SYNAPSE *> &connections)
{
    //NEURON -> NEURONs that connect TO IT
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *a = neurons.at(i);
        std::vector<SYNAPSE *> synapses = this->reverse_map_synapses[a];
        std::vector<NEURON *> neurons_to_a;
        for (unsigned int j = 0; j < synapses.size(); j++)
        {
            SYNAPSE *s = synapses.at(j);
            const NEURON *from = s->get_from();
            neurons_to_a.push_back(this->const_map[from]);
        }
        this->reverse_map[a] = neurons_to_a;
    }
}

void ConnectionMap::create_forward_synapses(std::vector<NEURON *> &neurons,
        std::vector<SYNAPSE *> &connections)
{
    //NEURON a, NEURON b -> SYNAPSE that connects FROM a TO b
    for (unsigned int i = 0; i < connections.size(); i++)
    {
        SYNAPSE *s = connections.at(i);
        const NEURON *a = s->get_from();
        const NEURON *b = s->get_to();
        std::tuple<const NEURON *, const NEURON *> ab = std::make_tuple(a, b);
        this->forward_synapses[ab] = s;
    }
}

void ConnectionMap::create_forward_map_synapses(std::vector<NEURON *> &neurons,
        std::vector<SYNAPSE *> &connections)
{
    //NEURON -> All outgoing SYNAPSEs from it
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *n = neurons.at(i);
        std::vector<SYNAPSE *> ns_synapses;
        for (unsigned int j = 0; j < connections.size(); j++)
        {
            SYNAPSE *s = connections.at(j);
            const NEURON *from = s->get_from();
            const NEURON *to = s->get_to();

            if (n == from)
                ns_synapses.push_back(s);
        }
        this->forward_map_synapses[n] = ns_synapses;
    }
}

void ConnectionMap::create_reverse_map_synapses(std::vector<NEURON *> &neurons,
        std::vector<SYNAPSE *> &connections)
{
    //NEURON -> All incoming SYNAPSEs going into it
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *n = neurons.at(i);
        std::vector<SYNAPSE *> ns_synapses;
        for (unsigned int j = 0; j < connections.size(); j++)
        {
            SYNAPSE *s = connections.at(j);
            const NEURON *from = s->get_from();
            const NEURON *to = s->get_to();

            if (n == to)
                ns_synapses.push_back(s);
        }
        this->reverse_map_synapses[n] = ns_synapses;
    }
}

void ConnectionMap::get_inputs(const NEURON *n,
        std::vector<NEURON *> &inputs)
{
    inputs = this->reverse_map[n];
}

void ConnectionMap::get_input_synapses(const NEURON *n,
        std::vector<SYNAPSE *> &syns)
{
    syns = this->reverse_map_synapses[n];
}

void ConnectionMap::get_outputs(const NEURON *n,
        std::vector<NEURON *> &outputs)
{
    outputs = this->forward_map[n];
}

void ConnectionMap::get_output_synapses(const NEURON *n,
        std::vector<SYNAPSE *> &syns)
{
    syns = this->forward_map_synapses[n];
}

void ConnectionMap::get_synapse(const NEURON *from, const NEURON *to,
        SYNAPSE *&syn)
{
    auto tup = std::make_tuple(from, to);
    syn = this->forward_synapses[tup];
}

bool ConnectionMap::neuron_synapses_onto(const NEURON *n, const NEURON *m)
{
    auto tup = std::make_tuple(n, m);
    return (this->forward_synapses.find(tup) != this->forward_synapses.end());
}

UnitTestResult ConnectionMap::run_tests()
{
    UnitTestResult result;

    ConnectionMap::test_forward_map(result);
    ConnectionMap::test_reverse_map(result);
    ConnectionMap::test_forward_synapses(result);
    ConnectionMap::test_forward_map_synapses(result);
    ConnectionMap::test_reverse_map_synapses(result);
    ConnectionMap::test_const_map(result);

    return result;
}

void ConnectionMap::test_forward_map(UnitTestResult &result)
{
    std::string class_name = "ConnectionMap";
    std::string test_name = "forward_map";

    ConnectionMap mp;
    create_test_connection_map(mp);
    auto map = mp.forward_map;
    auto neurons = mp.neurons;
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *n = neurons.at(i);
        if (n->get_id() == "a")
        {
            auto from_n = map[n];
            bool has_size_two = from_n.size() == 2;
            result.assert(has_size_two, class_name, test_name,
                    "A does not have two synapses leaving it, and should.");
            return;
        }
    }
}

void ConnectionMap::test_reverse_map(UnitTestResult &result)
{
    std::string class_name = "ConnectionMap";
    std::string test_name = "reverse_map";

    ConnectionMap mp;
    create_test_connection_map(mp);
    auto rmap = mp.reverse_map;
    auto neurons = mp.neurons;
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *n = neurons.at(i);
        if (n->get_id() == "c")
        {
            auto into_n = rmap[n];
            //Should have size two
            bool has_size_two = into_n.size() == 2;
            result.assert(has_size_two, class_name, test_name,
                    "C does not have two synapses into it, and should.");
            return;
        }
    }
}

void ConnectionMap::test_forward_synapses(UnitTestResult &result)
{
    std::string class_name = "ConnectionMap";
    std::string test_name = "forward_synapses";

    ConnectionMap mp;
    create_test_connection_map(mp);
    auto fsyns = mp.forward_synapses;
    auto neurons = mp.neurons;
    std::vector<SYNAPSE *> found;
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *n = neurons.at(i);
        for (unsigned int j = 0; j < neurons.size(); j++)
        {
            NEURON *m = neurons.at(j);
            auto tup = std::make_tuple(n, m);
            auto itr = fsyns.find(tup);
            if (itr != fsyns.end())
                found.push_back(itr->second);
        }
    }
    bool passed = result.assert(found.size() >= 6, class_name, test_name,
            "Did not find enough synapses.");
    if (passed)
    {
        bool makes_sense = false;
        bool has_all_combos = false;
        for (unsigned int i = 0; i < found.size(); i++)
        {
            SYNAPSE *s = found.at(i);
            //Check that at least one of these makes sense
            const NEURON *from = s->get_from();
            const NEURON *to = s->get_to();
            if (from->get_id() == "a" && to->get_id() == "c")
                makes_sense = true;

            //And that it doesn't contain all possible combinations
            if (from->get_id() == "a" && to->get_id() == "b")
                has_all_combos = true;
        }
        result.assert(makes_sense, class_name, test_name,
                "The SYNAPSEs don't actually make sense.");
        result.assert(! has_all_combos, class_name, test_name,
                "The map contains all possible combinations.");
    }
}

void ConnectionMap::test_forward_map_synapses(UnitTestResult &result)
{
    std::string class_name = "ConnectionMap";
    std::string test_name = "forward_map_synapses";

    ConnectionMap mp;
    create_test_connection_map(mp);
    auto fmap_synapses = mp.forward_map_synapses;
    auto neurons = mp.neurons;
    bool done_a = false, done_b = false, done_c = false,
            done_d = false, done_e = false;
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *n = neurons.at(i);
        std::vector<SYNAPSE *> from_n = fmap_synapses[n];
        std::string id = n->get_id();
        if (id == "a" && !done_a)
        {
            //a->c, a->d
            bool has_two = from_n.size() == 2;
            result.assert(has_two, class_name, test_name,
                    "NEURON a does not have exactly two synapses and should.");
            done_a = true;
        }
        else if (id == "b" && !done_b)
        {
            //b->a, b->d
            bool has_two = from_n.size() == 2;
            result.assert(has_two, class_name, test_name,
                    "NEURON b does not have exactly two synapses and should.");
            done_b = true;
        }
        else if (id == "c" && !done_c)
        {
            //c->e
            bool ce = from_n.size() == 1 && from_n.at(0)->get_from()->get_id() == "c"
                    && from_n.at(0)->get_to()->get_id() == "e";
            result.assert(ce, class_name, test_name, "NEURON c is missing c->e");
            done_c = true;
        }
        else if (id == "d" && !done_d)
        {
            //d->c
            bool dc = from_n.size() == 1 && from_n.at(0)->get_from()->get_id() == "d"
                    && from_n.at(0)->get_to()->get_id() == "c";
            result.assert(dc, class_name, test_name, "NEURON d is missing d->c");
            done_d = true;
        }
        else if (id == "e" && !done_e)
        {
            //None
            bool has_none = from_n.size() == 0;
            result.assert(has_none, class_name, test_name,
                    "NEURON e has at least one synapse and shouldn't.");
            done_e = true;
        }
    }

}

void ConnectionMap::test_reverse_map_synapses(UnitTestResult &result)
{
    std::string class_name = "ConnectionMap";
    std::string test_name = "reverse_map_synapses";

    ConnectionMap mp;
    create_test_connection_map(mp);
    auto rmap_synapses = mp.reverse_map_synapses;
    auto neurons = mp.neurons;
    bool done_a = false, done_b = false, done_c = false,
            done_d = false, done_e = false;
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        NEURON *n = neurons.at(i);
        std::vector<SYNAPSE *> into_n = rmap_synapses[n];
        std::string id = n->get_id();
        if (id == "a" && !done_a)
        {
            //b -> a
            bool ba = into_n.size() == 1 && into_n.at(0)->get_from()->get_id() == "b"
                    && into_n.at(0)->get_to()->get_id() == "a";
            result.assert(ba, class_name, test_name,
                    "NEURON a is missing b->a");
            done_a = true;
        }
        else if (id == "b" && !done_b)
        {
            //None
            bool has_none = into_n.size() == 0;
            result.assert(has_none, class_name, test_name,
                    "NEURON b has at least on synapse into it, and shouldn't.");
            done_b = true;
        }
        else if (id == "c" && !done_c)
        {
            //a -> c, d -> c
            bool has_two = into_n.size() == 2;
            result.assert(has_two, class_name, test_name,
                    "NEURON c does not have two synapses going into it.");
            done_c = true;
        }
        else if (id == "d" && !done_d)
        {
            //a -> d, b -> d
            bool has_two = into_n.size() == 2;
            result.assert(has_two, class_name, test_name,
                    "NEURON d does not have two synapses going into it.");
            done_d = true;
        }
        else if (id == "e" && !done_e)
        {
            //c -> e
            bool ce = into_n.size() == 1 && into_n.at(0)->get_from()->get_id() == "c"
                    && into_n.at(0)->get_to()->get_id() == "e";
            result.assert(ce, class_name, test_name, "NEURON e missing c->e");
            done_e = true;
        }
    }
}

void ConnectionMap::test_const_map(UnitTestResult &result)
{
    std::string class_name = "ConnectionMap";
    std::string test_name = "const_map";

    ConnectionMap mp;
    create_test_connection_map(mp);

    auto constmap = mp.const_map;
    auto neurons = mp.neurons;
    for (unsigned int i = 0; i < neurons.size(); i++)
    {
        const NEURON *n = neurons.at(i);
        NEURON *m = constmap[n];
        result.assert(n == m, class_name, test_name, "NEURONs not identical");
    }
}

void ConnectionMap::create_test_connection_map(ConnectionMap &cm)
{
    NEURON a("a", true, false), b("b", true, false), c("c", false, false),
            d("d", false, false), e("e", false, true);

    std::vector<Layer *> test_layers;

    Layer *input = new Layer();
    Layer *hidden = new Layer();
    Layer *output = new Layer();
    input->add_neuron(a);
    input->add_neuron(b);
    hidden->add_neuron(c);
    hidden->add_neuron(d);
    output->add_neuron(e);
    test_layers.push_back(input);
    test_layers.push_back(hidden);
    test_layers.push_back(output);

    std::vector<NEURON *> test_neurons;
    for (unsigned int i = 0; i < test_layers.size(); i++)
    {
        for (unsigned int j = 0; j < test_layers.at(i)->size(); j++)
        {
            NEURON *n = test_layers.at(i)->at(j);
            test_neurons.push_back(n);
        }
    }

    NEURON *ap, *bp, *cp, *dp, *ep;
    ap = input->at(0);
    bp = input->at(1);
    cp = hidden->at(0);
    dp = hidden->at(1);
    ep = output->at(0);

    Signal w(1);

    std::vector<SYNAPSE *> test_connections;
    SYNAPSE *ba = new SYNAPSE(bp, ap, w);
    SYNAPSE *ac = new SYNAPSE(ap, cp, w);
    SYNAPSE *ad = new SYNAPSE(ap, dp, w);
    SYNAPSE *dc = new SYNAPSE(dp, cp, w);
    SYNAPSE *ce = new SYNAPSE(cp, ep, w);
    SYNAPSE *bd = new SYNAPSE(bp, dp, w);
    test_connections.push_back(ba); test_connections.push_back(ac);
    test_connections.push_back(ad); test_connections.push_back(dc);
    test_connections.push_back(bd); test_connections.push_back(ce);

    cm = ConnectionMap(test_connections, test_neurons);
}























