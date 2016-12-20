"""
Provides methods to write various parts of a dot file
"""

def write_boilerplate(fname):
    """
    Writes the boilerplate dot code to the dot file. This should be
    the first method called on a file.
    """
    boilerplate =\
    """digraph G {
    rankdir=LR
    splines=line

    node [fixedsize=true, label=""];
    """
    with open(fname, 'w') as f:
        f.write(boilerplate)


