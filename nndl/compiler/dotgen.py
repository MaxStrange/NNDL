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
        self._num_layers = 0

    def enterProg(self, ctx):
        dotwriter.write_boilerplate(self._output_fname)

    def exitProg(self, ctx):
        print("Wrote dot file for %s to %s." %\
                (self._fname, self._output_fname))

    def exitLayer_stat(self, ctx):
        layer_name = ctx.ID()[0].getText()
        num_rows = int(ctx.MAT_DECL().getText()[0])
        num_cols = int(ctx.MAT_DECL().getText()[-1])
        neuron_type = ctx.ID()[1].getText()
        color = dotwriter.get_color(self._num_layers)
        dotwriter.write_layer(name=layer_name, nrows=num_rows, ncols=num_cols,
                neur_type=neuron_type, color=color, fname=self._output_fname)

        self._num_layers += 1

    def exitCon_stat(self, ctx):
        #TODO: figure out the connections and write them to the file
        print("con_stat: ", repr(ctx))










