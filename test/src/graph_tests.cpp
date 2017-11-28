#include "catch.hpp"
#include "graph.hpp"

TEST_CASE("Checking Graph Implementation", "[Graph]")
{
    SECTION("Graph Add Vertex and Edge") {
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

        REQUIRE(G->get_vertex_count() == 4);

        G->add_vertex(t);
        G->add_vertex(x);
        G->add_vertex(u);
        G->add_vertex(y);

        REQUIRE(G->get_vertex_count() == 8);

        G->add_edge(s, r);
        G->add_edge(s, w);
        G->add_edge(r, v);

        REQUIRE(G->get_edge_count() == 6);

        G->add_edge(w, t);
        G->add_edge(w, x);

        REQUIRE(G->get_edge_count() == 10);

        G->add_edge(t, x);
        G->add_edge(t, u);
        G->add_edge(x, u);
        G->add_edge(x, y);
        G->add_edge(u, y);

        REQUIRE(G->get_edge_count() == 20);

        delete G;
    }
}