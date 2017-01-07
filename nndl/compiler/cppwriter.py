"""
Module responsible for writing the C++ file to be used in the simulator.
"""

import os
import subprocess


def write_file(nw, output_file_name, sim_dir):
    """
    Writes the file needed by the simulator to the output_file.
    nw is a network populated by the nndl file.
    sim_dir is the directory where the simulator source code lives
    """
    output_file_name = output_file_name + "_autogen"
    with open(output_file_name + ".cpp", 'w') as of:
        _write_boilerplate(of)
        _write_create_layers(nw, of)
        _write_connect_layers(nw, of)

    with open(output_file_name + ".h", 'w') as of:
        _write_headerfile(of, output_file_name)

    print("Wrote code to " + output_file_name + ".cpp"\
            + " and " + output_file_name + ".h")
    subprocess.call(["mv", output_file_name + ".cpp",
            sim_dir + os.sep + output_file_name + ".cpp"])
    subprocess.call(["mv", output_file_name + ".h",
            sim_dir + os.sep + output_file_name + ".h"])
    print("And then moved to: " + sim_dir)

    _update_main([output_file_name + ".h"], sim_dir)
    print("Updated simulator's main to know where to find them.")


def _update_main(files, src_dir):
    """
    Updates src/headers.h to include the right files.
    """
    path = src_dir + os.sep + "headers.h"

    lines = []
    lines += "#ifndef __HEADERS_H__" + os.linesep
    lines += "#define __HEADERS_H__" + os.linesep + os.linesep

    for f in files:
        lines += ["#include \"" + f + "\"" + os.linesep]

    lines += "#endif //header guard" + os.linesep

    with open(path, 'w') as f:
        for line in lines:
            f.write(line)


def _write_headerfile(of, output_file_name):
    to_write = """
/*
 * This file and the corresponding .cpp file was auto generated
 * with the nndl compiler for the nndl simulator.
 */
#ifndef __""" + output_file_name.upper() + """_H__
#define __""" + output_file_name.upper() + """_H__

#include <vector>

#include "layer.h"
#include "synapse.h"

std::vector<Layer *> create_layers(void);

std::vector<Synapse *>& connect_layers(const std::vector<Layer *> &layers,
        std::vector<Synapse *> &connections);

#endif //header guard"""

    of.write(to_write)


def _write_boilerplate(of):
    """
    Writes the cpp file's boilerplate.
    """
    c_includes = ["iostream", "vector", "random"]
    l_includes = ["layer.h", "neuron.h", "synapse.h"]

    to_write = ""

    for inc in c_includes:
        to_write += "#include <" + inc + ">" + os.linesep

    for inc in l_includes:
        to_write += "#include \"" + inc + "\"" + os.linesep

    to_write += "#include SYNAPSE_HEADER" + os.linesep
    to_write += "#include NEURON_HEADER" + os.linesep
    to_write += "#include BIAS_HEADER" + os.linesep

    to_write += os.linesep
    to_write += "static Signal generate_random_weight();" + (os.linesep * 2)

    to_write += """Signal generate_random_weight()
{
    static auto seed = 5;
    std::mt19937 rng(seed++);
    double min = -0.5;
    double max = -0.5;
    std::uniform_real_distribution<double> uni(min, max);

    double rn = uni(rng);

    return Signal(rn);
}""" + (os.linesep * 2)

    of.write(to_write)


def _write_create_layers(nw, of):
    """
    Writes the create_layers function to the cpp file.
    """
    to_write = """std::vector<Layer *> create_layers(void)
{
    std::cout << "Creating the layers..." << std::endl;

    std::vector<Layer *> layers;""" + os.linesep + os.linesep

    for i, layer in enumerate(nw.layers):
        layer_id = "layer_" + str(i)
        to_write += "    Layer *" + layer_id + " = new Layer();" + os.linesep

        to_write += "    for (unsigned int i = 0; i < " + str(len(layer))
        to_write += "; i++)" + os.linesep
        to_write += "    {" + os.linesep

        # neuron_id is like: neuron_0_1
        neuron_id = "\"neuron_" + str(i) + "_\"" + " + std::to_string(i)"
        is_input = i == 0
        is_output = i == len(nw.layers) - 1
        to_write += "        Neuron n(" + neuron_id + ", " + str(is_input).lower()
        to_write += ", " + str(is_output).lower() + ");" + os.linesep

        to_write += "        " + layer_id + "->add_neuron(n);" + os.linesep
        to_write += "    }" + os.linesep
        to_write += "    layers.push_back(" + layer_id + ");" + os.linesep
        to_write += os.linesep
    to_write += "    return layers;" + os.linesep
    to_write += "}" + os.linesep

    of.write(to_write)


def _write_connect_layers(nw, of):
    """
    Writes the connect_layers function to the cpp file.
    """
    to_write = """
std::vector<Synapse *>& connect_layers(const std::vector<Layer *> &layers,
        std::vector<Synapse *> &connections)
{
    std::cout << "Connecting layers..." << std::endl;

    for (unsigned int i = 0; i < layers.size(); i++)
    {
        std::cout << "Connecting layer " << std::to_string(i) << std::endl;
        std::cout << "Number of neurons in this layer: " <<
                std::to_string(layers.at(i)->size()) << std::endl;
        if (i != layers.size() - 1)
        {
            //We are not the last layer, so add forward connections
            Layer *layer_i = layers.at(i);
            for (unsigned int j = 0; j < layer_i->size(); j++)
            {
                Neuron *neuron_j_pointer = layer_i->at(j);
                Layer *layer_next = layers.at(i + 1);
                //Connect neuron_j to each neuron_l in layer i + 1
                for (unsigned int l = 0; l < layer_next->size(); l++)
                {
                    Signal w = generate_random_weight();
                    std::cout << "Weight (" << i << "_" << j << ", " << i + 1
                            << "_" << l << "): " << w << std::endl;
                    Neuron *neuron_l_pointer = layer_next->at(l);
                    //Synapse from j to l
                    Synapse *s = new SYNAPSE(neuron_j_pointer, neuron_l_pointer, w);
                    if (j == 0)
                    {
                        std::cout << "Bias weight (" << i << "_" << j << ", " << i + 1
                                << "_" << l << "): " << w << std::endl;

                        Synapse *b = new BIAS(neuron_j_pointer, neuron_l_pointer, w);
                        connections.push_back(b);
                    }
                    connections.push_back(s);
                }
            }
        }
    }
    return connections;
}"""

    of.write(to_write)







