#include "graph.hpp"

void graph::add_vertex(vertex *v)
{
    _vertices.insert(std::pair<std::string, vertex *>(v->id(), v));
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

void graph::foreach_vertex(const std::function<void (const vertex *v)> fn)
{
    for (std::pair<const std::string, vertex *> &kv : _vertices) {
        fn(kv.second);
    }
}

void graph::add_edge(const std::string id1, const std::string id2)
{
    vertex *v1 = get_vertex(id1);
    vertex *v2 = get_vertex(id2);

    if (v1 != v2 && v1 != nullptr && v2 != nullptr) {
        _adj_list[v1->id()]->push_back(v2);
    }
}

std::list<vertex *> *graph::get_adj_vertices_to(vertex *v)
{
    std::map<std::string, std::list<vertex *> *>::iterator it;

    it = _adj_list.find(v->id());

    if (it != _adj_list.end()) {
        return it->second;
    }

    return nullptr;
}