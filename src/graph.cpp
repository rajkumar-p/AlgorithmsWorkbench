#include "graph.hpp"

graph::graph() : _vertices(), _edges(), _adj_edges()
{

}

graph::~graph()
{
    deinit_adj_edges();
    deinit_edges();
    deinit_vertices();
}

void graph::deinit_adj_edges()
{
    for (std::pair<const std::string, std::list<edge *> *> &adj : _adj_edges) {
        adj.second = nullptr;
    }
}

void graph::deinit_edges()
{
    for (edge *e : _edges) {
        if (e != nullptr) {
            delete e;
            e = nullptr;
        }
    }
}

void graph::deinit_vertices()
{
    for (std::pair<const std::string, vertex *> &kv : _vertices) {
        if (kv.second != nullptr) {
            delete kv.second;
            kv.second = nullptr;
        }
    }
}

vertex *graph::make_vertex(std::string id)
{
    return new vertex(id);
}

void graph::add_vertex(vertex *v)
{
    _vertices.insert(std::pair<std::string, vertex *>(v->id(), v));
    _adj_edges.insert(std::pair<std::string, std::list<edge *> *>(v->id(), new std::list<edge *>()));
}

vertex *graph::get_vertex(const std::string s)
{
    std::map<std::string, vertex *>::iterator it;

    it = _vertices.find(s);

    if (it != _vertices.end()) {
        return it->second;
    }

    return nullptr;
}

size_t graph::get_vertex_count()
{
    return _vertices.size();
}

size_t graph::get_edge_count()
{
    return _edges.size();
}

void graph::foreach_vertex(const std::function<void (const vertex *v)> fn)
{
    for (std::pair<const std::string, vertex *> &kv : _vertices) {
        fn(kv.second);
    }
}

void graph::foreach_edge(const std::function<void (const edge *e)> fn)
{
    for (const edge *e : _edges) {
        fn(e);
    }
}

void graph::foreach_vertex_change(const std::function<void(vertex *v)> changes)
{
    for (std::pair<const std::string, vertex *> &kv : _vertices) {
        changes(kv.second);
    }
}

void graph::add_directed_edge(vertex *v1, vertex *v2, int weight)
{
    if (v1 != v2 && v1 != nullptr && v2 != nullptr) {
        edge *e = new edge(v1, v2, weight);
        _edges.push_back(e);
        _adj_edges[v1->id()]->push_back(e);
    }
}

void graph::add_edge(vertex *v1, vertex *v2, int weight)
{
    if (v1 != v2 && v1 != nullptr && v2 != nullptr) {
        add_directed_edge(v1, v2, weight);
        add_directed_edge(v2, v1, weight);
    }
}

std::list<edge *> *graph::get_adj_edges(vertex *v)
{
    std::map<std::string, std::list<edge *> *>::iterator it;
    it = _adj_edges.find(v->id());

    if (it != _adj_edges.end()) {
        return it->second;
    }

    return nullptr;
}

size_t graph::get_adj_edge_count(vertex *v)
{
    std::map<std::string, std::list<edge *> *>::iterator it;
    it = _adj_edges.find(v->id());

    if (it != _adj_edges.end()) {
        return it->second->size();
    }

    return 0;
}