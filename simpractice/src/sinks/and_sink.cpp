#include <cassert>
#include <vector>

#include "and_sink.h"

AndSink::AndSink()
{
}

AndSink::~AndSink()
{
}

std::ostream& operator<<(std::ostream &outstream, const AndSink &s)
{
    outstream << "Sink: AND";
    return outstream;
}

std::vector<Signal> AndSink::take(uint64_t time, std::vector<Signal> &outputs,
        const std::vector<Signal> &inputs)
{
    assert((outputs.size() == NUM_NEURONS_OUTPUT));
    assert((outputs.size() == 1));

    Signal output = outputs.at(0);
    std::cout << "RAW: " << output << " ";
    output = output >= Signal(0.5) ? Signal(1) : Signal(0);

    auto val = (inputs.at(0) == 1 && inputs.at(1) == 1) ? 1 : 0;
    Signal label(val);
    Signal diff = label - output;

    Signal err = diff * diff;
    std::cout << "GOT: " << output << " " << "LABEL: " << label << " ";
    std::cout << "ERROR: " << err << std::endl;

    std::vector<Signal> label_as_vec = { label };
    return label_as_vec;
}






