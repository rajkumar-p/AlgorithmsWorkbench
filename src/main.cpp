#include <iostream>
#include "graph.hpp"
#include "graph_algorithms.hpp"

int main(int argc, char *argv[])
{
    graph *G = new graph();

    vertex *s = G->make_vertex("S");
    vertex *r = G->make_vertex("R");
    vertex *v = G->make_vertex("V");
    vertex *w = G->make_vertex("W");
    vertex *t = G->make_vertex("T");
    vertex *x = G->make_vertex("X");
    vertex *u = G->make_vertex("U");
    vertex *y = G->make_vertex("Y");

    G->add_vertex(s);
    G->add_vertex(r);
    G->add_vertex(v);
    G->add_vertex(w);
    G->add_vertex(t);
    G->add_vertex(x);
    G->add_vertex(u);
    G->add_vertex(y);

    G->add_edge(s, r);
    G->add_edge(s, w);
    G->add_edge(r, v);
    G->add_edge(w, t);
    G->add_edge(w, x);
    G->add_edge(t, x);
    G->add_edge(t, u);
    G->add_edge(x, u);
    G->add_edge(x, y);
    G->add_edge(u, y);

    std::map<std::string, vertex> bfs_vertices = bfs(G, s);
    for (auto &kv : bfs_vertices) {
        std::cout <<"ID : "<<kv.first<<", DIST : "<<kv.second.distance_from_root()<<std::endl;
    }

    std::cout <<std::endl;

    print_bfs_path(bfs_vertices, G->get_vertex("Y"));

    std::cout <<std::endl;

    delete G;

    return 0;
}