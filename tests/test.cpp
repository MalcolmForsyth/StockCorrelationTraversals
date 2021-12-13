#include "../cs225/catch/catch.hpp"
#include "../Graph.h"
#include "../Edge.h"
#include "../Node.h"
#include "../BFS.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

TEST_CASE("pass", "[weight=10][valgrind]") {
    REQUIRE(1 == 1);
}

// TEST_CASE("fail", "[weight=20][valgrind]") {
//     REQUIRE(0 == 1);
// }

TEST_CASE("Load Nodes", "[weight=20][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    REQUIRE(((G.nodes_[0])->ticker_) == "AAPL");
    REQUIRE(((G.nodes_[1])->ticker_) == "A");
    REQUIRE(((G.nodes_[2])->ticker_) == "B");
    REQUIRE(((G.nodes_[3])->ticker_) == "MRNA");
}

TEST_CASE("Load Edges", "[weight=20][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    REQUIRE(((G.nodes_[0])->edges_.front()->sr_coeff_) == 0.9);
    REQUIRE(((G.nodes_[0])->edges_.front()->node_2_->ticker_) == "AAPL");
    REQUIRE(((G.nodes_[0])->edges_.front()->node_1_->ticker_) == "MRNA");
}

TEST_CASE("BFS standard example", "[weight=10][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    BFS bfs;
    std::vector<std::string> test = bfs.traverse(G.nodes_[0]);
    std::vector<std::string> compare = {"AAPL", "MRNA", "A", "B"};
    REQUIRE(test == compare);
}

TEST_CASE("Load Edges does not create certain edges below threshold", "[weight=20][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges_under.txt");
    BFS bfs;
    std::vector<std::string> test = bfs.traverse(G.nodes_[0]);
    std::vector<std::string> compare = {"AAPL"};
    REQUIRE(test == compare);
}



