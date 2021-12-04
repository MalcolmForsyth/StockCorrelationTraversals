#include "Graph.h"


void Graph::AddNode(std::string ticker) {
    Node* n = new Node(ticker);
    nodes_.push_back(n);
}

Node::Node(std::string ticker) {
    ticker_ = ticker;
}
