"""
Provides methods to write various parts of a dot file
"""

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

    node [fixedsize=true, label=""];"""
    with open(fname, 'w') as f:
        f.write(boilerplate)
        f.write(os.linesep + os.linesep)


def write_connections(conx, fname):
    """
    Writes the connections to the file.
    """
    for pair in conx:
        n0, n1 = pair[0], pair[1]
        lines = ["\t" + n0 + " -> " + n1 + ";"]
        text = os.linesep.join(lines)
        with open(fname, 'a') as f:
            f.write(text)


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

    nodes = [name + "_" + str(i) for i in range(nrows * ncols)]
    nodes_str = ", ".join(nodes)
    text = "\t" + "subgraph " + name + " {" + os.linesep
    text += "\t\t" + "color=white;" + os.linesep
    text += "\t\t" + "node [style=solid, color=" + color + ", shape=circle];" + os.linesep
    text += "\t\t" + nodes_str + ";" + os.linesep
    text += "\t\t" + "label=\"" + name + " Layer\";" + os.linesep
    text += "\t" + "}" + os.linesep

    with open(fname, 'a') as f:
        f.write(text)






