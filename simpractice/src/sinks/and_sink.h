/*
 * This is the Sink for the AND example.
 */
#ifndef __AND_SINK_H__
#define __AND_SINK_H__

#include <vector>

#include "sink.h"

class AndSink :
    public Sink
{
public:
    AndSink();
    ~AndSink();

    friend std::ostream& operator<<(std::ostream &outstream, const AndSink &s);

    std::vector<Signal> take(uint64_t time, std::vector<Signal> &outputs,
            const std::vector<Signal> &intputs);
};



#endif //header guard
