#include "Graph.h"
#include <iostream>
int main(int argc, char *argv[]) {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    std::cout << ((G.nodes_[0])->ticker_) << std::endl;
    std::cout << ((G.nodes_[1])->ticker_) << std::endl;
    std::cout << ((G.nodes_[2])->ticker_) << std::endl;
    std::cout << ((G.nodes_[3])->ticker_) << std::endl;
}