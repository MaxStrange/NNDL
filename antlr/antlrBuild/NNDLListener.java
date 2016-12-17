// Generated from NNDL.g4 by ANTLR 4.6
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link NNDLParser}.
 */
public interface NNDLListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link NNDLParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(NNDLParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(NNDLParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#import_stat}.
	 * @param ctx the parse tree
	 */
	void enterImport_stat(NNDLParser.Import_statContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#import_stat}.
	 * @param ctx the parse tree
	 */
	void exitImport_stat(NNDLParser.Import_statContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#neuron_stat}.
	 * @param ctx the parse tree
	 */
	void enterNeuron_stat(NNDLParser.Neuron_statContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#neuron_stat}.
	 * @param ctx the parse tree
	 */
	void exitNeuron_stat(NNDLParser.Neuron_statContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#connection_stat}.
	 * @param ctx the parse tree
	 */
	void enterConnection_stat(NNDLParser.Connection_statContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#connection_stat}.
	 * @param ctx the parse tree
	 */
	void exitConnection_stat(NNDLParser.Connection_statContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#layer_stat}.
	 * @param ctx the parse tree
	 */
	void enterLayer_stat(NNDLParser.Layer_statContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#layer_stat}.
	 * @param ctx the parse tree
	 */
	void exitLayer_stat(NNDLParser.Layer_statContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#con_stat}.
	 * @param ctx the parse tree
	 */
	void enterCon_stat(NNDLParser.Con_statContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#con_stat}.
	 * @param ctx the parse tree
	 */
	void exitCon_stat(NNDLParser.Con_statContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#neuron_selection}.
	 * @param ctx the parse tree
	 */
	void enterNeuron_selection(NNDLParser.Neuron_selectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#neuron_selection}.
	 * @param ctx the parse tree
	 */
	void exitNeuron_selection(NNDLParser.Neuron_selectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#logical_expr}.
	 * @param ctx the parse tree
	 */
	void enterLogical_expr(NNDLParser.Logical_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#logical_expr}.
	 * @param ctx the parse tree
	 */
	void exitLogical_expr(NNDLParser.Logical_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#log_pred_expr}.
	 * @param ctx the parse tree
	 */
	void enterLog_pred_expr(NNDLParser.Log_pred_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#log_pred_expr}.
	 * @param ctx the parse tree
	 */
	void exitLog_pred_expr(NNDLParser.Log_pred_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#class_expr}.
	 * @param ctx the parse tree
	 */
	void enterClass_expr(NNDLParser.Class_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#class_expr}.
	 * @param ctx the parse tree
	 */
	void exitClass_expr(NNDLParser.Class_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#predicate}.
	 * @param ctx the parse tree
	 */
	void enterPredicate(NNDLParser.PredicateContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#predicate}.
	 * @param ctx the parse tree
	 */
	void exitPredicate(NNDLParser.PredicateContext ctx);
	/**
	 * Enter a parse tree produced by {@link NNDLParser#math_expr}.
	 * @param ctx the parse tree
	 */
	void enterMath_expr(NNDLParser.Math_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NNDLParser#math_expr}.
	 * @param ctx the parse tree
	 */
	void exitMath_expr(NNDLParser.Math_exprContext ctx);
}