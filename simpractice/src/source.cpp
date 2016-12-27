#include <iostream>
#include <vector>

#include "debug.h"
#include "signal.h"

#include "source.h"


Source::Source()
{
    this->ntimes_given = 0;
}

Source::~Source()
{
}

std::ostream& operator<<(std::ostream &outstream, const Source &s)
{
    outstream << debug_print_header("Source") << std::endl;
    outstream << "ntimes_given: " << s.ntimes_given << std::endl;
    outstream << debug_print_closing("Source") << std::endl;

    return outstream;
}

std::vector<Signal> Source::get()
{
    //TODO
    this->ntimes_given++;
    return std::vector<Signal>();
}

bool Source::has_more(void)
{
    if (this->ntimes_given > 1)
        return false;
    else
        return true;
}





