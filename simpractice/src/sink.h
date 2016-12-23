/*
 * The Sink class takes values from the output layer of the network
 * and does whatever internal stuff to them, before then sending
 * new values back through the network the other way.
 */
#ifndef __SINK_H__
#define __SINK_H__

#include <vector>

#include "signal.h"


class Sink
{
public:
    Sink();
    ~Sink();

    std::vector<Signal> take(std::vector<Signal> outputs);

private:
};


#endif //header guard




