#include "Graph.h"
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;

class ConnectedComponenets {
    public:
        vector<vector<string>> connectTheComponents();
        ConnectedComponents(Graph graph);
    private:
        void fillOrder(Node* node, map<Node*, bool> &traved_, stack<int> &stack);
        vector<string> DFSTraverse(Node* node, map<Node*, bool> &traved_, vector<Node*> adjacent_nodes);

        Graph graph_;
        map<Node*, bool> traved_;
}