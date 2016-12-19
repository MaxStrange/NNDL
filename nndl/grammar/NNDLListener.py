# Generated from NNDL.g4 by ANTLR 4.6
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .NNDLParser import NNDLParser
else:
    from NNDLParser import NNDLParser

# This class defines a complete listener for a parse tree produced by NNDLParser.
class NNDLListener(ParseTreeListener):

    # Enter a parse tree produced by NNDLParser#prog.
    def enterProg(self, ctx:NNDLParser.ProgContext):
        pass

    # Exit a parse tree produced by NNDLParser#prog.
    def exitProg(self, ctx:NNDLParser.ProgContext):
        pass


    # Enter a parse tree produced by NNDLParser#import_stat.
    def enterImport_stat(self, ctx:NNDLParser.Import_statContext):
        pass

    # Exit a parse tree produced by NNDLParser#import_stat.
    def exitImport_stat(self, ctx:NNDLParser.Import_statContext):
        pass


    # Enter a parse tree produced by NNDLParser#network_stat.
    def enterNetwork_stat(self, ctx:NNDLParser.Network_statContext):
        pass

    # Exit a parse tree produced by NNDLParser#network_stat.
    def exitNetwork_stat(self, ctx:NNDLParser.Network_statContext):
        pass


    # Enter a parse tree produced by NNDLParser#neuron_stat.
    def enterNeuron_stat(self, ctx:NNDLParser.Neuron_statContext):
        pass

    # Exit a parse tree produced by NNDLParser#neuron_stat.
    def exitNeuron_stat(self, ctx:NNDLParser.Neuron_statContext):
        pass


    # Enter a parse tree produced by NNDLParser#connection_stat.
    def enterConnection_stat(self, ctx:NNDLParser.Connection_statContext):
        pass

    # Exit a parse tree produced by NNDLParser#connection_stat.
    def exitConnection_stat(self, ctx:NNDLParser.Connection_statContext):
        pass


    # Enter a parse tree produced by NNDLParser#layer_stat.
    def enterLayer_stat(self, ctx:NNDLParser.Layer_statContext):
        pass

    # Exit a parse tree produced by NNDLParser#layer_stat.
    def exitLayer_stat(self, ctx:NNDLParser.Layer_statContext):
        pass


    # Enter a parse tree produced by NNDLParser#con_stat.
    def enterCon_stat(self, ctx:NNDLParser.Con_statContext):
        pass

    # Exit a parse tree produced by NNDLParser#con_stat.
    def exitCon_stat(self, ctx:NNDLParser.Con_statContext):
        pass


    # Enter a parse tree produced by NNDLParser#neuron_selection.
    def enterNeuron_selection(self, ctx:NNDLParser.Neuron_selectionContext):
        pass

    # Exit a parse tree produced by NNDLParser#neuron_selection.
    def exitNeuron_selection(self, ctx:NNDLParser.Neuron_selectionContext):
        pass


    # Enter a parse tree produced by NNDLParser#logical_expr.
    def enterLogical_expr(self, ctx:NNDLParser.Logical_exprContext):
        pass

    # Exit a parse tree produced by NNDLParser#logical_expr.
    def exitLogical_expr(self, ctx:NNDLParser.Logical_exprContext):
        pass


    # Enter a parse tree produced by NNDLParser#log_pred_expr.
    def enterLog_pred_expr(self, ctx:NNDLParser.Log_pred_exprContext):
        pass

    # Exit a parse tree produced by NNDLParser#log_pred_expr.
    def exitLog_pred_expr(self, ctx:NNDLParser.Log_pred_exprContext):
        pass


    # Enter a parse tree produced by NNDLParser#class_expr.
    def enterClass_expr(self, ctx:NNDLParser.Class_exprContext):
        pass

    # Exit a parse tree produced by NNDLParser#class_expr.
    def exitClass_expr(self, ctx:NNDLParser.Class_exprContext):
        pass


    # Enter a parse tree produced by NNDLParser#predicate.
    def enterPredicate(self, ctx:NNDLParser.PredicateContext):
        pass

    # Exit a parse tree produced by NNDLParser#predicate.
    def exitPredicate(self, ctx:NNDLParser.PredicateContext):
        pass


    # Enter a parse tree produced by NNDLParser#math_expr.
    def enterMath_expr(self, ctx:NNDLParser.Math_exprContext):
        pass

    # Exit a parse tree produced by NNDLParser#math_expr.
    def exitMath_expr(self, ctx:NNDLParser.Math_exprContext):
        pass


