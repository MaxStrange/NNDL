#include <iostream>
#include <vector>

#include "debug.h"
#include "signal.h"

#include "source.h"


Source::Source()
{
}

Source::~Source()
{
}

std::ostream& operator<<(std::ostream &outstream, const Source &s)
{
    outstream << debug_print_header("Source") << std::endl;
    outstream << debug_print_closing("Source") << std::endl;

    return outstream;
}

std::vector<Signal> get()
{
    //TODO
    return std::vector<Signal>();
}





