EXENAME = main 
TEST = test
OBJS = main.o Graph.o Node.o Edge.o

$(EXENAME): $(OBJS)
	g++ $(OBJS) -o main

Node.o: Node.cpp
	g++ -c Node.cpp

Edge.o: Edge.cpp 
	g++ -c Edge.cpp

Graph.o: Graph.cpp 
	g++ -c Graph.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	-rm -f *.o $(EXENAME)