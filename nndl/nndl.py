"""
Main file for the NNDL compiler. Takes a single input argument, a
.ndl file, and generates everything from it.
"""

from compiler import compiler
import sys


def main(argv):
    """
    Main function for the nndl program.
    """
    compiler.compile(argv)


if __name__ == "__main__":
    main(sys.argv)



