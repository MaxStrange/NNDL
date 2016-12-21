"""
Provides methods to write various parts of a dot file
"""

import itertools
import math
import os

def get_color(index):
    """
    Gets a color by index.
    """
    colors = [
        "aquamarine",
        # "blue",  # Too dark
        # "chartreuse", # Too bright
        "coral",
        "cyan",
        "darkgoldenrod",
        "darkorange",
        "darksalmon",
        "darkturquoise",
        # "deeppink",  # Way too bright
        # "firebrick",  # A little too dark
        # "forestgreen", # Too dark
        "gold",
        "hotpink",
        "indianred",
        "khaki",
        # "lightcyan",  # A little too light
        "lightgoldenrod",
        "limegreen",
        "mediumseagreen",
        "mediumturquoise"
        # "navyblue",  # Way too dark
        "olivedrab",
        "orange",
        "orangered",
        "palegreen",
        "paleturquoise",
        # "red",  # A little too intense
        "seagreen",
        "springgreen",
        "steelblue",
        "skyblue",
        "tomato",
        "violetred",
        "wheat",
        "yellowgreen"
    ]
    return colors[index % len(colors)]


def write_boilerplate(fname):
    """
    Writes the boilerplate dot code to the dot file. This should be
    the first method called on a file.
    """
    boilerplate =\
    """digraph G {
    rankdir=LR
    splines=line

    node [fixedsize=true];"""
    with open(fname, 'w') as f:
        f.write(boilerplate)
        f.write(os.linesep + os.linesep)


def write_connections(conx, fname):
    """
    Writes the connections to the file.
    """
    lines = []
    for pair in conx:
        n0, n1 = pair[0], pair[1]
        index_from = int(n0.split('_')[1])
        index_to = int(n1.split('_')[1])
        # Make the weight biggest when the difference between
        # the two indexes is 0
        weight = 10.0 * _gauss(index_from - index_to)
        line = "    " + n0 + " -> " + n1
        line += " [weight=" + str(weight) + "];"
        lines.append(line)
    with open(fname, 'a') as f:
        for line in lines:
            f.write(line + os.linesep)


def _gauss(x):
    mu = 0
    sigma = 1.0
    ex = pow(math.e, (-(x - mu) ** 2) / (2 * sigma ** 2))
    base = 1.0 / math.sqrt(2 * sigma ** 2 * math.pi)
    return base * ex


def write_end(fname):
    """
    Writes the closing curly brace to the file.
    """
    with open(fname, 'a') as f:
        f.write("}" + os.linesep)


def write_layer(name, nrows, ncols, neur_type, color, fname):
    """
    Writes a subgraph corresponding to the layer information
    given to the given file's end.
    """
    # Currently just lay out the layer in a single dimension
    # Would love to change this in the future

    nodes = [name + "_" + str(i) + "[label=\"" + name + "_" + str(i)+\
                "\"]" for i in range(nrows * ncols)]
    nodes_str = (";" + os.linesep + "        ").join(nodes)
    text = "    " + "subgraph " + name + " {" + os.linesep
    text += "        " + "color=white;" + os.linesep
    text += "        " + "rank=same;" + os.linesep
    text += "        " + "node [style=solid, color=" + color + ", shape=circle];" + os.linesep
    text += "        " + nodes_str + ";" + os.linesep
    text += "        " + "label=\"" + name + " Layer\";" + os.linesep
    text += "    " + "}" + os.linesep

    with open(fname, 'a') as f:
        f.write(text)






