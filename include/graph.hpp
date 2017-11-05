#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <list>
#include <string>

class vertex {
private:
    std::string _id;

public:
    vertex(std::string id) : _id(id) { }

    const std::string id() const { return _id; }
};

enum class vertex_color {
    white, gray, black
};

class vertex_search_details {
private:
    std::string _id;
    vertex_color _color;
    size_t _dist_from_root;
    vertex *_parent;

public:
    vertex_search_details(std::string id) : _id(id), _color(vertex_color::white), _dist_from_root(0), _parent(nullptr) { }

    std::string id() const { return _id; }
    vertex_color color() const { return _color; }
    size_t dist_from_root() const { return _dist_from_root; }
    vertex *parent() const { return _parent; }

    void set_color(vertex_color c) { _color = c; }
    void set_dist_from_root(size_t dist) { _dist_from_root = dist; }
    void set_parent(vertex *p) { _parent = p; }
};

class graph {
private:
    std::map<std::string, vertex *> _vertices;
    std::map<std::string, std::list<vertex *> *> _adj_list; 

public:
    void add_vertex(vertex *v);
    vertex *get_vertex(const std::string id);
    void foreach_vertex(const std::function<void(const vertex *v)> fn);

    void add_edge(const std::string id1, const std::string id2);

    std::list<vertex *> *get_adj_vertices_to(vertex *v);
};

#endif