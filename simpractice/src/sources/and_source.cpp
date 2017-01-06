#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "signal.h"

#include "and_source.h"



AndSource::AndSource()
{
    this->index = 0;

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

AndSource::~AndSource()
{
}

std::ostream& operator<<(std::ostream &outstream, const AndSource &s)
{
    outstream << "Source: AND";
    return outstream;
}

std::vector<Signal> AndSource::get(uint64_t time)
{
    if (this->index >= this->dataset.size())
    {
        this->index = 0;
        static std::default_random_engine rnd(5);
        shuffle(this->dataset.begin(), this->dataset.end(), rnd);
    }

    return this->dataset.at(this->index++);
}

bool AndSource::has_more(uint64_t time)
{
    return true;
}









