#! /usr/bin/env bash
echo "Removing everything in the build directory..."
rm build/*

echo "Running antlr4..."
java -jar /usr/local/lib/antlr-4.6-complete.jar -Dlanguage=Python3 NNDL.g4

echo "Moving everything to the build directory..."
mv NNDL*.py build/
mv NNDL*.tokens build/
cp NNDL.g4 build/
cp examples/* build/

echo "Done. To grun, cd into build and run: 'grun NNDL prog <EXAMPLE> -gui'"
