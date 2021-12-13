#include "Graph.h"
#include "BFS.h"
#include "Dijkstra.h"
#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
    Graph G;
    G.LoadNodes("data_processing/datasets/s&p_500.txt");
    G.LoadEdges("data_processing/datasets/spearman_coefficients.csv");
    BFS bfs;
    Dijkstra dijkstra;

    std::string algorithm;
    std::string ticker;
    std::cout<<"Type the letter of the program you would like to run"<<std::endl;
    std::cout<<"Breadth First Search (A)"<<std::endl;
    std::cout<<"Dijkstras (B)"<<std::endl;
    std::cout<<"Connected Components (C)"<<std::endl;
    std::cin>>algorithm;
    if (!(algorithm == "A" || algorithm == "B" || algorithm == "C")) {
        std::cout<<"Not a valid algorithm, please try again"<<std::endl;
        return 0;
    }
    std::cout<<"Please enter a stock ticker you would like to run the algorithm on"<<std::endl;
    std::cin>>ticker;

    Node * start = G.getNode(ticker);
    //if user decides to use BFS
    if (algorithm == "A") {
        if (start == NULL) {
            std::cout<<"Not a valid ticker, please try again"<<std::endl;
            return 0;
        }
        std::cout<<"All stocks connected to "<<ticker<<std::endl;
        std::vector<std::string> v;
        v = bfs.traverse(start);
        for (std::string output : v) {
            std::cout<<output<<" ";
        }
        std::cout<<" "<<std::endl;
    }
    //if user decides to use Dijstras
    if (algorithm == "B") {
        std::cout<<"WIP"<<std::endl;
    }
    //if used decides to use Connected components
    if (algorithm == "C") {
        std::cout<<"WIP"<<std::endl;
    }
    
    return 0;
}