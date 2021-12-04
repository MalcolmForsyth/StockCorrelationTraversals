#include "BFS.h"
#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>

void BFS::traverse(Node* start) {
    q_.push(start);
    traved_.insert({start, true});
    while (!q_.empty()) {
        Node* curr = q_.front();
        q_.pop();
        std::cout << curr->ticker_ << " | ";
        for (Edge * e : curr->edges_) {
            Node* neighbor;
            if (e->node_1_ != curr) {
                neighbor = e->node_1_;
            } else {
                neighbor = e->node_2_;
            }
            if (traved_.find(neighbor) != traved_.end()) {
                q_.push(neighbor);
                traved_.insert({neighbor, true});
            }
        }
    }
}