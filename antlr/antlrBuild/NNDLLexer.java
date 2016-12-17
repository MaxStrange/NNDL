// Generated from NNDL.g4 by ANTLR 4.6
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class NNDLLexer extends Lexer {
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
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
		"T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
		"T__17", "T__18", "T__19", "T__20", "IMPORT", "NEURON_OPEN", "NEURON_END", 
		"CONNECT_OPEN", "CONNECT_END", "LAYER", "LAYER_ID", "MAT_DECL", "CONNECT", 
		"CLASS", "NEUR_VAR", "ID", "NUM", "LETTER", "DIGIT", "WS"
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


	public NNDLLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "NNDL.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2%\u00e9\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3"+
		"\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3\r\3\r\3"+
		"\16\3\16\3\16\3\17\3\17\3\17\3\20\3\20\3\20\3\21\3\21\3\21\3\22\3\22\3"+
		"\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3\27\3\27\3\27\3\27\3\27\3"+
		"\27\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31\3\31\3"+
		"\31\3\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3"+
		"\32\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3"+
		"\33\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3\34\3\35\3"+
		"\35\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3\37\3 \3 "+
		"\3 \3 \3 \5 \u00cd\n \3!\3!\3\"\3\"\3\"\3\"\7\"\u00d5\n\"\f\"\16\"\u00d8"+
		"\13\"\3#\6#\u00db\n#\r#\16#\u00dc\3$\3$\3%\3%\3&\6&\u00e4\n&\r&\16&\u00e5"+
		"\3&\3&\2\2\'\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16"+
		"\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34"+
		"\67\359\36;\37= ?!A\"C#E$G\2I\2K%\3\2\4\4\2C\\c|\5\2\13\13\16\16\"\"\u00ec"+
		"\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2"+
		"\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2"+
		"\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2"+
		"\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2"+
		"\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3"+
		"\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2K\3\2\2"+
		"\2\3M\3\2\2\2\5O\3\2\2\2\7Q\3\2\2\2\tS\3\2\2\2\13U\3\2\2\2\rW\3\2\2\2"+
		"\17Y\3\2\2\2\21[\3\2\2\2\23]\3\2\2\2\25_\3\2\2\2\27a\3\2\2\2\31d\3\2\2"+
		"\2\33f\3\2\2\2\35i\3\2\2\2\37l\3\2\2\2!o\3\2\2\2#r\3\2\2\2%t\3\2\2\2\'"+
		"v\3\2\2\2)x\3\2\2\2+z\3\2\2\2-|\3\2\2\2/\u0083\3\2\2\2\61\u008b\3\2\2"+
		"\2\63\u0097\3\2\2\2\65\u00a3\3\2\2\2\67\u00b3\3\2\2\29\u00b9\3\2\2\2;"+
		"\u00bb\3\2\2\2=\u00bf\3\2\2\2?\u00cc\3\2\2\2A\u00ce\3\2\2\2C\u00d0\3\2"+
		"\2\2E\u00da\3\2\2\2G\u00de\3\2\2\2I\u00e0\3\2\2\2K\u00e3\3\2\2\2MN\7<"+
		"\2\2N\4\3\2\2\2OP\7?\2\2P\6\3\2\2\2QR\7*\2\2R\b\3\2\2\2ST\7.\2\2T\n\3"+
		"\2\2\2UV\7+\2\2V\f\3\2\2\2WX\7}\2\2X\16\3\2\2\2YZ\7\177\2\2Z\20\3\2\2"+
		"\2[\\\7]\2\2\\\22\3\2\2\2]^\7_\2\2^\24\3\2\2\2_`\7>\2\2`\26\3\2\2\2ab"+
		"\7>\2\2bc\7?\2\2c\30\3\2\2\2de\7@\2\2e\32\3\2\2\2fg\7@\2\2gh\7?\2\2h\34"+
		"\3\2\2\2ij\7?\2\2jk\7?\2\2k\36\3\2\2\2lm\7(\2\2mn\7(\2\2n \3\2\2\2op\7"+
		"~\2\2pq\7~\2\2q\"\3\2\2\2rs\7,\2\2s$\3\2\2\2tu\7\61\2\2u&\3\2\2\2vw\7"+
		"\'\2\2w(\3\2\2\2xy\7-\2\2y*\3\2\2\2z{\7/\2\2{,\3\2\2\2|}\7k\2\2}~\7o\2"+
		"\2~\177\7r\2\2\177\u0080\7q\2\2\u0080\u0081\7t\2\2\u0081\u0082\7v\2\2"+
		"\u0082.\3\2\2\2\u0083\u0084\7p\2\2\u0084\u0085\7g\2\2\u0085\u0086\7w\2"+
		"\2\u0086\u0087\7t\2\2\u0087\u0088\7q\2\2\u0088\u0089\7p\2\2\u0089\u008a"+
		"\7u\2\2\u008a\60\3\2\2\2\u008b\u008c\7g\2\2\u008c\u008d\7p\2\2\u008d\u008e"+
		"\7f\2\2\u008e\u008f\3\2\2\2\u008f\u0090\7p\2\2\u0090\u0091\7g\2\2\u0091"+
		"\u0092\7w\2\2\u0092\u0093\7t\2\2\u0093\u0094\7q\2\2\u0094\u0095\7p\2\2"+
		"\u0095\u0096\7u\2\2\u0096\62\3\2\2\2\u0097\u0098\7e\2\2\u0098\u0099\7"+
		"q\2\2\u0099\u009a\7p\2\2\u009a\u009b\7p\2\2\u009b\u009c\7g\2\2\u009c\u009d"+
		"\7e\2\2\u009d\u009e\7v\2\2\u009e\u009f\7k\2\2\u009f\u00a0\7q\2\2\u00a0"+
		"\u00a1\7p\2\2\u00a1\u00a2\7u\2\2\u00a2\64\3\2\2\2\u00a3\u00a4\7g\2\2\u00a4"+
		"\u00a5\7p\2\2\u00a5\u00a6\7f\2\2\u00a6\u00a7\3\2\2\2\u00a7\u00a8\7e\2"+
		"\2\u00a8\u00a9\7q\2\2\u00a9\u00aa\7p\2\2\u00aa\u00ab\7p\2\2\u00ab\u00ac"+
		"\7g\2\2\u00ac\u00ad\7e\2\2\u00ad\u00ae\7v\2\2\u00ae\u00af\7k\2\2\u00af"+
		"\u00b0\7q\2\2\u00b0\u00b1\7p\2\2\u00b1\u00b2\7u\2\2\u00b2\66\3\2\2\2\u00b3"+
		"\u00b4\7n\2\2\u00b4\u00b5\7c\2\2\u00b5\u00b6\7{\2\2\u00b6\u00b7\7g\2\2"+
		"\u00b7\u00b8\7t\2\2\u00b88\3\2\2\2\u00b9\u00ba\5C\"\2\u00ba:\3\2\2\2\u00bb"+
		"\u00bc\5E#\2\u00bc\u00bd\7z\2\2\u00bd\u00be\5E#\2\u00be<\3\2\2\2\u00bf"+
		"\u00c0\7e\2\2\u00c0\u00c1\7q\2\2\u00c1\u00c2\7p\2\2\u00c2\u00c3\7p\2\2"+
		"\u00c3\u00c4\7g\2\2\u00c4\u00c5\7e\2\2\u00c5\u00c6\7v\2\2\u00c6>\3\2\2"+
		"\2\u00c7\u00cd\7,\2\2\u00c8\u00c9\5E#\2\u00c9\u00ca\7/\2\2\u00ca\u00cb"+
		"\5E#\2\u00cb\u00cd\3\2\2\2\u00cc\u00c7\3\2\2\2\u00cc\u00c8\3\2\2\2\u00cd"+
		"@\3\2\2\2\u00ce\u00cf\4kl\2\u00cfB\3\2\2\2\u00d0\u00d6\5G$\2\u00d1\u00d5"+
		"\5G$\2\u00d2\u00d5\5I%\2\u00d3\u00d5\7a\2\2\u00d4\u00d1\3\2\2\2\u00d4"+
		"\u00d2\3\2\2\2\u00d4\u00d3\3\2\2\2\u00d5\u00d8\3\2\2\2\u00d6\u00d4\3\2"+
		"\2\2\u00d6\u00d7\3\2\2\2\u00d7D\3\2\2\2\u00d8\u00d6\3\2\2\2\u00d9\u00db"+
		"\5I%\2\u00da\u00d9\3\2\2\2\u00db\u00dc\3\2\2\2\u00dc\u00da\3\2\2\2\u00dc"+
		"\u00dd\3\2\2\2\u00ddF\3\2\2\2\u00de\u00df\t\2\2\2\u00dfH\3\2\2\2\u00e0"+
		"\u00e1\4\62;\2\u00e1J\3\2\2\2\u00e2\u00e4\t\3\2\2\u00e3\u00e2\3\2\2\2"+
		"\u00e4\u00e5\3\2\2\2\u00e5\u00e3\3\2\2\2\u00e5\u00e6\3\2\2\2\u00e6\u00e7"+
		"\3\2\2\2\u00e7\u00e8\b&\2\2\u00e8L\3\2\2\2\b\2\u00cc\u00d4\u00d6\u00dc"+
		"\u00e5\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}