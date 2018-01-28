#include <iostream>
#include <vector>
#include <cmath>
#include "graph_algorithms.hpp"

int main(int argc, char *argv[])
{
    graph G;

    G.add_vertex("S");
    G.add_vertex("Z");
    G.add_vertex("Y");
    G.add_vertex("X");
    G.add_vertex("W");
    G.add_vertex("T");
    G.add_vertex("V");
    G.add_vertex("U");

    G.add_directed_edge("S", "Z");
    G.add_directed_edge("S", "W");
    G.add_directed_edge("Z", "Y");
    G.add_directed_edge("Z", "W");
    G.add_directed_edge("Y", "X");
    G.add_directed_edge("X", "Z");
    G.add_directed_edge("W", "X");
    G.add_directed_edge("V", "W");
    G.add_directed_edge("V", "S");
    G.add_directed_edge("T", "U");
    G.add_directed_edge("T", "V");
    G.add_directed_edge("U", "T");
    G.add_directed_edge("U", "V");

    // std::map<std::string, vertex_search_prop> dfs_results = dfs(G);
    // for (const std::pair<std::string, vertex_search_prop> &p : dfs_results) {
    //     std::cout <<"Vertex id : "<<p.first<<std::endl;
    //     std::cout <<"Parent : "<<p.second.parent()<<", ST : "<<p.second.start_time()<<", ET : "<<p.second.end_time()<<std::endl;
    // }
    // std::cout <<std::endl;

    std::map<std::string, edge_type> edge_results = classify_edges(G);
    for (const std::pair<std::string, edge_type> &p : edge_results) {
        std::string type;
        if (p.second == edge_type::tree) {
            type = "Tree";
        } else if (p.second == edge_type::back) {
            type = "Back";
        } else if (p.second == edge_type::forward_or_cross) {
            type = "Forward/Cross";
        } else {
            type = "Uinit";
        }

        std::cout <<p.first<<" :: "<<type<<std::endl;
    }
    std::cout <<std::endl;

    return 0;
}
