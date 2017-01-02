#include <iostream>

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


std::ostream& operator<<(std::ostream &outstream, const Signal &s)
{
    outstream << s.value;
    return outstream;
}

Signal& Signal::operator-()
{
    this->value *= (fpoint_t)(-1.0);
    return *this;
}

Signal& Signal::operator+=(const Signal &rhs)
{
    this->value += rhs.value;
    return *this;
}

Signal Signal::operator+(const Signal &rhs) const
{
    return Signal(this->value + rhs.value);
}

Signal& Signal::operator-=(const Signal &rhs)
{
    this->value -= rhs.value;
    return *this;
}

Signal Signal::operator-(const Signal &rhs) const
{
    return Signal(this->value - rhs.value);
}

Signal& Signal::operator*=(const Signal &rhs)
{
    this->value *= rhs.value;
    return *this;
}

Signal Signal::operator*(const Signal &rhs) const
{
    return Signal(this->value * rhs.value);
}

Signal& Signal::operator/=(const Signal &rhs)
{
    this->value /= rhs.value;
    return *this;
}

Signal Signal::operator/(const Signal &rhs) const
{
    return this->value / rhs.value;
}

bool Signal::operator==(const Signal &rhs) const
{
    return this->value == rhs.value;
}

bool Signal::operator!=(const Signal &rhs) const
{
    return !(*this == rhs);
}

bool Signal::operator<(const Signal &rhs) const
{
    return this->value < rhs.value;
}

bool Signal::operator>(const Signal &rhs) const
{
    return this->value > rhs.value;
}

bool Signal::operator>=(const Signal &rhs) const
{
    Signal s = *this;
    return s > rhs;
}

bool Signal::operator<=(const Signal &rhs) const
{
    Signal s = *this;
    return s < rhs;
}

Signal::operator int() const
{
    return (int)this->value;
}

Signal::operator float() const
{
    return (float)this->value;
}

Signal::operator double() const
{
    return (double)this->value;
}

fpoint_t Signal::get_value() const
{
    return this->value;
}

void Signal::set_value(fpoint_t val)
{
    this->value = val;
}




