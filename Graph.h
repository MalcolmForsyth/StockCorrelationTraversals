#pragma once 

#include <string>
#include <list>
#include <map>
#include "Edge.h"
#include "Node.h"

namespace finalproject {
    class Graph {
        public:

        void AddNode(std::string ticker); 
        void AddEdge(Node* node_1, Node* node_2, double sr_coeff);    

        private: 
        std::vector<Node*> nodes_;
        void LoadNodes(std::string filepath);
        void LoadEdges(std::string filepath);
        std::map<std::string, Node*> ticker_to_node_;
    };
}