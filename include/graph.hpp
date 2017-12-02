#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <list>
#include <string>

enum class vertex_color {
    white, gray, black
};

class vertex {
private:
    std::string _id;
    vertex_color _color;
    size_t _dist_from_root;
    std::string _prev;

public:
    vertex(std::string id) : _id(id), _color(vertex_color::white), _dist_from_root(0), _prev("") {}

    std::string id() const { return _id; }
    vertex_color color() const { return _color; }
    size_t distance_from_root() const { return _dist_from_root; }
    const std::string prev() const { return _prev; }

    void set_color(vertex_color color) { _color = color; }
    void set_dist_from_root(size_t dist_from_root) { _dist_from_root = dist_from_root; }
    void set_prev(std::string prev) { _prev = prev; }
};

class edge {
private:
    vertex *_from;
    vertex *_to;
    int _weight;

public:
    edge(vertex *from, vertex *to, int weight) : _from(from), _to(to), _weight(weight) {}

    vertex *from() const { return _from; }
    vertex *to() const { return _to; }
    int weight() const { return _weight; }
};

class graph {
private:
    std::map<std::string, vertex *> _vertices;
    std::list<edge *> _edges;
    std::map<std::string, std::list<edge *> *> _adj_edges; 

public:
    graph();
    ~graph();

    vertex *make_vertex(std::string id);
    void add_vertex(vertex *v);
    vertex *get_vertex(const std::string id);

    size_t get_vertex_count();
    size_t get_edge_count();

    void foreach_vertex(const std::function<void(const vertex *v)> fn);
    void foreach_edge(const std::function<void(const edge *e)> fn);

    void foreach_vertex_change(const std::function<void(vertex *v)> fn);

    void add_directed_edge(vertex *v1, vertex *v2, int weight = 1);
    void add_edge(vertex *v1, vertex *v2, int weight = 1);

    std::list<edge *> *get_adj_edges(vertex *v);
    size_t get_adj_edge_count(vertex *v);

private:
    void deinit_adj_edges();
    void deinit_edges();
    void deinit_vertices();
};

#endif