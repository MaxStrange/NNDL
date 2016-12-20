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
    def __init__(self, fname):
        self._fname = fname

    def enterProg(self, ctx):
        #TODO: write the dot file's boiler plate
        print("Enter prog")
        pass

    def exitProg(self, ctx):
        print("Wrote dot file for %s." % self._fname)

    def exitLayer_stat(self, ctx):
        #TODO: make a subgraph and write it to the file
        print("Found a layer: ", repr(ctx))

    def exitCon_stat(self, ctx):
        #TODO: figure out the connections and write them to the file
        print("con_stat: ", repr(ctx))










