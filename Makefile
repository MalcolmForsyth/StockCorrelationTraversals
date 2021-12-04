EXENAME = main 
TEST = test
OBJS = main.o Graph.o 

$(EXENAME): $(OBJS)
	g++ $(OBJS) -o main

Graph.o: Graph.cpp 
	g++ -c Graph.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	-rm -f *.o $(EXENAME)