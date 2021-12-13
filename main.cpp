#include "include/Graph.h"
#include "include/BFS.h"
#include "include/Dijkstra.h"
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
        if (start == NULL) {
            std::cout<<"Not a valid ticker, please try again"<<std::endl;
            return 0;
        }
        std::string destination;
        std::cout<<"Type the ticker of the stock you would like to run Dijstra's to"<<std::endl;
        std::cin>>destination;
        Node * end = G.getNode(destination);
        if (end == NULL) {
            std::cout<<"Not a valid ticker, please try again"<<std::endl;
            return 0;
        }
        dijkstra.ComputeDistances(G, start);
        std::vector<std::string> v;
        v = dijkstra.NodesPath(end);
        //std::cout<<G.nodes_[238]->ticker_<<std::endl;
        double distance = dijkstra.GetDist(end);
        if (v.size() == 0) {
            std::cout<<"There is no path between these two stocks"<<std::endl;
            return 0;
        }
        for (std::string output : v) {
            std::cout<<"Printing path"<<std::endl;
            std::cout<<output<<" ";
        }
        std::cout<<"This path has a disatance of "<<distance<<std::endl;
    }
    //if used decides to use Connected components
    if (algorithm == "C") {
        std::cout<<"WIP"<<std::endl;
    }
    
    return 0;
}