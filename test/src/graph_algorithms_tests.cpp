#include "catch.hpp"
#include "graph.hpp"
#include "graph_algorithms.hpp"

TEST_CASE("Checking Graph Algorithms", "[Graph Algorithms]")
{
    SECTION("Breadth First Search (BFS)") {
        graph G;

        G.add_vertex("S");
        G.add_vertex("R");
        G.add_vertex("V");
        G.add_vertex("W");
        G.add_vertex("T");
        G.add_vertex("X");
        G.add_vertex("U");
        G.add_vertex("Y");

        G.add_edge("S", "R");
        G.add_edge("S", "W");
        G.add_edge("R", "V");
        G.add_edge("W", "T");
        G.add_edge("W", "X");
        G.add_edge("T", "X");
        G.add_edge("T", "U");
        G.add_edge("X", "U");
        G.add_edge("X", "Y");
        G.add_edge("U", "Y");

        std::map<std::string, vertex_search_prop> bfs_results = bfs(G, "S");

        std::map<std::string, size_t> bfs_dist_from_root =
        {
            std::pair<std::string, size_t>("R", 1),
            std::pair<std::string, size_t>("S", 0),
            std::pair<std::string, size_t>("T", 2),
            std::pair<std::string, size_t>("U", 3),
            std::pair<std::string, size_t>("V", 2),
            std::pair<std::string, size_t>("W", 1),
            std::pair<std::string, size_t>("X", 2),
            std::pair<std::string, size_t>("Y", 3)
        };

        for (const std::pair<std::string, size_t> &kv : bfs_dist_from_root) {
            REQUIRE(kv.second == bfs_results.find(kv.first)->second.dist_from_root());
        }

        std::map<std::string, std::string> bfs_parent = 
        {
            std::pair<std::string, std::string>("R", "S"),
            std::pair<std::string, std::string>("S", "NIL"),
            std::pair<std::string, std::string>("T", "W"),
            std::pair<std::string, std::string>("U", "T"),
            std::pair<std::string, std::string>("V", "R"),
            std::pair<std::string, std::string>("W", "S"),
            std::pair<std::string, std::string>("X", "W"),
            std::pair<std::string, std::string>("Y", "X")
        };

        for (const std::pair<std::string, std::string> &kv : bfs_parent) {
            REQUIRE(kv.second == bfs_results.find(kv.first)->second.parent());
        }
    }

    SECTION("Depth First Search (DFS)") {
        graph G;

        G.add_vertex("U");
        G.add_vertex("V");
        G.add_vertex("X");
        G.add_vertex("Y");
        G.add_vertex("W");
        G.add_vertex("Z");

        G.add_directed_edge("U", "V");
        G.add_directed_edge("U", "X");
        G.add_directed_edge("X", "V");
        G.add_directed_edge("V", "Y");
        G.add_directed_edge("Y", "X");
        G.add_directed_edge("W", "Z");
        G.add_directed_edge("W", "Y");
        G.add_directed_edge("Z", "Z");
    }
}