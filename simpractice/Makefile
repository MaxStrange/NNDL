Q ?= @

appname := simulator

rootdir               := $(shell pwd)
BUILDDIR              := $(rootdir)/build
OBJDIR                := $(BUILDDIR)/obj
srcdir                := $(rootdir)/src

src                   := $(wildcard $(srcdir)/*.cpp)
src                   += $(wildcard $(srcdir)/*.cu)

CXX                   := clang++

RM                    := rm -f
MKDIR                 := mkdir -p
SED                   := sed

inc_path              := $(srcdir)

WARNING               += -Wall
WARNING               += -Werror
WARNING               += -Wfatal-errors
WARNING               += -Wno-unused-local-typedefs
WARNING               += -Wno-unused-variable
WARNING               += -Wno-unused-function

OPTIMIZATION          ?= -O1 -ggdb3

CXXFLAGS              += $(WARNING)
CXXFLAGS              += $(OPTIMIZATION)
CXXFLAGS              += -std=c++11

CPPFLAGS              += $(addprefix -I, $(inc_path))

obj                   := $(addprefix $(OBJDIR)/, $(notdir $(src)))
obj                   := $(obj:.cpp=.o)
obj                   := $(obj:.cu=.o)

empty :=
space := $(empty) $(empty)
vpath %.cpp $(subst $(space),:,$(sort $(dir $(src))))
vpath %.cu $(subst $(space),:,$(sort $(dir $(src))))
vpath %.h $(subst $(space),:,$(inc_path))
vpath %.o $(OBJDIR)

.PHONY: all
all: $(appname)

$(appname): $(obj)
	$(Q) $(CXX) $^ $(CPPFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILDDIR)

$(BUILDDIR):
	$(Q) $(MKDIR) $@

$(OBJDIR):
	$(Q) $(MKDIR) $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@echo "$(CXX) $(notdir $<)"
	$(Q) $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@








