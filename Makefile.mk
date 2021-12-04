EXENAME = main 
TEST = test
OBJS = main.o Graph.o 

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
    $(LD) $^ $(LDFLAGS) -o $@

Graph.o: Graph.cpp 
    $(CXX) $< $(CXXFLAGS)

main.o: main.cpp
    $(CXX) $< $(CXXFLAGS)

clean:
    -rm -f *.o $(EXENAME)