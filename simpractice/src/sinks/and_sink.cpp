#include <cassert>
#include <vector>

#include "and_sink.h"

AndSink::AndSink()
{
    this->index = 0;
    this->labels = std::vector<Signal> {
        Signal(0), Signal(0), Signal(0), Signal(1)
    };
}

AndSink::~AndSink()
{
}

std::ostream& operator<<(std::ostream &outstream, const AndSink &s)
{
    outstream << "Sink: AND";
    return outstream;
}

std::vector<Signal> AndSink::take(uint64_t time, std::vector<Signal> &outputs)
{
    assert((outputs.size() == NUM_NEURONS_OUTPUT));
    assert((outputs.size() == 1));

    Signal output = outputs.at(0);
    std::cout << "RAW: " << output << " ";
    output = output > Signal(0.5) ? Signal(1) : Signal(0);

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






