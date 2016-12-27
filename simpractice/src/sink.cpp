#include <iostream>
#include <vector>

#include "debug.h"
#include "signal.h"

#include "sink.h"


Sink::Sink()
{
}

Sink::~Sink()
{
}

std::ostream& operator<<(std::ostream &outstream, const Sink &s)
{
    outstream << debug_print_header("Sink") << std::endl;
    outstream << debug_print_closing("Sink") << std::endl;

    return outstream;
}

std::vector<Signal> Sink::take(std::vector<Signal> outputs)
{
    //TODO
    return std::vector<Signal>();
}



