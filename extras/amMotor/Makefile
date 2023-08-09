# Example Project Makefile
# Example-MultiThreaded
#
# Creates an executable in this directory called Example-MultiThreaded

EXEC_NAME := "libamMotor.so"
TEST_NAME := "amMotorTest"
INCLUDE_DIR := "./inc/inc-pub"
LIBS := 
CC := g++
OPTIMIZATION := -O3 -g -fPIC
DEBUG_OPTIMIZATION := -O0 -g -fPIC 
CXXFLAGS := -I$(INCLUDE_DIR) $(OPTIMIZATION)
DEBUG_CXXFLAGS := $(CXXFLAGS) -Wall -Wextra -pedantic -g3 $(DEBUG_OPTIMIZATION)

# Specify source files here
ALL_SRC_FILES := $(wildcard *.cpp)
ALL_OBJS := $(patsubst %.cpp,%.o,$(ALL_SRC_FILES))

# Default target
all: amMotor

# Generic rule to compile a CPP file into an object
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o "$@" $<

lib: $(ALL_OBJS)
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
	-rm $(TEST_NAME)
	
amMotor: $(ALL_OBJS)
    ifneq ($(RPATH),)
	$(CC) -O2 -g -L$(RPATH) -Wl,-rpath=$(RPATH) -o $(TEST_NAME) $(ALL_OBJS) $(LIBS)
    else
	$(CC) -O2 -g -o $(TEST_NAME) $(ALL_OBJS) $(LIBS)
    endif
	
run:
	make
	./$(TEST_NAME)
