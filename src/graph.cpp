#include "graph.hpp"

void graph::add_vertex(const std::string id)
{
    // Insert into map, only if not already present
    if (_vertex_and_adj_edges.find(id) == _vertex_and_adj_edges.end()) {
        std::list<edge> adj_edges;
        _vertex_and_adj_edges.emplace(id, adj_edges);
    }
}

void graph::add_directed_edge(const std::string from, const std::string to, const size_t weight)
{
    auto vertex_not_present = _vertex_and_adj_edges.end();
    if (_vertex_and_adj_edges.find(from) != vertex_not_present && _vertex_and_adj_edges.find(to) != vertex_not_present) {
        _vertex_and_adj_edges[from].push_back(edge(from, to, weight));
        ++_edge_count;
    }
}

void graph::add_edge(const std::string from, const std::string to, const size_t weight)
{
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}

size_t graph::get_vertex_count() const
{
    return _vertex_and_adj_edges.size();
}

size_t graph::get_edge_count() const
{
    return _edge_count;
}

size_t graph::get_adj_vertices_count(const std::string vertex_id)
{
    if (_vertex_and_adj_edges.find(vertex_id) != _vertex_and_adj_edges.end()) {
        return _vertex_and_adj_edges[vertex_id].size();
    }

    return 0;
}

void graph::foreach_vertex(const std::function<void(std::string id)> fn)
{
    for (const std::pair<std::string, std::list<edge>> &kv : _vertex_and_adj_edges) {
        fn(kv.first);
    }
}

void graph::foreach_edge(const std::function<void(edge e)> fn)
{
    for (const std::pair<std::string, std::list<edge>> &kv : _vertex_and_adj_edges) {
        std::list<edge> adj_edges = kv.second;

        for (const edge &e : adj_edges) {
            fn(e);
        }
    }
}

void graph::foreach_adj_edge(const std::string vertex_id, std::function<void(edge e)> fn)
{
    if (_vertex_and_adj_edges.find(vertex_id) != _vertex_and_adj_edges.end()) {
        std::list<edge> adj_edges = _vertex_and_adj_edges[vertex_id];

        for (const edge &e : adj_edges) {
            fn(e);
        }
    }
}
