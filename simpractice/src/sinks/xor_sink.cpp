#include <cassert>
#include <vector>

#include "xor_sink.h"

XorSink::XorSink()
{
    this->index = 0;

    this->labels = std::vector<Signal> {
        Signal(0), Signal(1), Signal(1), Signal(0)
    };
    //results in labels that look like this:
    //0
    //1
    //1
    //0
}

XorSink::~XorSink()
{
}

std::ostream& operator<<(std::ostream &outstream, const XorSink &s)
{
    outstream << "Sink: XOR";
    return outstream;
}

std::vector<Signal> XorSink::take(uint64_t time, std::vector<Signal> &outputs)
{
    assert((outputs.size() == NUM_NEURONS_OUTPUT));
    assert((outputs.size() == 1));

    Signal output = outputs.at(0);

    if (this->index >= this->labels.size())
        this->index = 0;

    Signal label = this->labels.at(this->index++);
    Signal diff = label - output;

    Signal err = diff * diff;
    std::cout << "GOT: " << output << " " << "LABEL: " << label << " ";
    std::cout << "ERROR: " << err << std::endl;

    std::vector<Signal> label_as_vec = { label };
    return label_as_vec;
}










