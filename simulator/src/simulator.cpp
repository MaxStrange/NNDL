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
    while (this->source->has_more(t) && debug_not_done)
    {
//        std::vector<Signal> weights_before;
//        this->network->get_weights(weights_before);

        std::vector<Signal> inputs = this->source->get(t);
        std::vector<Signal> outputs = this->network->fire_forward(t, inputs);
        std::vector<Signal> back_inputs = this->sink->take(t, outputs, inputs);
        std::vector<Signal> back_outputs =
                this->network->fire_backward(t, back_inputs);

//        std::vector<Signal> weights_after;
//        this->network->get_weights(weights_after);
//        this->print_stats(t, back_inputs.at(0), weights_before, weights_after,
//                inputs, outputs);

        t++;

        if (t > DEBUG_NUM_RUNS)
            debug_not_done = false;
    }
}

void Simulator::print_stats(uint64_t t, const Signal &label,
            const std::vector<Signal> &weights_before,
            const std::vector<Signal> &weights_after,
            const std::vector<Signal> &data_vector,
            const std::vector<Signal> &raw_output) const
{
    static auto epoch = 0;
    static auto num_right_this_epoch = 0;

    if (t % 4 == 0)
        std::cout << "EPOCH: " << epoch++ << std::endl;

    std::cout << "========================" << std::endl;
    std::cout << "Step: " << t << std::endl;
    std::cout << "LABEL: " << label << std::endl;
    std::cout << "WEIGHTS: [ ";
    for (unsigned int i = 0; i < weights_before.size(); i++)
    {
        std::cout << weights_before.at(i) << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "DATA: [ ";
    for (unsigned int i = 0; i < data_vector.size(); i++)
    {
        std::cout << data_vector.at(i) << " ";
    }
    std::cout << "]" << std::endl;
    auto clamped = (raw_output.at(0) >= Signal(0.5)) ? Signal(1) : Signal(0);
    std::cout << "FF OUTPUT: " << raw_output.at(0) << " --> " <<
            clamped << std::endl;
    std::cout << "WEIGHTS AFTER BACKPROP: [ ";
    for (unsigned int i = 0; i < weights_after.size(); i++)
    {
        std::cout << weights_after.at(i) << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "========================" << std::endl;

    if (clamped == label)
        num_right_this_epoch++;

    if (t % 4 == 0)
    {
        auto accuracy = num_right_this_epoch / 4.0;
        std::cout << "========ACCURACY OVER THE LAST EPOCH: "
                << accuracy << "==========" << std::endl;
        num_right_this_epoch = 0;
    }
}

