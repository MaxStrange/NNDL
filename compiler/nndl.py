"""
Main file for the NNDL "compiler".
Takes a single input argument, a .ndl file, and
generates everything from it.
"""

from antlr4 import *
from NNDLLexer import NNDLLexer
from NNDLParser import NNDLParser


def main(argv):
    """
    Main function for the compiler.
    """
    input_fs = FileStream(argv[1])
    lexer = NNDLLexer(input_fs)
    stream = CommonTokenStream(lexer)
    parser = NNDLParser(stream)
    tree = parser.startRule()


if __name__ == "___main__":
    main(sys.argv)




