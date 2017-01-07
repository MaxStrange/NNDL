/*
 * This is another example of a Source. This one is used for the AND example.
 */
#ifndef __AND_SOURCE_H__
#define __AND_SOURCE_H__

#include <iostream>
#include <vector>

#include "source.h"
#include "signal.h"


class AndSource :
    public Source
{
public:
    AndSource();
    ~AndSource();

    friend std::ostream& operator<<(std::ostream &outstream, const AndSource &s);

    std::vector<Signal> get(uint64_t time);

    bool has_more(uint64_t time);

private:
    std::vector<std::vector<Signal>> dataset;
    unsigned int index;
};



#endif //header guard
