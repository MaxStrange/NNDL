/*
 * The Simulator class is the class that actually runs the program.
 *
 * It takes values from the Source until the Source is empty, and feeds
 * those values into the network, getting values out the otherside, which
 * it then feeds into the Sink.
 *
 * After a vector of Signals comes out of the network and is fed into the Sink,
 * the Simulator takes the resulting values from the Sink, and places them
 * back into the Network's fire_backward function, which is usually used for
 * training.
 */
#include <iostream>

#include "network.h"
#include "sink.h"
#include "source.h"


class Simulator
{
public:
    Simulator(Network *network, Source *source, Sink *sink);
    ~Simulator();

    friend std::ostream& operator<<(std::ostream &outstream, const Simulator &s);

    void run();

private:
    Network *network;
    Sink *sink;
    Source *source;
};






