
EXENAME = main 
TEST = test
OBJS = main.o Graph.o Node.o Edge.o BFS.o
TEST_OBJS = test.o catchmain.o Graph.o Node.o Edge.o BFS.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm



$(EXENAME): $(OBJS)
	g++ $(OBJS) -o main

$(TEST): $(TEST_OBJS)
	g++ $(TEST_OBJS) -o test

BFS.o: BFS.cpp
	g++ -c -std=c++11 BFS.cpp

Node.o: Node.cpp
	g++ -c -std=c++11 Node.cpp

Edge.o: Edge.cpp 
	g++ -c -std=c++11 Edge.cpp

Graph.o: Graph.cpp 
	g++ -std=c++11 -c Graph.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

test.o: tests/test.cpp
	g++ -std=c++11 -c tests/test.cpp

catchmain.o: cs225/catch/catchmain.cpp cs225/catch/catch.hpp
	g++ -std=c++11 -c cs225/catch/catchmain.cpp

dummy.o : dummy.cpp
	$(CXX) $(CXXFLAGS) dummy.cpp



clean:
	-rm -f *.o $(EXENAME)
	-rm -f *.o $(TEST)
