EXENAME = main 
TEST = test
OBJS = main.o Graph.o Node.o Edge.o BFS.o

$(EXENAME): $(OBJS)
	g++ $(OBJS) -o main

BFS.o: BFS.cpp
	g++ -c -std=c+11 BFS.cpp

Node.o: Node.cpp
	g++ -c -std=c++11 Node.cpp

Edge.o: Edge.cpp 
	g++ -c -std=c++11 Edge.cpp

Graph.o: Graph.cpp 
	g++ -std=c++11 -c Graph.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	-rm -f *.o $(EXENAME)