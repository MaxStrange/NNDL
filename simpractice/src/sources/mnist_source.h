/*
 * This is a subclass of Source that serves as an example of how you might go
 * about implementing a Source for a given project.
 */

#ifndef __MNIST_SOURCE_H__
#define __MNIST_SOURCE_H__

#include <iostream>
#include <vector>

#include "source.h"
#include "signal.h"


class MnistSource :
    public Source
{
public:
    MnistSource();
    ~MnistSource();

    friend std::ostream& operator<<(std::ostream &outstream, const MnistSource &ms);

    std::vector<Signal> get(uint64_t time);

    bool has_more(uint64_t time);

private:
    unsigned char **dataset;
    unsigned int nimages;
    unsigned int imgsz;

    void load_dataset();
};




#endif//header guard





