#ifndef GRAPH_ALGORITHMS_HPP
#define GRAPH_ALGORITHMS_HPP

#include "graph.hpp"

std::map<std::string, vertex_search_details *> *bfs(graph G, vertex *source);

#endif