"""
Module responsible for writing the C++ file to be used in the simulator.
"""

import os


def write_file(nw, output_file_name):
    """
    Writes the file needed by the simulator to the output_file.
    nw is a network populated by the nndl file.
    """
    with open(output_file_name + ".cpp", 'w') as of:
        _write_boilerplate(of)
        _write_create_layers(nw, of)
        _write_connect_layers(nw, of)

    with open(output_file_name + ".h", 'w') as of:
        _write_headerfile(of)



def _write_boilerplate(of):
    """
    Writes the cpp file's boilerplate.
    """
    c_includes = ["iostream", "vector"]
    l_includes = ["layer.h", "neuron.h", "synapse.h"]

    to_write = ""

    for inc in c_includes:
        to_write += "#include <" + inc + ">" + os.linesep

    for inc in l_includes:
        to_write += "#include \"" + inc + "\"" + os.linesep

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









