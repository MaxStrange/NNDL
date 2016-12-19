"""
Main file for the NNDL compiler. Takes a single input argument, a
.ndl file, and generates everything from it.
"""

import compiler
import grammar
import sys


def main(argv):
    """
    Main function for the nndl program.
    """
    grammar.generate()
    compiler.compile(argv)


if __name__ == "__main__":
    main(sys.argv)



