appname := simulator

CXX := clang++
CXXFLAGS := -std=c++11

srcfiles := $(shell find . -name "*.cpp")
srcfiles += $(shell find . -name "*.cc")
srcfiles += $(shell find . -name ".cu")

objects := $(patsubst %.cpp, %.o, $(srcfiles))
objects := $(patsubst %.cc, %.o, $(objects))
objects := $(patsubst %.cu, %.o, $(objects))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend

clean:
	rm -f $(objects)

include .depend




