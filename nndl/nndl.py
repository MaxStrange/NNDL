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
    if len(argv) < 2:
        print("USAGE: python3 %s <.ndl files>" % argv[0])
        exit(1)
    else:
        files_to_compile = argv[1:]
        for f in files_to_compile:
            compiler.compile(f)


if __name__ == "__main__":
    main(sys.argv)



