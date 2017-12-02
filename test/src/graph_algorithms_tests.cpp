#include "catch.hpp"
#include "graph.hpp"
#include "graph_algorithms.hpp"

TEST_CASE("Checking Graph Algorithms", "[Graph Algorithms]")
{
    SECTION("Breadth First Search (BFS)") {
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

        std::map<std::string, size_t> bfs_check = { std::pair<std::string, size_t>("R", 1),
                                                    std::pair<std::string, size_t>("S", 0),
                                                    std::pair<std::string, size_t>("T", 2),
                                                    std::pair<std::string, size_t>("U", 3),
                                                    std::pair<std::string, size_t>("V", 2),
                                                    std::pair<std::string, size_t>("W", 1),
                                                    std::pair<std::string, size_t>("X", 2),
                                                    std::pair<std::string, size_t>("Y", 3)
                                                  };
    
        for (auto &kv : bfs_vertices) {
            REQUIRE(kv.first == bfs_check.find(kv.first)->first);
            REQUIRE(kv.second.distance_from_root() == bfs_check.find(kv.first)->second);
        }

        delete G;

    }
}