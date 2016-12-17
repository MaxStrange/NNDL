#! /usr/bin/env bash
echo "Removing everything in the build directory..."
rm build/*

echo "Running antlr4..."
java -jar /usr/local/lib/antlr-4.6-complete.jar NNDL.g4

echo "Compiling .java files..."
javac -classpath /usr/local/lib/antlr-4.6-complete.jar NNDL*.java

echo "Moving everything to the build directory..."
mv NNDL*.java build/
mv NNDL*.class build/
mv NNDL*.tokens build/

