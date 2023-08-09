# Example Project Makefile
# Example-Motion
#
# Creates an executable in this directory called Example-Motion

EXEC_NAME := "pyMotor.so"
INCLUDE_DIR := "./inc/inc-pub"
LIBS := -lsFoundation20 -lpthread
CC := g++
OPTIMIZATION := -O3 -g -fPIC
DEBUG_OPTIMIZATION := -O0 -g -fPIC
CXXFLAGS := -I$(INCLUDE_DIR) $(OPTIMIZATION)
DEBUG_CXXFLAGS := $(CXXFLAGS) -Wall -Wextra -pedantic -g3 $(DEBUG_OPTIMIZATION)

# Specify source files here
ALL_SRC_FILES := $(wildcard *.cpp)
ALL_OBJS := $(patsubst %.cpp,%.o,$(ALL_SRC_FILES))

# Default target
all: sMotor

# Generic rule to compile a CPP file into an object
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o "$@" $<

sMotor: $(ALL_OBJS)
    ifneq ($(RPATH),)
	$(CC) -w -shared -Wl,-soname,$(EXEC_NAME) -o $(EXEC_NAME) -L$(RPATH) -Wl,-rpath=$(RPATH)  $(ALL_OBJS) $(LIBS)
    else
	$(CC) -w -shared -Wl,-soname,$(EXEC_NAME) -o $(EXEC_NAME) $(ALL_OBJS) $(LIBS)
    endif

# Remove all object files
.PHONY: clean
clean:
	-find . -type f -name "*.o" -delete

# Sayonara. Viciously destroys all build artifacts, including the executable.
.PHONY: real_clean
real_clean: clean
	-rm $(EXEC_NAME)
	
# Run the program shorthand
.PHONY: run
run:
	./$(EXEC_NAME)
