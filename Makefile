.PHONY: clean

SRCS=$(wildcard src/*.cpp)
OBJS=$(SRCS:src/%.cpp=$(DEST)/%.o)
DEPS=$(SRCS:src/%.cpp=$(DEST)/%.d)

CXX=g++
CXXFLAGS=-g -Wall -Wextra -std=c++11
INCFLAGS = -Iinclude/

LIBS = 
DEST=bin
COMPILE= $(CXX) $(CXXFLAGS) $(INCFLAGS) 
TARGET=app

all: clean dirs app

app: $(OBJS)
	$(COMPILE) $^ -o $(DEST)/$@ $(LIBS)

-include $(DEPS)

$(DEST)/%.o: src/%.cpp Makefile
	$(CXX) $(CXXFLAGS) $(INCFLAGS)  -MMD -MP -c $^ -o $@
	
dirs:
	mkdir -p $(DEST)

clean:
	rm -rf $(DEST) || :