/*
 * This is an example Sink for the MNIST dataset.
 */
#ifndef __MNIST_SINK_H__
#define __MNIST_SINK_H__

#include <vector>

#include "sink.h"

class MnistSink :
    public Sink
{
public:
    MnistSink();
    ~MnistSink();

    friend std::ostream& operator<<(std::ostream &outstream, const MnistSink &s);

    std::vector<Signal> take(uint64_t time, std::vector<Signal> &outputs);

private:
    uint64_t index;
    std::vector<uint8_t> labels;

    std::vector<Signal> get_next_label();
    void load_labels();
};




#endif //header guard





