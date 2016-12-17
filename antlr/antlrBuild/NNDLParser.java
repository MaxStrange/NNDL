// Generated from NNDL.g4 by ANTLR 4.6
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class NNDLParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.6", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, IMPORT=22, NEURON_OPEN=23, NEURON_END=24, 
		CONNECT_OPEN=25, CONNECT_END=26, LAYER=27, LAYER_ID=28, MAT_DECL=29, CONNECT=30, 
		CLASS=31, NEUR_VAR=32, ID=33, NUM=34, WS=35;
	public static final int
		RULE_prog = 0, RULE_import_stat = 1, RULE_neuron_stat = 2, RULE_connection_stat = 3, 
		RULE_layer_stat = 4, RULE_con_stat = 5, RULE_neuron_selection = 6, RULE_logical_expr = 7, 
		RULE_log_pred_expr = 8, RULE_class_expr = 9, RULE_predicate = 10, RULE_math_expr = 11;
	public static final String[] ruleNames = {
		"prog", "import_stat", "neuron_stat", "connection_stat", "layer_stat", 
		"con_stat", "neuron_selection", "logical_expr", "log_pred_expr", "class_expr", 
		"predicate", "math_expr"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "':'", "'='", "'('", "','", "')'", "'{'", "'}'", "'['", "']'", "'<'", 
		"'<='", "'>'", "'>='", "'=='", "'&&'", "'||'", "'*'", "'/'", "'%'", "'+'", 
		"'-'", "'import'", "'neurons'", null, "'connections'", null, "'layer'", 
		null, null, "'connect'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, null, null, "IMPORT", 
		"NEURON_OPEN", "NEURON_END", "CONNECT_OPEN", "CONNECT_END", "LAYER", "LAYER_ID", 
		"MAT_DECL", "CONNECT", "CLASS", "NEUR_VAR", "ID", "NUM", "WS"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "NNDL.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public NNDLParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ProgContext extends ParserRuleContext {
		public Neuron_statContext neuron_stat() {
			return getRuleContext(Neuron_statContext.class,0);
		}
		public Connection_statContext connection_stat() {
			return getRuleContext(Connection_statContext.class,0);
		}
		public TerminalNode EOF() { return getToken(NNDLParser.EOF, 0); }
		public List<Import_statContext> import_stat() {
			return getRuleContexts(Import_statContext.class);
		}
		public Import_statContext import_stat(int i) {
			return getRuleContext(Import_statContext.class,i);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterProg(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitProg(this);
		}
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(27);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==IMPORT) {
				{
				{
				setState(24);
				import_stat();
				}
				}
				setState(29);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(30);
			neuron_stat();
			setState(31);
			connection_stat();
			setState(32);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Import_statContext extends ParserRuleContext {
		public TerminalNode IMPORT() { return getToken(NNDLParser.IMPORT, 0); }
		public TerminalNode ID() { return getToken(NNDLParser.ID, 0); }
		public Import_statContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_import_stat; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterImport_stat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitImport_stat(this);
		}
	}

	public final Import_statContext import_stat() throws RecognitionException {
		Import_statContext _localctx = new Import_statContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_import_stat);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(34);
			match(IMPORT);
			setState(35);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Neuron_statContext extends ParserRuleContext {
		public TerminalNode NEURON_OPEN() { return getToken(NNDLParser.NEURON_OPEN, 0); }
		public TerminalNode NEURON_END() { return getToken(NNDLParser.NEURON_END, 0); }
		public List<Layer_statContext> layer_stat() {
			return getRuleContexts(Layer_statContext.class);
		}
		public Layer_statContext layer_stat(int i) {
			return getRuleContext(Layer_statContext.class,i);
		}
		public Neuron_statContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_neuron_stat; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterNeuron_stat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitNeuron_stat(this);
		}
	}

	public final Neuron_statContext neuron_stat() throws RecognitionException {
		Neuron_statContext _localctx = new Neuron_statContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_neuron_stat);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(37);
			match(NEURON_OPEN);
			setState(39); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(38);
				layer_stat();
				}
				}
				setState(41); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==LAYER );
			setState(43);
			match(NEURON_END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Connection_statContext extends ParserRuleContext {
		public TerminalNode CONNECT_OPEN() { return getToken(NNDLParser.CONNECT_OPEN, 0); }
		public TerminalNode CONNECT_END() { return getToken(NNDLParser.CONNECT_END, 0); }
		public List<Con_statContext> con_stat() {
			return getRuleContexts(Con_statContext.class);
		}
		public Con_statContext con_stat(int i) {
			return getRuleContext(Con_statContext.class,i);
		}
		public Connection_statContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_connection_stat; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterConnection_stat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitConnection_stat(this);
		}
	}

	public final Connection_statContext connection_stat() throws RecognitionException {
		Connection_statContext _localctx = new Connection_statContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_connection_stat);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(45);
			match(CONNECT_OPEN);
			setState(49);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2) {
				{
				{
				setState(46);
				con_stat();
				}
				}
				setState(51);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(52);
			match(CONNECT_END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Layer_statContext extends ParserRuleContext {
		public TerminalNode LAYER() { return getToken(NNDLParser.LAYER, 0); }
		public TerminalNode LAYER_ID() { return getToken(NNDLParser.LAYER_ID, 0); }
		public TerminalNode MAT_DECL() { return getToken(NNDLParser.MAT_DECL, 0); }
		public TerminalNode ID() { return getToken(NNDLParser.ID, 0); }
		public Layer_statContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_layer_stat; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterLayer_stat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitLayer_stat(this);
		}
	}

	public final Layer_statContext layer_stat() throws RecognitionException {
		Layer_statContext _localctx = new Layer_statContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_layer_stat);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(54);
			match(LAYER);
			setState(55);
			match(T__0);
			setState(56);
			match(LAYER_ID);
			setState(57);
			match(MAT_DECL);
			setState(58);
			match(T__1);
			setState(59);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Con_statContext extends ParserRuleContext {
		public List<Neuron_selectionContext> neuron_selection() {
			return getRuleContexts(Neuron_selectionContext.class);
		}
		public Neuron_selectionContext neuron_selection(int i) {
			return getRuleContext(Neuron_selectionContext.class,i);
		}
		public TerminalNode CONNECT() { return getToken(NNDLParser.CONNECT, 0); }
		public TerminalNode ID() { return getToken(NNDLParser.ID, 0); }
		public Con_statContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_con_stat; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterCon_stat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitCon_stat(this);
		}
	}

	public final Con_statContext con_stat() throws RecognitionException {
		Con_statContext _localctx = new Con_statContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_con_stat);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			neuron_selection();
			setState(62);
			match(T__0);
			setState(63);
			match(CONNECT);
			setState(64);
			neuron_selection();
			setState(65);
			match(T__1);
			setState(66);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Neuron_selectionContext extends ParserRuleContext {
		public List<Logical_exprContext> logical_expr() {
			return getRuleContexts(Logical_exprContext.class);
		}
		public Logical_exprContext logical_expr(int i) {
			return getRuleContext(Logical_exprContext.class,i);
		}
		public Neuron_selectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_neuron_selection; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterNeuron_selection(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitNeuron_selection(this);
		}
	}

	public final Neuron_selectionContext neuron_selection() throws RecognitionException {
		Neuron_selectionContext _localctx = new Neuron_selectionContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_neuron_selection);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			match(T__2);
			setState(69);
			logical_expr();
			setState(70);
			match(T__3);
			setState(71);
			logical_expr();
			setState(72);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Logical_exprContext extends ParserRuleContext {
		public Log_pred_exprContext log_pred_expr() {
			return getRuleContext(Log_pred_exprContext.class,0);
		}
		public Class_exprContext class_expr() {
			return getRuleContext(Class_exprContext.class,0);
		}
		public Math_exprContext math_expr() {
			return getRuleContext(Math_exprContext.class,0);
		}
		public Logical_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logical_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterLogical_expr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitLogical_expr(this);
		}
	}

	public final Logical_exprContext logical_expr() throws RecognitionException {
		Logical_exprContext _localctx = new Logical_exprContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_logical_expr);
		try {
			setState(77);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__5:
				enterOuterAlt(_localctx, 1);
				{
				setState(74);
				log_pred_expr();
				}
				break;
			case T__7:
				enterOuterAlt(_localctx, 2);
				{
				setState(75);
				class_expr();
				}
				break;
			case NEUR_VAR:
			case NUM:
				enterOuterAlt(_localctx, 3);
				{
				setState(76);
				math_expr(0);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Log_pred_exprContext extends ParserRuleContext {
		public PredicateContext predicate() {
			return getRuleContext(PredicateContext.class,0);
		}
		public Log_pred_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_log_pred_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterLog_pred_expr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitLog_pred_expr(this);
		}
	}

	public final Log_pred_exprContext log_pred_expr() throws RecognitionException {
		Log_pred_exprContext _localctx = new Log_pred_exprContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_log_pred_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(79);
			match(T__5);
			setState(80);
			predicate(0);
			setState(81);
			match(T__6);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Class_exprContext extends ParserRuleContext {
		public TerminalNode CLASS() { return getToken(NNDLParser.CLASS, 0); }
		public Class_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterClass_expr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitClass_expr(this);
		}
	}

	public final Class_exprContext class_expr() throws RecognitionException {
		Class_exprContext _localctx = new Class_exprContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_class_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(83);
			match(T__7);
			setState(84);
			match(CLASS);
			setState(85);
			match(T__8);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PredicateContext extends ParserRuleContext {
		public List<Math_exprContext> math_expr() {
			return getRuleContexts(Math_exprContext.class);
		}
		public Math_exprContext math_expr(int i) {
			return getRuleContext(Math_exprContext.class,i);
		}
		public List<PredicateContext> predicate() {
			return getRuleContexts(PredicateContext.class);
		}
		public PredicateContext predicate(int i) {
			return getRuleContext(PredicateContext.class,i);
		}
		public PredicateContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_predicate; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterPredicate(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitPredicate(this);
		}
	}

	public final PredicateContext predicate() throws RecognitionException {
		return predicate(0);
	}

	private PredicateContext predicate(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		PredicateContext _localctx = new PredicateContext(_ctx, _parentState);
		PredicateContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_predicate, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(88);
			math_expr(0);
			setState(89);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__9) | (1L << T__10) | (1L << T__11) | (1L << T__12) | (1L << T__13))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(90);
			math_expr(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(97);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new PredicateContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_predicate);
					setState(92);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(93);
					_la = _input.LA(1);
					if ( !(_la==T__14 || _la==T__15) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(94);
					predicate(2);
					}
					} 
				}
				setState(99);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Math_exprContext extends ParserRuleContext {
		public TerminalNode NEUR_VAR() { return getToken(NNDLParser.NEUR_VAR, 0); }
		public TerminalNode NUM() { return getToken(NNDLParser.NUM, 0); }
		public List<Math_exprContext> math_expr() {
			return getRuleContexts(Math_exprContext.class);
		}
		public Math_exprContext math_expr(int i) {
			return getRuleContext(Math_exprContext.class,i);
		}
		public Math_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_math_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).enterMath_expr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof NNDLListener ) ((NNDLListener)listener).exitMath_expr(this);
		}
	}

	public final Math_exprContext math_expr() throws RecognitionException {
		return math_expr(0);
	}

	private Math_exprContext math_expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Math_exprContext _localctx = new Math_exprContext(_ctx, _parentState);
		Math_exprContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_math_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(103);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NEUR_VAR:
				{
				setState(101);
				match(NEUR_VAR);
				}
				break;
			case NUM:
				{
				setState(102);
				match(NUM);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(113);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(111);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new Math_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_math_expr);
						setState(105);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(106);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__16) | (1L << T__17) | (1L << T__18))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(107);
						math_expr(5);
						}
						break;
					case 2:
						{
						_localctx = new Math_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_math_expr);
						setState(108);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(109);
						_la = _input.LA(1);
						if ( !(_la==T__19 || _la==T__20) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(110);
						math_expr(4);
						}
						break;
					}
					} 
				}
				setState(115);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 10:
			return predicate_sempred((PredicateContext)_localctx, predIndex);
		case 11:
			return math_expr_sempred((Math_exprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean predicate_sempred(PredicateContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean math_expr_sempred(Math_exprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 4);
		case 2:
			return precpred(_ctx, 3);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3%w\4\2\t\2\4\3\t\3"+
		"\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4\f"+
		"\t\f\4\r\t\r\3\2\7\2\34\n\2\f\2\16\2\37\13\2\3\2\3\2\3\2\3\2\3\3\3\3\3"+
		"\3\3\4\3\4\6\4*\n\4\r\4\16\4+\3\4\3\4\3\5\3\5\7\5\62\n\5\f\5\16\5\65\13"+
		"\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\5\tP\n\t\3\n\3\n\3\n\3\n\3\13\3\13\3"+
		"\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\7\fb\n\f\f\f\16\fe\13\f\3\r\3"+
		"\r\3\r\5\rj\n\r\3\r\3\r\3\r\3\r\3\r\3\r\7\rr\n\r\f\r\16\ru\13\r\3\r\2"+
		"\4\26\30\16\2\4\6\b\n\f\16\20\22\24\26\30\2\6\3\2\f\20\3\2\21\22\3\2\23"+
		"\25\3\2\26\27s\2\35\3\2\2\2\4$\3\2\2\2\6\'\3\2\2\2\b/\3\2\2\2\n8\3\2\2"+
		"\2\f?\3\2\2\2\16F\3\2\2\2\20O\3\2\2\2\22Q\3\2\2\2\24U\3\2\2\2\26Y\3\2"+
		"\2\2\30i\3\2\2\2\32\34\5\4\3\2\33\32\3\2\2\2\34\37\3\2\2\2\35\33\3\2\2"+
		"\2\35\36\3\2\2\2\36 \3\2\2\2\37\35\3\2\2\2 !\5\6\4\2!\"\5\b\5\2\"#\7\2"+
		"\2\3#\3\3\2\2\2$%\7\30\2\2%&\7#\2\2&\5\3\2\2\2\')\7\31\2\2(*\5\n\6\2)"+
		"(\3\2\2\2*+\3\2\2\2+)\3\2\2\2+,\3\2\2\2,-\3\2\2\2-.\7\32\2\2.\7\3\2\2"+
		"\2/\63\7\33\2\2\60\62\5\f\7\2\61\60\3\2\2\2\62\65\3\2\2\2\63\61\3\2\2"+
		"\2\63\64\3\2\2\2\64\66\3\2\2\2\65\63\3\2\2\2\66\67\7\34\2\2\67\t\3\2\2"+
		"\289\7\35\2\29:\7\3\2\2:;\7\36\2\2;<\7\37\2\2<=\7\4\2\2=>\7#\2\2>\13\3"+
		"\2\2\2?@\5\16\b\2@A\7\3\2\2AB\7 \2\2BC\5\16\b\2CD\7\4\2\2DE\7#\2\2E\r"+
		"\3\2\2\2FG\7\5\2\2GH\5\20\t\2HI\7\6\2\2IJ\5\20\t\2JK\7\7\2\2K\17\3\2\2"+
		"\2LP\5\22\n\2MP\5\24\13\2NP\5\30\r\2OL\3\2\2\2OM\3\2\2\2ON\3\2\2\2P\21"+
		"\3\2\2\2QR\7\b\2\2RS\5\26\f\2ST\7\t\2\2T\23\3\2\2\2UV\7\n\2\2VW\7!\2\2"+
		"WX\7\13\2\2X\25\3\2\2\2YZ\b\f\1\2Z[\5\30\r\2[\\\t\2\2\2\\]\5\30\r\2]c"+
		"\3\2\2\2^_\f\3\2\2_`\t\3\2\2`b\5\26\f\4a^\3\2\2\2be\3\2\2\2ca\3\2\2\2"+
		"cd\3\2\2\2d\27\3\2\2\2ec\3\2\2\2fg\b\r\1\2gj\7\"\2\2hj\7$\2\2if\3\2\2"+
		"\2ih\3\2\2\2js\3\2\2\2kl\f\6\2\2lm\t\4\2\2mr\5\30\r\7no\f\5\2\2op\t\5"+
		"\2\2pr\5\30\r\6qk\3\2\2\2qn\3\2\2\2ru\3\2\2\2sq\3\2\2\2st\3\2\2\2t\31"+
		"\3\2\2\2us\3\2\2\2\n\35+\63Ociqs";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}