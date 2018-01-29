#ifndef GRAPH_ALGORITHMS_HPP
#define GRAPH_ALGORITHMS_HPP

#include "graph.hpp"

enum class vertex_color {
    white, gray, black
};

enum class edge_type {
    uninit, tree, back, forward_or_cross
};

class vertex_search_prop {
private:
    int _dist_from_root;
    std::string _parent;
    vertex_color _color;

    size_t _start_time;
    size_t _end_time;

public:
    vertex_search_prop() : _dist_from_root(-1), _parent("NIL"), _color(vertex_color::white) {}
    vertex_search_prop(int dist_from_root, std::string parent, vertex_color color) : _dist_from_root(dist_from_root), _parent(parent), _color(color) {}

    int dist_from_root() const { return _dist_from_root; }
    std::string parent() const { return _parent; }
    vertex_color color() const { return _color; }

    size_t start_time() const { return _start_time; }
    size_t end_time() const { return _end_time; }

    void set_dist_from_root(int dist_from_root) { _dist_from_root = dist_from_root; }
    void set_parent(std::string parent) { _parent = parent; }
    void set_vertex_color(vertex_color color) { _color = color; }

    void set_start_time(size_t start_time) { _start_time = start_time; }
    void set_end_time(size_t end_time) { _end_time = end_time; }
};

std::map<std::string, vertex_search_prop> bfs(graph &G, std::string source_id);
void print_bfs_path(std::map<std::string, vertex_search_prop> &bfs_results, std::string target_id);

std::map<std::string, vertex_search_prop> dfs(graph &G);
void dfs_walk(graph &G, std::string from_vertex_id, std::atomic<size_t> &time_counter, std::map<std::string, vertex_search_prop> &dfs_results);

std::map<std::string, edge_type> classify_edges(graph &G);
void dfs_walk_to_classify_edges(graph &G, std::string from_vertex_id, std::map<std::string, vertex_color> &vertex_colors, std::map<std::string, edge_type> &edge_results);

std::map<std::string, vertex_search_prop> dfs_custom_order(graph &G, std::vector<std::string> vertices_order);
std::map<std::string, vertex_search_prop> strongly_connected_components(graph &G);
void transverse_of(graph &G, graph &GT);

std::list<std::string> topological_sort(graph &G);

void mst_prim(graph &G, const std::string source_id, graph &output_tree);

bool bellman_ford(graph &G, std::string source_id, std::map<std::string, vertex_search_prop> &results);
std::map<std::string, vertex_search_prop> dag_shortest_path(graph &DAG, std::string source_id);
std::map<std::string, vertex_search_prop> djikstra(graph &G, std::string source_id);

#endif