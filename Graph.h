#pragma once
#include <iostream>
#include "Node.h"

class Graph
{
private:
    std::vector<Node*> nodes;
public:
    Graph(std::string filename);
    std::vector<Node*> get_nodes();
    void print_graph();

};

