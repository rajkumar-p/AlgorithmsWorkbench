#ifndef GRAPH_ALGORITHMS_HPP
#define GRAPH_ALGORITHMS_HPP

#include "graph.hpp"

std::map<std::string, vertex> bfs(graph *G, vertex *source);
void print_bfs_path(std::map<std::string, vertex> &bfs_vertices, vertex *traget);

#endif