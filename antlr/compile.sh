#! /usr/bin/env bash
java -jar /usr/local/lib/antlr-4.6-complete.jar NNDL.g4 -o ./antlrBuild
javac -d ./antlrBuild -classpath /usr/local/lib/antlr-4.6-complete.jar -classpath ./antlrBuild ./antlrBuild/*.java

