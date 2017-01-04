/*
 * This is the Sink for the Xor example.
 */
#ifndef __XOR_SINK_H__
#define __XOR_SINK_H__

#include <vector>

#include "sink.h"

class XorSink :
    public Sink
{
public:
    XorSink();
    ~XorSink();

    friend std::ostream& operator<<(std::ostream &oustream, const XorSink &s);

    std::vector<Signal> take(uint64_t time, std::vector<Signal> &outputs);

private:
    std::vector<Signal> labels;
    unsigned int index;
};


#endif //header guard






