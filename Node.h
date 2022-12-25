#pragma once
#include <string>
#include <vector>


struct Node {
    std::string name;
    float pr;
    std::vector<Node*> links;
};

