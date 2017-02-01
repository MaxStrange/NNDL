# NNDL
Neural Network Description Language

This is a quick little neural network description language I made. It writes DOT files and
even produces C++ code that can be used with a simulator I wrote that's included in this repo.
It's mostly a proof of concept, and some of the features are not fully implemented.

The idea was to create a very simple language that could be used to describe (almost) any arbitrary neural network (even spiking ones, rate-based ones, and deep ones). The language is mostly complete, and uses an ANTLR back-end with a python runtime to do the compilation.

## Quickstart

### Install Dependencies:
First, you must install the dependencies.

- The compiler is written in Python3, so you will need Python3
- This is only tested on Unix systems, but I don't see any reason why it couldn't be made to work
on Windows without too much fighting with it.
- You will need one package from pip that I am aware of: `pip3 install antlr4-python3-runtime`
- You will need graphviz to compile the DOT file into a .png. On Windows, you can download it from whatever website is currently hosting it - just search for 'download graphviz'. For OSX, you will want to brew install it, and for Linux, you can apt-get it.

### XOR
Now that everything is installed. Let's make sure that it works. navigate to the nndl directory and run `python3 nndl.py ../examples/xor.ndl ../simulator/src`

This should spew out a bit of console stuff and then tell you that it has done some helpful things. Yay. Specifically, it should have generated a few files:
- xor.dot
- xor.png

Both of these files can be found in the same directory that you are currently in (NNDL/nndl). It also created a couple of C++ files to be used in the simulator framework:
- xor_autogen.cpp
- xor_autogen.h

### Simulator
If you want to run the simulator on this beautiful network, you can. From here on out, things are a little less nice than they have been; never got around to really making the simulator shine. But it works - at least on simple networks like this - and could easily be used in the future by some entrepeneurial soul that is looking for a good school project or something.

Go into the NNDL/simulator/src directory. Edit the config.h file. Change the #defines at the top to be false for the examples that aren't the XOR example and true for that one. Now go back up one directory to the NNDL/simulator dir and type `make` into the console and let it do its thing.

Once the Makefile has finished compiling, you can `./simulator` to have it run the XOR example. If you have it run enough batches (configurable in the config.h file and on the order of 100000), you will find that the accuracy converges on 1 (that's 100%). Hurray science.

I'm afraid that's where the fun ends for now (and likely forever). I never got around to having it save the model that you have trained, or spout out stats about it after the training is complete. I also never validated that it could really run the MNIST dataset, but then, I also never parallelized it either. It's unlikely that I will ever get around to doing any of that, but it is still pretty neat if I do say so myself.

## Grammar
I find it unlikely that I will ever actually write a description of the grammar, but it is very simple and you can look at the examples to figure out most of what it is capable of. If you know ANTLR, you can look at the ANTLR grammar file. The one thing that's a little odd is that it REQUIRES that you put those two import statements at the top of the page... or at least I think it does. Can't remember... Anyway, those were going to be so that you could swap out neuron/synapse models and even have several different ones in the same network.
