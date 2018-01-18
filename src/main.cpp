#include <iostream>
#include <vector>
#include "graph_algorithms.hpp"

int main(int argc, char *argv[])
{
    graph G;

    G.add_vertex("S");
    G.add_vertex("R");
    G.add_vertex("V");
    G.add_vertex("W");
    G.add_vertex("T");
    G.add_vertex("X");
    G.add_vertex("U");
    G.add_vertex("Y");

    G.add_edge("S", "R");
    G.add_edge("S", "W");
    G.add_edge("R", "V");
    G.add_edge("W", "T");
    G.add_edge("W", "X");
    G.add_edge("T", "X");
    G.add_edge("T", "U");
    G.add_edge("X", "U");
    G.add_edge("X", "Y");
    G.add_edge("U", "Y");

    std::map<std::string, vertex_search_prop> bfs_results = bfs(G, "S");
    print_bfs_path(bfs_results, "Y");

    return 0;
}
