#include "Graph.h"
#include "BFS.h"
#include <iostream>
int main(int argc, char *argv[]) {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    // std::cout << ((G.nodes_[0])->ticker_) << std::endl;
    // std::cout << ((G.nodes_[1])->ticker_) << std::endl;
    // std::cout << ((G.nodes_[2])->ticker_) << std::endl;
    // std::cout << ((G.nodes_[3])->ticker_) << std::endl;
    G.LoadEdges("tests/test_data/test_edges.txt");
    // std::cout << ((G.nodes_[0])->edges_.front()->sr_coeff_) << std::endl;
    // std::cout << ((G.nodes_[0])->edges_.front()->node_2_->ticker_) << std::endl;
    // std::cout << ((G.nodes_[1])->edges_.front()->sr_coeff_) << std::endl;
    // std::cout << ((G.nodes_[1])->edges_.front()->node_2_->ticker_) << std::endl;
    std::cout<<"starting loop"<<std::endl;
    for (int i = 0; i < G.nodes_.size(); i++) {
        std::cout << ((G.nodes_[i])->ticker_) <<" i = " <<i<<std::endl;
        std::cout << ((G.nodes_[i])->edges_.front()->node_1_->ticker_) << " "<< ((G.nodes_[i])->edges_.front()->node_2_->ticker_)<< std::endl;
        std::cout << ((G.nodes_[i])->edges_.back()->node_1_->ticker_) << " "<< ((G.nodes_[i])->edges_.back()->node_2_->ticker_)<< std::endl;

    }
    // std::cout<<"starting bfs"<<std::endl;
    // BFS bfs;
    // std::vector<std::string> test = bfs.traverse(G.nodes_[0]);
    // std::vector<std::string> test1 = bfs.traverse(G.nodes_[4]);
    // for (std::string a : test) {
    //     std::cout<<a<<std::endl;
    // }
    return 0;
}