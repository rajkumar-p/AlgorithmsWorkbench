#include "catch.hpp"
#include "graph.hpp"

TEST_CASE("Checking Graph Implementation", "[Graph]")
{
    SECTION("Graph Add Vertex and Edge") {
        graph G;

        G.add_vertex("S");
        G.add_vertex("R");
        G.add_vertex("V");
        G.add_vertex("W");

        REQUIRE(G.get_vertex_count() == 4);

        G.add_vertex("T");
        G.add_vertex("X");
        G.add_vertex("U");
        G.add_vertex("Y");

        REQUIRE(G.get_vertex_count() == 8);

        G.add_edge("S", "R");
        G.add_edge("S", "W");
        G.add_edge("R", "V");

        REQUIRE(G.get_edge_count() == 6);

        G.add_edge("W", "T");
        G.add_edge("W", "X");

        REQUIRE(G.get_edge_count() == 10);

        G.add_edge("T", "X");
        G.add_edge("T", "U");
        G.add_edge("X", "U");
        G.add_edge("X", "Y");
        G.add_edge("U", "Y");

        REQUIRE(G.get_edge_count() == 20);

        REQUIRE(G.get_adj_vertices_count("S") == 2);
        std::list<std::string> ver_ids_adj_to_s = { "R", "W" };
        G.foreach_adj_edge("S", [&ver_ids_adj_to_s](edge e) {
            REQUIRE(e.from() == "S");
            REQUIRE(e.to() == ver_ids_adj_to_s.front());

            ver_ids_adj_to_s.pop_front();
        });

        REQUIRE(G.get_adj_vertices_count("U") == 3);
        std::list<std::string> ver_ids_adj_to_u = { "T", "X", "Y" };
        G.foreach_adj_edge("U", [&ver_ids_adj_to_u](edge e) {
            REQUIRE(e.from() == "U");
            REQUIRE(e.to() == ver_ids_adj_to_u.front());

            ver_ids_adj_to_u.pop_front();
        });
    }
}