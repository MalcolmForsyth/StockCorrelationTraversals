#include "Dijkstra.h"
#include <float.h>
#include <queue>
#include <algorithm>
#include <iostream>

void Dijkstra::ComputeDistances(Graph& G, Node* source) {
    source_ = source;
    std::vector<DjikNode*> q;
    std::map<Node*, DjikNode*> node_map;
    for (int i = 0; i < G.nodes_.size(); ++i) {
        previous_.insert({G.nodes_.at(i), NULL});
        DjikNode* n = new DjikNode(); 
        n->node_ = G.nodes_.at(i);
        n->dist_ = DBL_MAX - 1000.0;
        n->visited_ = false;
        q.push_back(n);
        std::cout << n << std::endl;
        node_map.insert({G.nodes_.at(i), n});
    }

    node_map[source]->dist_ = 0;
    make_heap(q.begin(), q.end(), Comp());
    for (size_t i = 0; i < q.size(); ++i) {
        std::cout << q.at(i)->dist_ << std::endl;
        std::cout << node_map[q.at(i)->node_]->dist_ << std::endl;
    }

    while (!q.empty()) {
        std::cout << q.size() << std::endl;
        DjikNode* n = q[0];
        std::pop_heap(q.begin(), q.end());
        q.pop_back();
        std::cout << n->dist_ << std::endl;
        for (Edge* e : n->node_->edges_) {
            Node* neighbor;
            if (e->node_1_ == n->node_) {
                neighbor = e->node_2_;
            } else {
                neighbor = e->node_1_;
            }

            int alt_dist = n->dist_ + 1/(e->sr_coeff_);
            if (alt_dist < node_map[neighbor]->dist_) {
                node_map[neighbor]->dist_ = alt_dist;
                previous_[neighbor] = n->node_;
            }
        }

    }

    for (auto it = node_map.begin(); it != node_map.end(); ++it) {
        distances_.insert({it->first, it->second->dist_});
        delete it->second;
    } 


    
}

double Dijkstra::GetDist(Node* node) {
    return distances_[node];
}

std::vector<std::string> Dijkstra::NodesPath(Node* node) {
    std::vector<std::string> out; 
    while (previous_[node] != source_) {
        out.insert(out.begin(), previous_[node]->ticker_);
        node = previous_[node];
    }

    out.insert(out.begin(), source_->ticker_);


     
}