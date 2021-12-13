#include "../include/CC.h"
#include <stack>

using std::stack;

vector<Node*> ConnectedComponents::DFSTraverse(Node* node, Map<Node*, bool> &traved_, vector<Node*> adjacent_nodes) {
    traved_.insert({node, true});
    adjacent_nodes.push_back(node->ticker_);
    for (Edge * edge : node->edges_) {
        Node* neighbor;
        if (edge->node_1_ != node) {
            neighbor = edge->node_1_;
        } else {
            neighbor = edge->node_2_;
        }
        if (traved_.find(neighbor) != traved_.end()) {
            DFSTraverse(neighbor, traved_, adjacent_nodes);
        }
    }
}

void ConnectedComponents::fillOrder(Node* node, Map<Node*, bool> &traved_, stack<int> &stack) {
    traved_.insert({node, true});
    for (Edge * edge : node->edges_) {
        Node* neighbor;
        if (edge->node_1_ != node) {
            neighbor = edge->node_1_;
        } else {
            neighbor = edge->node_2_;
        }
        if (traved_.find(neighbor) != traved_.end()) {
            DFSTraverse(neighbor, traved_, stack);
        }
    }
    stack.push(node);
}

ConnectedComponents::ConnectedComponents(Graph graph) {
    graph_ = graph;
    traved_ = map<Node*, bool>();
}

vector<vector<string>> ConnectedComponents::connectTheComponents() {
    stack<Node*> stack;
    traved_ = map<Node*, bool>();
    for (Node* node : graph.nodes) {
        if (map.find(node) != map.end()) {
            fillOrder(node, map, stack);
        }
    }

    traved_ = map<Node*, bool>();

    while(!stack.empty()) {
        Node* node = stack.top();
        stack.pop();
        vector<vector<Node*>> connected_components;
        if (map.find(node) != map.end()) {
            vector<Node*> component = DFSTraverse(node, traved_);
            connected_components.push_back(component);
        }
    }

    return connected_components;
}