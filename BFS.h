#include "Graph.h"
#include <queue>
#include <map>

class BFS {
    public:
        void traverse(Node* start);
    private:
        std::queue<Node*> q_;
        std::map<Node*, bool> traved_;
};