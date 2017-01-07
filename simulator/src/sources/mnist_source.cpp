#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

#include "debug.h"
#include "signal.h"

#include "mnist_source.h"



MnistSource::MnistSource()
{
    this->seed = 5;
    this->load_dataset();
    //std::default_random_engine rnd(this->seed);
    //shuffle(this->dataset.begin(), this->dataset.end(), rnd);
}

MnistSource::~MnistSource()
{
}

std::ostream& operator<<(std::ostream &outstream, const MnistSource &ms)
{
    outstream << debug_print_header("MNIST Source") << std::endl;
    outstream << "ntimes_given: " << ms.ntimes_given << std::endl;
    outstream << "nimages: " << ms.nimages << std::endl;
    outstream << "imgsz: " << ms.imgsz << std::endl;
    outstream << debug_print_closing("MNIST Source") << std::endl;

    return outstream;
}

std::vector<Signal> MnistSource::get(uint64_t time)
{
    if (this->ntimes_given >= this->dataset.size())
    {
        this->ntimes_given = 0;
    }

    std::vector<Signal> data_vector;
    image img = this->dataset.at(this->ntimes_given++);
    for (unsigned int i = 0; i < this->imgsz; i++)
    {
        uint8_t val = img.at(i);
        Signal s((fpoint_t)val);
        data_vector.push_back(s);
    }

    return data_vector;
}

bool MnistSource::has_more(uint64_t time)
{
    static const auto num_epochs = 1;
    return this->ntimes_given / this->nimages < num_epochs;
}



void MnistSource::load_dataset()
{
    /*
     * This method shamelessly taken from Stack Overflow:
     * https://stackoverflow.com/questions/8286668/how-to-read-mnist-data-in-c
     */

    auto reverse_int = [](int i)
    {
        unsigned char c1, c2, c3, c4;
        c1 = i & 0xFF;
        c2 = (i >> 8) & 0xFF;
        c3 = (i >> 16) & 0xFF;
        c4 = (i >>24) & 0xFF;
        return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
    };

    int number_of_images = 0;
    int image_size = 0;
    std::string path("mnist/train-images-idx3-ubyte");//This one is for training
    //std::string path("mnist/t10k-images-idx3-ubyte");//This one is for testing
    std::ifstream file(path, std::ios::binary);

    if (file.is_open())
    {
        int32_t magic_number = 0;
        int32_t n_rows = 0;
        int32_t n_cols = 0;

        //Read the first value into 'magic_number' to see if the file is valid
        file.read((char *)&magic_number, sizeof(magic_number));
        magic_number = reverse_int(magic_number);

        bool magic_valid = (magic_number == 2051);
        if (!magic_valid)
            throw std::runtime_error("Invalid MNIST data file.");

        std::cout << "Magic Number: " << magic_number << std::endl;

        file.read((char *)&number_of_images, sizeof(number_of_images));
        number_of_images = reverse_int(number_of_images);
        std::cout << "Number of images: " << number_of_images << std::endl;

        file.read((char *)&n_rows, sizeof(n_rows));
        n_rows = reverse_int(n_rows);
        std::cout << "Number of rows: " << n_rows << std::endl;

        file.read((char *)&n_cols, sizeof(n_cols));
        n_cols = reverse_int(n_cols);
        std::cout << "Number of columns: " << n_cols << std::endl;

        image_size = n_rows * n_cols;
        std::cout << "Image size: " << image_size << std::endl;

        unsigned char **dataset = new unsigned char *[number_of_images];
        for (int i = 0; i < number_of_images; i++)
        {
            dataset[i] = new unsigned char[image_size];
            file.read((char *)dataset[i], image_size);

            image img(dataset[i], image_size);
            this->dataset.push_back(img);
            delete dataset[i];
        }
        this->nimages = number_of_images;
        this->imgsz = image_size;
    }
    else
    {
        throw std::runtime_error("Cannot open file `" + path + "`");
    }
}










