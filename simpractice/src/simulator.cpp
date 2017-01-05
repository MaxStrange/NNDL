#include <iostream>
#include <vector>

#include "debug.h"
#include "network.h"
#include "sink.h"
#include "source.h"

#include "simulator.h"


Simulator::Simulator(Network *network, Source *source, Sink *sink)
{
    this->network = network;
    this->sink = sink;
    this->source = source;
}

Simulator::~Simulator()
{
}

std::ostream& operator<<(std::ostream &outstream, const Simulator &s)
{
    outstream << debug_print_header("Simulator") << std::endl;
    outstream << "Network: " << std::endl;
    outstream << *(s.network) << std::endl;
    outstream << *(s.sink) << std::endl;
    outstream << *(s.source) << std::endl;
    outstream << debug_print_closing("Simulator") << std::endl;

    return outstream;
}

void Simulator::run()
{
    std::cout << "Running simulator..." << std::endl;

    uint64_t t = 0;
    bool debug_not_done = true;
    uint64_t debug_time_step_limit = 50;
    while (this->source->has_more(t) && debug_not_done)
    {
        std::cout << "Running timestep " << t << "..." << std::endl;

        std::vector<Signal> inputs = this->source->get(t);
        std::vector<Signal> outputs = this->network->fire_forward(t, inputs);
        std::vector<Signal> back_inputs = this->sink->take(t, outputs);
        std::vector<Signal> back_outputs =
                this->network->fire_backward(t, back_inputs);
        t++;

        if (t > debug_time_step_limit)
            debug_not_done = false;

        this->network->print_weights();
    }
}



