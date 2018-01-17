#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <list>
#include <string>

class edge {
private:
    std::string _from;
    std::string _to;
    size_t _weight;

public:
    edge(const std::string from, const std::string to, const size_t weight) : _from(from), _to(to), _weight(weight) {}

    std::string from() const { return _from; }
    std::string to() const { return _to; }
    size_t weight() const { return _weight; }
};

class graph {
private:
    std::map<std::string, std::list<edge>> _vertex_and_adj_edges;
    size_t _edge_count;

public:
    graph() : _vertex_and_adj_edges(), _edge_count(0) {}

    void add_vertex(const std::string id);
    void add_directed_edge(const std::string from, const std::string to, const size_t weight = 1);
    void add_edge(const std::string from, const std::string to, const size_t weight = 1);

    size_t get_vertex_count() const;
    size_t get_edge_count() const;
    size_t get_adj_vertices_count(const std::string vertex_id);

    void foreach_vertex(const std::function<void(std::string id)> fn);
    void foreach_edge(const std::function<void(edge e)> fn);
    void foreach_adj_edge(const std::string vertex_id, std::function<void(edge e)> fn);
};

#endif