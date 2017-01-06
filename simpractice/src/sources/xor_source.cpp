#include <iostream>
#include <vector>

#include "signal.h"

#include "xor_source.h"



XorSource::XorSource()
{
    this->index = 0;

    //This example is super simple - we just have a dataset of
    //all possible inputs to the xor network.
    //The corresponding sink (xor_sink.h) will have the
    //labels for the dataset in the same order
    for (unsigned int i = 0; i <= 1; i++)
    {
        for (unsigned int j = 0; j <= 1; j++)
        {
            std::vector<Signal> x;
            x.push_back(Signal(i));
            x.push_back(Signal(j));
            this->dataset.push_back(x);
        }
    }
    //results in a dataset like this:
    //0, 0
    //0, 1
    //1, 0
    //1, 1
}

XorSource::~XorSource()
{
}

std::ostream& operator<<(std::ostream &outstream, const XorSource &s)
{
    outstream << "Source: XOR";
    return outstream;
}

std::vector<Signal> XorSource::get(uint64_t time)
{
    if (this->index >= this->dataset.size())
        this->index = 0;

    return this->dataset.at(this->index++);
}

bool XorSource::has_more(uint64_t time)
{
    static const unsigned int max_times = 1000;
    return time < max_times;
}






