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
        node_map.insert({G.nodes_.at(i), n});
    }

    node_map[source]->dist_ = 0;
    make_heap(q.begin(), q.end(), Comp());

    while (!q.empty()) {
        DjikNode* n = q[0];
        std::pop_heap(q.begin(), q.end());
        q.pop_back();
        for (Edge* e : n->node_->edges_) {
            Node* neighbor;
            if (e->node_1_ == n->node_) {
                neighbor = e->node_2_;
            } else {
                neighbor = e->node_1_;
            }

            double alt_dist = (double) n->dist_ + ( (double) 1/ (double) (e->sr_coeff_));
            if (alt_dist < node_map[neighbor]->dist_) {
                node_map[neighbor]->dist_ = alt_dist;
                previous_[neighbor] = n->node_;
            }
        }

    }

    for (auto it = node_map.begin(); it != node_map.end(); ++it) {

        if (it->second->dist_ < 10000000) {
            distances_.insert({it->first, it->second->dist_});
        } else {
            distances_.insert({it->first, -1.0});
        }
        
        delete it->second;
    } 


    
}

double Dijkstra::GetDist(Node* node) {
    return distances_[node];
}

std::vector<std::string> Dijkstra::NodesPath(Node* node) {

    if (GetDist(node) < 0) {
        return std::vector<std::string>();
    }
    std::vector<std::string> out; 
    Node* curr = node;
    while (curr != source_) {


        out.insert(out.begin(), curr->ticker_);
        curr = previous_[curr];
    }

    out.insert(out.begin(), source_->ticker_);

    return out;
 
}