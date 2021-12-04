#pragma once 

namespace finalproject {
    
    class Node {
        Node(std::string ticker);
        std::string ticker_; 
        std::list<finalproject::Graph::Edge*> edges_;
    };
}