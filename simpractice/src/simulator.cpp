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
    auto epoch = 0;
    auto num_right_this_epoch = 0;
    while (this->source->has_more(t) && debug_not_done)
    {
        if (t % 4 == 0)
            std::cout << "EPOCH: " << epoch++ << std::endl;

        std::cout << "========================" << std::endl;
        std::cout << "Step: " << t << std::endl;

        std::vector<Signal> weights_before;
        this->network->get_weights(weights_before);

        std::vector<Signal> inputs = this->source->get(t);
        std::vector<Signal> outputs = this->network->fire_forward(t, inputs);
        std::vector<Signal> back_inputs = this->sink->take(t, outputs, inputs);
        std::vector<Signal> back_outputs =
                this->network->fire_backward(t, back_inputs);
        t++;

        if (t > DEBUG_NUM_RUNS)
            debug_not_done = false;

        std::cout << "LABEL: " << back_inputs.at(0) << std::endl;
        std::cout << "WEIGHTS: [";
        std::cout << weights_before.at(1) << "   ";
        std::cout << weights_before.at(2) << "   ";
        std::cout << weights_before.at(0) << "]" << std::endl;
        std::cout << "DATA: [ ";
        for (unsigned int i = 0; i < inputs.size(); i++)
        {
            std::cout << inputs.at(i) << "   ";
        }
        std::cout << "-0.1 ]" << std::endl;
        auto clamped = (outputs.at(0) >= Signal(0.5)) ? Signal(1) : Signal(0);
        std::cout << "FF OUTPUT: " << outputs.at(0) << " --> " <<
                clamped << std::endl;
        std::vector<Signal> weights;
        this->network->get_weights(weights);
        std::cout << "WEIGHTS AFTER BACKPROP: [";
        std::cout << weights.at(1) << "   ";
        std::cout << weights.at(2) << "   ";
        std::cout << weights.at(0) << "]" << std::endl;
        std::cout << "========================" << std::endl;

        if (clamped == back_inputs.at(0))
            num_right_this_epoch++;

        if (t % 4 == 0)
        {
            auto accuracy = num_right_this_epoch / 4.0;
            std::cout << "========ACCURACY OVER THE LAST EPOCH: "
                    << accuracy << "==========" << std::endl;
            num_right_this_epoch = 0;
        }
    }
}



