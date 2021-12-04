#pragma once

namespace finalproject {

class Edge {
    public:
      Edge(Node* node_1, Node* node_2, double sr_coeff);
      double sr_coeff_; 
      Node* node_1_; 
      Node* node_2_;
};

}