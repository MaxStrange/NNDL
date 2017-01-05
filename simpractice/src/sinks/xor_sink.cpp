#include <cassert>
#include <vector>

#include "xor_sink.h"

XorSink::XorSink()
{
}

XorSink::~XorSink()
{
}

std::ostream& operator<<(std::ostream &outstream, const XorSink &s)
{
    outstream << "Sink: XOR";
    return outstream;
}

std::vector<Signal> XorSink::take(uint64_t time, std::vector<Signal> &outputs,
        const std::vector<Signal> &inputs)
{
    assert((outputs.size() == NUM_NEURONS_OUTPUT));
    assert((outputs.size() == 1));

    Signal output = outputs.at(0);
    std::cout << "RAW: " << output << " ";
    output = output > Signal(0.5) ? Signal(1) : Signal(0);

    Signal sum = inputs.at(0) + inputs.at(1);
    auto val = sum == Signal(1) ? 1 : 0;
    Signal label(val);
    Signal diff = label - output;

    Signal err = diff * diff;
    std::cout << "GOT: " << output << " " << "LABEL: " << label << " ";
    std::cout << "ERROR: " << err << std::endl;

    std::vector<Signal> label_as_vec = { label };
    return label_as_vec;
}










