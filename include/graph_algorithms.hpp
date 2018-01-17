#ifndef GRAPH_ALGORITHMS_HPP
#define GRAPH_ALGORITHMS_HPP

#include "graph.hpp"

enum class vertex_color {
    white, gray, black
};

class vertex_search_prop {
private:
    int _dist_from_root;
    std::string _parent;
    vertex_color _color;

public:
    vertex_search_prop() : _dist_from_root(-1), _parent(""), _color(vertex_color::white) {}
    vertex_search_prop(int dist_from_root, std::string parent, vertex_color color) : _dist_from_root(dist_from_root), _parent(parent), _color(color) {}

    int dist_from_root() const { return _dist_from_root; }
    std::string parent() const { return _parent; }
    vertex_color color() const { return _color; }

    void set_dist_from_root(int dist_from_root) { _dist_from_root = dist_from_root; }
    void set_parent(std::string parent) { _parent = parent; }
    void set_vertex_color(vertex_color color) { _color = color; }
};

std::map<std::string, vertex_search_prop> bfs(graph &G, std::string source_id);
void print_bfs_path(std::map<std::string, vertex_search_prop> &bfs_results, std::string target_id);

#endif