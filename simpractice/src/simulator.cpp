#include <vector>

#include "network.h"
#include "sink.h"
#include "source.h"


Simulator::Simulator(Network &network, Source &source, Sink &sink)
{
    this->network = network;
    this->sink = sink;
    this->source = source;
}

Simulator::~Simulator()
{
}

void Simulator::run()
{
    //TODO
#if 0
    while (this->source.has_more())
    {
        std::vector<Signal> inputs = this->source.get();
        std::vector<Signal> outputs = this->network.fire_forward(inputs);
        std::vector<Signal> back_inputs = this->sink.take(outputs);
        std::vector<Signal> back_outputs =
                this->network.fire_backward(back_inputs);
    }
#endif
}



