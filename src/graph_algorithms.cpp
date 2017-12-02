#include "graph_algorithms.hpp"
#include <queue>
#include <iostream>

void init_vertices_for_bfs(graph *G)
{
    G->foreach_vertex_change([](vertex *v) {
        v->set_color(vertex_color::white);
        v->set_dist_from_root(INT32_MAX);
        v->set_prev("");
    });
}

void init_source_vertex_for_bfs(vertex *source)
{
    source->set_color(vertex_color::gray);
    source->set_dist_from_root(0);
    source->set_prev("");
}

std::map<std::string, vertex> bfs(graph *G, vertex *source)
{
    init_vertices_for_bfs(G);
    init_source_vertex_for_bfs(source);

    std::queue<vertex *> Q;

    Q.push(source);

    while (!Q.empty()) {
        vertex *u = Q.front();
        Q.pop();

        std::list<edge *> *adj_edges_to_u = G->get_adj_edges(u);
        for (const edge *e : *adj_edges_to_u) {
            if (e->to()->color() == vertex_color::white) {
                e->to()->set_color(vertex_color::gray);
                e->to()->set_dist_from_root(u->distance_from_root() + 1);
                e->to()->set_prev(u->id());

                Q.push(e->to());
            }
        }

        u->set_color(vertex_color::black);
    }

    std::map<std::string, vertex> bfs_vertices;
    G->foreach_vertex([&bfs_vertices](const vertex *v) {
        bfs_vertices.insert(std::pair<std::string, vertex>(v->id(), *v));
    });

    return bfs_vertices;
}

void print_bfs_path(std::map<std::string, vertex> &bfs_vertices, vertex *target)
{
    std::string id = target->id();
    std::map<std::string, vertex>::iterator it;
    while((it = bfs_vertices.find(id)) != bfs_vertices.end()) {
        std::cout <<it->first;

        if (it->second.prev() == "") {
            return;
        } else {
            id = it->second.prev();
            std::cout <<"<---";
        }
    }
}