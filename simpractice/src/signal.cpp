#include "config.h"

#include "signal.h"


Signal::Signal()
{
    this->value = (fpoint_t)0.0;
}

Signal::Signal(fpoint_t val)
{
    this->value = val;
}

Signal::~Signal()
{
}

fpoint_t Signal::get_value() const
{
    return this->value;
}

void Signal::set_value(fpoint_t val)
{
    this->value = val;
}




