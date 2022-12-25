#include <fstream>
#include "Graph.h"

Graph::Graph(std::string filename) {
    std::fstream file(filename);
    if (file.is_open()) {
        int number_of_pages;
        file >> number_of_pages;
        for (int i = 0; i < number_of_pages; i++) {
            std::string page_name;
            file >> page_name;
            Node* node = new Node();
            node->name = page_name;
            nodes.push_back(node);
        }
        for (int i = 0; i < number_of_pages; i++) {
            for (int j = 0; j < number_of_pages; j++) {
                bool is_related;
                file >> is_related;
                if (is_related) {
                    nodes[i]->links.push_back(nodes[j]);
                }
            }
        }
    }
}

std::vector<Node*> Graph::get_nodes() {
    return nodes;
}

void Graph::print_graph() {
    std::cout << std::fixed;
    std::cout.precision(3);
    for (Node* node : nodes) {
        std::cout << node->name << " pr: " << node->pr  << " links: { ";
        for (Node* related_node : node->links) {
            std::cout << related_node->name << " ";
        }
        std::cout << "}\n";
    }
}