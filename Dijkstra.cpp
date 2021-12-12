#include "Dijkstra.h"
#include <float.h>
#include <queue>
#include <algorithm>

void Dijkstra::ComputeDistances(Graph& G, Node* source) {
    std::vector<DjikNode> q;
    std::map<Node*, DjikNode> node_map;
    for (int i = 0; i < G.nodes_.size(); ++i) {
        previous_.insert({G.nodes_.at(i), NULL});
        DjikNode n; 
        n.node_ = G.nodes_.at(i);
        n.dist_ = DBL_MAX;
        n.visited_ = false;
        q.push_back(n);
        node_map.insert({G.nodes_.at(i), n});
    }

    node_map[source].dist_ = 0;
    make_heap(q.begin(), q.end(), Comp());
    while (!q.empty()) {
        DjikNode n = q[0];
        std::pop_heap(q.begin(), q.end());
        q.pop_back();
        for (Edge* e : n.node_->edges_) {
            Node* neighbor;
            if (e->node_1_ == n.node_) {
                neighbor = e->node_2_;
            } else {
                neighbor = e->node_1_;
            }

            int alt_dist = node_map[neighbor].dist_ + 1/(e->sr_coeff_);
            if (alt_dist < node_map[neighbor].dist_) {
                node_map[neighbor].dist_ = alt_dist;
                previous_[neighbor] = n.node_;
            }
        }

    }
    
}