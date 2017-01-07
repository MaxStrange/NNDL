"""
The main compiler file for the nndl compiler.
"""

import antlr4
import compiler.dotgen as dotgen
import compiler.cppwriter as cppwriter
from grammar import NNDLLexer
from grammar import NNDLParser
import os

def compile(file_to_compile, src_dir):
    """
    Compiles the given .ndl file. First checks to make sure it is a .ndl
    file. If it isn't, it throws a ValueError.
    """
    if file_to_compile.endswith(".ndl"):
        print("Compiling %s..." % file_to_compile)
        if os.path.isfile(file_to_compile):
            _compile_file(file_to_compile, src_dir)
        else:
            raise IOError("File %s does not exist or is not a file." %\
                    file_to_compile)
    else:
        raise ValueError("The nndl compiler only accepts .ndl files.")

def _compile_file(file_to_compile, src_dir):
    """
    Compiles the given file, which should actually be a path to a file.
    """
    output_file_name = os.path.splitext(file_to_compile)[0]
    # Now we have output_file_name = "path/to/file" without the .ndl
    # but we want "file" not "path/to/file", so:
    output_file_name = output_file_name.split(os.path.sep)[-1]

    input = antlr4.FileStream(file_to_compile)
    lexer = NNDLLexer.NNDLLexer(input)
    stream = antlr4.CommonTokenStream(lexer)
    parser = NNDLParser.NNDLParser(stream)
    tree = parser.prog()

    # Walk the tree and generate the dot file
    dg = dotgen.DotGenerator(file_to_compile, output_file_name + ".dot")
    walker = antlr4.ParseTreeWalker()
    walker.walk(dg, tree)

    # Use the dotgenerator's network that it figured out from the nndl file
    # to generate the cpp file
    nw = dg._network
    cppwriter.write_file(nw, output_file_name, src_dir)














