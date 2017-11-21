#include "graph.hpp"

// graph::graph() : _vertices(), _adj_list()
// {

// }

// graph::~graph()
// {
//     deinit_adj_list();
//     deinit_vertices();
// }

// void graph::deinit_adj_list()
// {
//     for (std::pair<const std::string, std::list<vertex *> *> &adj : _adj_list) {
//         adj.second = nullptr;
//     }
// }

// void graph::deinit_vertices()
// {
//     for (std::pair<const std::string, vertex *> &kv : _vertices) {
//         delete kv.second;

//         kv.second = nullptr;
//     }
// }

// void graph::add_vertex(vertex *v)
// {
//     _vertices.insert(std::pair<std::string, vertex *>(v->id(), v));
//     _adj_list.insert(std::pair<std::string, std::list<vertex *> *>(v->id(), new std::list<vertex *>()));
// }

// vertex *graph::get_vertex(const std::string s)
// {
//     std::map<std::string, vertex *>::iterator it;

//     it = _vertices.find(s);

//     if (it != _vertices.end()) {
//         return it->second;
//     }

//     return nullptr;
// }

// void graph::foreach_vertex(const std::function<void (const vertex *v)> fn)
// {
//     for (std::pair<const std::string, vertex *> &kv : _vertices) {
//         fn(kv.second);
//     }
// }

// void graph::add_edge(vertex *v1, vertex *v2)
// {
//     if (v1 != v2 && v1 != nullptr && v2 != nullptr) {
//         _adj_list[v1->id()]->push_back(v2);
//     }
// }

// std::list<vertex *> *graph::get_adj_vertices_to(vertex *v)
// {
//     std::map<std::string, std::list<vertex *> *>::iterator it;

//     it = _adj_list.find(v->id());

//     if (it != _adj_list.end()) {
//         return it->second;
//     }

//     return nullptr;
// }