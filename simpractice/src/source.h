/*
 * The Source is the data getter. It has a method, get(), which offers
 * up a std::vector of Signals, which are ready to be put into the network's
 * input layer.
 *
 * TODO: eventually, this should be made an abstract base class that the user
 * would subclass off of, or else they could maybe just implement their own
 * functions inside of this class. Whatever works.
 */
#ifndef __SOURCE_H__
#define __SOURCE_H__

#include <iostream>
#include <vector>

#include "signal.h"

class Source
{
public:
    Source();
    ~Source();

    friend std::ostream& operator<<(std::ostream &outstream, const Source &s);

    /*
     * Gets the next vector of input data. The vector must be of length
     * equal to the number of input neurons in the network.
     */
    std::vector<Signal> get();
};

#endif //header guard



