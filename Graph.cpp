#include "Graph.h"


void Graph::AddNode(std::string ticker) {
    Node* n = new Node(ticker);
    size_t index = nodes_.size();
    nodes_.at(index) = n;   
    ticker_to_node_.insert(std::pair<std::string, Node*>(ticker, n));
}

Node::Node(std::string ticker) {
    ticker_ = ticker;
}

Edge::Edge(Node* node_1, Node* node_2, double sr_coeff) {
    node_1_ = node_1;
    node_2_ = node_2;
    sr_coeff_ = sr_coeff;
}

void Graph::AddEdge(Node* node_1, Node* node_2, double sr_coeff) {
    Edge* e = new Edge(node_1, node_2, sr_coeff);
    node_1.edges_.push_front(e);
    node_2.edges_.push_front(e);
}


void Graph::LoadNodes(std::string filepath) {
  std::string line;
  ifstream myfile (filepath);
  if (myfile.is_open())
  {
    while (getline(myfile,line) )
    {
      AddNode(line);
    }
    myfile.close();
  }

}
