#pragma once 

#include <string>
#include <list>

namespace finalproject {
    class Graph {
        public:

            class Node {
                Node(std::string ticker);
                std::string stock_name_; 
                std::list<Edge*> edges_;
            }

            class Edge {
                public:
                    Edge(Node* node_1, Node* node_2, double sr_coeff)
                    double sr_coeff_; 
                    Node* node_1_; 
                    Node* node_2_;
            }


        void AddNode(std::string ticker); 
        void AddEdge(Node* node_1, Node* node_2, double sr_coeff);    

        private: 
        std::map<std::string, int> ticker_to_index_
    }
}