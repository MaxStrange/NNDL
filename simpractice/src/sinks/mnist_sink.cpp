#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

#include "signal.h"

#include "mnist_sink.h"



MnistSink::MnistSink()
{
    this->index = 0;
    this->load_labels();
}

MnistSink::~MnistSink()
{
}

std::ostream& operator<<(std::ostream &outstream, const MnistSink &s)
{
    outstream << "Mnist Sink";
    return outstream;
}

std::vector<Signal> MnistSink::take(uint64_t time, std::vector<Signal> &outputs)
{
    std::vector<Signal> diffs;

    //take the next sz (should be 10) labels and compare them to the outputs
    for (unsigned int i = 0; i < outputs.size(); i++)
    {
        Signal s = outputs.at(i);
        Signal label = Signal(this->labels.at(this->index));
        this->index++;

        Signal dif = label - s;
        diffs.push_back(dif);

        std::cout << "Difference: " << dif << std::endl;
    }

    return diffs;
}

void MnistSink::load_labels()
{
    std::string path("mnist/train-labels-idx1-ubyte");//This one is for training
    //std::string path("mnist/t10k-labels-idx1-ubyte");//This one is for testing


    auto reverse_int = [](int i)
    {
        unsigned char c1, c2, c3, c4;
        c1 = i & 0xFF;
        c2 = (i >> 8) & 0xFF;
        c3 = (i >> 16) & 0xFF;
        c4 = (i >>24) & 0xFF;
        return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
    };

    std::ifstream file(path, std::ios::binary);
    if (file.is_open())
    {
        int32_t magic_number = 0;
        int32_t num_labels = 0;

        //Read the first value into 'magic_number' to see if the file is valid
        file.read((char *)&magic_number, sizeof(magic_number));
        magic_number = reverse_int(magic_number);

        bool magic_valid = (magic_number == 2049);
        if (!magic_valid)
            throw std::runtime_error("Invalid MNIST label file.");

        file.read((char *)&num_labels, sizeof(num_labels));
        num_labels = reverse_int(num_labels);
        std::cout << "Number of labels: " << num_labels << std::endl;

        uint8_t label;
        for (int i = 0; i < num_labels; i++)
        {
            file.read((char *)&label, sizeof(label));
            this->labels.push_back(label);
        }
    }
    else
    {
        throw std::runtime_error("Cannot open file `" + path + "`");
    }
}










