"""
This module provides a class for the antlr framework to walk the tree
and generate dot graphs.
"""

import compiler.dotwriter as dotwriter
import compiler.logic as logic
import compiler.network as network
from grammar import NNDLListener
import subprocess


class DotGenerator(NNDLListener.NNDLListener):
    """
    Listener that generates dot files when walked over the nndl tree.
    """
    def __init__(self, fname, output_fname):
        self._fname = fname
        self._output_fname = output_fname
        self._network = network.Network()

    def enterProg(self, ctx):
        dotwriter.write_boilerplate(self._output_fname)

    def exitProg(self, ctx):
        dotwriter.write_end(self._output_fname);
        with open(self._output_fname) as f:
            lines = [line for line in f]
        subprocess.call(["dot", "-Tpng", self._output_fname, "-o",\
                self._output_fname.strip(".dot") + ".png"])
        with open(self._output_fname, 'w') as f:
            for line in lines:
                f.write(line)
        print("Wrote dot file for %s to %s." %\
                (self._fname, self._output_fname))
        print("Also compiled it into a .png file %s." %\
                (self._output_fname.strip(".dot") + ".png"))

    def exitLayer_stat(self, ctx):
        layer_name = ctx.ID()[0].getText()
        num_rows = int(ctx.MAT_DECL().getText()[0])
        num_cols = int(ctx.MAT_DECL().getText()[-1])
        neuron_type = ctx.ID()[1].getText()
        color = dotwriter.get_color(len(self._network.layers))
        dotwriter.write_layer(name=layer_name, nrows=num_rows,
                ncols=num_cols, neur_type=neuron_type, color=color,
                fname=self._output_fname)

        self._network.add_layer(nrows=num_rows, ncols=num_cols,
                neurtype=neuron_type, name=layer_name)

    def enterConnection_stat(self, ctx):
        self._conx = []

    def exitConnection_stat(self, ctx):
        cons = ctx.con_stat()
        # A list of from rules and their corresponding to rules (which
        # is a list)
        rules = []
        for con_stat in cons:
            connect_from = con_stat.neuron_selection()[0]
            connect_to = con_stat.neuron_selection()[1:]

            from_logic_layer = connect_from.logical_expr()[0].getText()
            log_type = self._lookup_log_type(connect_from.logical_expr()[0])
            from_logic_layer = logic.py(from_logic_layer, log_type, "i")

            from_logic_neurs = connect_from.logical_expr()[1].getText()
            log_type = self._lookup_log_type(connect_from.logical_expr()[1])
            from_logic_neurs = logic.py(from_logic_neurs, log_type, "j")

            from_rule = logic.Rule(from_logic_layer, from_logic_neurs)

            to_rules = []
            for to in connect_to:
                to_logic_layer = to.logical_expr()[0].getText()
                log_type = self._lookup_log_type(to.logical_expr()[0])
                to_logic_layer = logic.py(to_logic_layer, log_type, "k")

                to_logic_neurs = to.logical_expr()[1].getText()
                log_type = self._lookup_log_type(to.logical_expr()[1])
                to_logic_neurs = logic.py(to_logic_neurs, log_type, "l")

                to_rule = logic.Rule(to_logic_layer, to_logic_neurs)
                to_rules.append(to_rule)
            rules.append((from_rule, to_rules))

        self._network = logic.pygen(rules, self._network)
        dotwriter.write_connections(self._network.connections,
                self._output_fname)


    def _lookup_log_type(self, logical_expr):
        """
        Looks up whether the logical_expr is log_pred_expr
        or class_expr, or math_expr.
        """
        if logical_expr.log_pred_expr():
            return "pred"
        elif logical_expr.class_expr():
            return "class"
        else:
            return "math"








