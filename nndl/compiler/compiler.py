"""
The main compiler file for the nndl compiler.
"""

import antlr4
from grammar import NNDLLexer
from grammar import NNDLParser
import os

def compile(file_to_compile):
    """
    Compiles the given .ndl file. First checks to make sure it is a .ndl
    file. If it isn't, it throws a ValueError.
    """
    if file_to_compile.endswith(".ndl"):
        print("Compiling %s..." % file_to_compile)
        if os.path.isfile(file_to_compile):
            _compile_file(file_to_compile)
        else:
            raise IOError("File %s does not exist or is not a file." %\
                    file_to_compile)
    else:
        raise ValueError("The nndl compiler only accepts .ndl files.")

def _compile_file(file_to_compile):
    """
    Compiles the given file, which should actually be a path to a file.
    """
    input = antlr4.FileStream(file_to_compile)
    lexer = NNDLLexer.NNDLLexer(input)
    stream = antlr4.CommonTokenStream(lexer)
    parser = NNDLParser.NNDLParser(stream)
    tree = parser.prog()














