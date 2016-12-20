"""
This module provides a class for the antlr framework to walk the tree
and generate dot graphs.
"""

import compiler.dotwriter as dotwriter
from grammar import NNDLListener

class DotGenerator(NNDLListener.NNDLListener):
    """
    Listener that generates dot files when walked over the nndl tree.
    """
    def __init__(self, fname, output_fname):
        self._fname = fname
        self._output_fname = output_fname

    def enterProg(self, ctx):
        dotwriter.write_boilerplate(self._output_fname)

    def exitProg(self, ctx):
        print("Wrote dot file for %s to %s." %\
                (self._fname, self._output_fname))

    def exitLayer_stat(self, ctx):
        #TODO: make a subgraph and write it to the file
        print("Found a layer: ", repr(ctx))
        text = ctx.getText()
        # text --> layer : h2 4x1 = n;
        #TODO: send whitespace on hidden channel

    def exitCon_stat(self, ctx):
        #TODO: figure out the connections and write them to the file
        print("con_stat: ", repr(ctx))










