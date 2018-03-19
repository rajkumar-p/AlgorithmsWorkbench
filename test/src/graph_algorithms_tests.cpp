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

        G.add_vertex("S");
        G.add_vertex("Z");
        G.add_vertex("Y");
        G.add_vertex("X");
        G.add_vertex("W");
        G.add_vertex("T");
        G.add_vertex("V");
        G.add_vertex("U");

        G.add_directed_edge("S", "Z");
        G.add_directed_edge("S", "W");
        G.add_directed_edge("Z", "Y");
        G.add_directed_edge("Z", "W");
        G.add_directed_edge("Y", "X");
        G.add_directed_edge("X", "Z");
        G.add_directed_edge("W", "X");
        G.add_directed_edge("V", "W");
        G.add_directed_edge("V", "S");
        G.add_directed_edge("T", "U");
        G.add_directed_edge("T", "V");
        G.add_directed_edge("U", "T");
        G.add_directed_edge("U", "V");

        std::map<std::string, vertex_search_prop> dfs_results = dfs(G);
        for (const std::pair<std::string, vertex_search_prop> &p : dfs_results) {
            if (p.second.parent() != "NIL") {
                REQUIRE(p.second.end_time() < dfs_results[p.second.parent()].end_time());
            }
        }
    }

    SECTION("Edge Classification") {
        graph G;

        G.add_vertex("S");
        G.add_vertex("Z");
        G.add_vertex("Y");
        G.add_vertex("X");
        G.add_vertex("W");
        G.add_vertex("T");
        G.add_vertex("V");
        G.add_vertex("U");

        G.add_directed_edge("S", "Z");
        G.add_directed_edge("S", "W");
        G.add_directed_edge("Z", "Y");
        G.add_directed_edge("Z", "W");
        G.add_directed_edge("Y", "X");
        G.add_directed_edge("X", "Z");
        G.add_directed_edge("W", "X");
        G.add_directed_edge("V", "W");
        G.add_directed_edge("V", "S");
        G.add_directed_edge("T", "U");
        G.add_directed_edge("T", "V");
        G.add_directed_edge("U", "T");
        G.add_directed_edge("U", "V");

        std::map<std::string, edge_type> edge_results = classify_edges(G);
        std::map<std::string, edge_type> edge_type_to_check = {
            std::make_pair("S-W", edge_type::forward_or_cross),
            std::make_pair("S-Z", edge_type::tree),
            std::make_pair("T-U", edge_type::tree),
            std::make_pair("T-V", edge_type::forward_or_cross),
            std::make_pair("U-T", edge_type::back),
            std::make_pair("U-V", edge_type::tree),
            std::make_pair("V-S", edge_type::forward_or_cross),
            std::make_pair("V-W", edge_type::forward_or_cross),
            std::make_pair("W-X", edge_type::forward_or_cross),
            std::make_pair("X-Z", edge_type::back),
            std::make_pair("Y-X", edge_type::tree),
            std::make_pair("Z-W", edge_type::tree),
            std::make_pair("Z-Y", edge_type::tree)
        };

        REQUIRE(edge_results.size() == edge_type_to_check.size());
        for (const std::pair<std::string, edge_type> &p : edge_results) {
            REQUIRE(p.second == edge_type_to_check[p.first]);
        }
    }
}