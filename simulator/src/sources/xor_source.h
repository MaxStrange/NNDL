/*
 * This is another example of a Source; this one is used for the xor example.
 */
#ifndef __XOR_SOURCE_H__
#define __XOR_SOURCE_H__

#include <iostream>
#include <vector>

#include "source.h"
#include "signal.h"


class XorSource :
    public Source
{
public:
    XorSource();
    ~XorSource();

    friend std::ostream& operator<<(std::ostream &outstream, const XorSource &s);

    std::vector<Signal> get(uint64_t time);

    bool has_more(uint64_t time);

private:
    std::vector<std::vector<Signal>> dataset;
    unsigned int index;
};


#endif //header guard
