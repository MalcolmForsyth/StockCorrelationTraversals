#pragma once 
#include "Graph.h"
#include <map>

class Dijkstra {
    public: 
        void ComputeDistances(Graph& G, Node* source);
        std::map<Node*, double> GetDistances();
        struct DjikNode {
            Node* node_;
            double dist_; 
            bool visited_;

            bool operator <(const DjikNode& d) {
                return dist_ > d.dist_;
            }

        };
        struct Comp { 
            bool operator()(const DjikNode& a,const DjikNode& b) const { 
                return a.dist_ > b.dist_;
            }    
        }; 

    private: 
        std::map<Node*, Node*> previous_;  
        std::map<Node*, double> distances_;  
};