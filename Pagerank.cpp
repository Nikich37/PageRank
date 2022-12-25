#include <math.h>
#include <vector>
#include <map>
#include "Graph.h"

using namespace std;

void pagerank(Graph g) {
    
    vector<Node*> u = g.get_nodes();

    map<Node*, float> next_pr;
    int N = u.size();
    float d = 0.85;
    float default_pr = (float)(1 - d) / N; 
    float e = 0.001;
    
    for (auto p : u) { (*p).pr = (float)1 / N; }

    bool cf = true;
    while (cf) {
        next_pr.clear();
        for (auto p : u) {
            for (auto l : (*p).links) {
                if ((*p).links.empty())
                    next_pr[l] += (float)1 / N;
                else
                    next_pr[l] += (float)p->pr / (*p).links.size();
            }
        }
        cf = false;
        for (auto p : u) {
            next_pr[p] = default_pr + d * next_pr[p];
            if (abs(next_pr[p] - (*p).pr) > e)
                cf = true;
            (*p).pr = next_pr[p];
        }
    }
}

int main() {
    Graph web_graph("graph.txt");
    pagerank(web_graph);
    web_graph.print_graph();
    return 0;
}