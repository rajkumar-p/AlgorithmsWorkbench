#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include "math_algorithms.hpp"

int main(int argc, char *argv[])
{
    // graph G;

    // G.add_vertex("S");
    // G.add_vertex("Z");
    // G.add_vertex("Y");
    // G.add_vertex("X");
    // G.add_vertex("W");
    // G.add_vertex("T");
    // G.add_vertex("V");
    // G.add_vertex("U");

    // G.add_directed_edge("S", "Z");
    // G.add_directed_edge("S", "W");
    // G.add_directed_edge("Z", "Y");
    // G.add_directed_edge("Z", "W");
    // G.add_directed_edge("Y", "X");
    // G.add_directed_edge("X", "Z");
    // G.add_directed_edge("W", "X");
    // G.add_directed_edge("V", "W");
    // G.add_directed_edge("V", "S");
    // G.add_directed_edge("T", "U");
    // G.add_directed_edge("T", "V");
    // G.add_directed_edge("U", "T");
    // G.add_directed_edge("U", "V");

    // std::map<std::string, vertex_search_prop> dfs_results = dfs(G);
    // for (const std::pair<std::string, vertex_search_prop> &p : dfs_results) {
    //     std::cout <<"Vertex id : "<<p.first<<std::endl;
    //     std::cout <<"Parent : "<<p.second.parent()<<", ST : "<<p.second.start_time()<<", ET : "<<p.second.end_time()<<std::endl;
    // }
    // std::cout <<std::endl;

    // std::map<std::string, edge_type> edge_results = classify_edges(G);
    // for (const std::pair<std::string, edge_type> &p : edge_results) {
    //     std::string type;
    //     if (p.second == edge_type::tree) {
    //         type = "Tree";
    //     } else if (p.second == edge_type::back) {
    //         type = "Back";
    //     } else if (p.second == edge_type::forward_or_cross) {
    //         type = "Forward/Cross";
    //     } else {
    //         type = "Uinit";
    //     }

    //     std::cout <<p.first<<" :: "<<type<<std::endl;
    // }
    // std::cout <<std::endl;

    // graph G;

    // G.add_vertex("undershorts");
    // G.add_vertex("pants");
    // G.add_vertex("belt");
    // G.add_vertex("shirt");
    // G.add_vertex("tie");
    // G.add_vertex("jacket");
    // G.add_vertex("socks");
    // G.add_vertex("shoes");
    // G.add_vertex("watch");

    // G.add_directed_edge("undershorts", "shoes");
    // G.add_directed_edge("undershorts", "pants");
    // G.add_directed_edge("pants", "shoes");
    // G.add_directed_edge("pants", "belt");
    // G.add_directed_edge("socks", "shoes");
    // G.add_directed_edge("shirt", "belt");
    // G.add_directed_edge("shirt", "tie");
    // G.add_directed_edge("belt", "jacket");
    // G.add_directed_edge("tie", "jacket");

    // topological_sort(G);

    // graph G;

    // G.add_vertex("A");
    // G.add_vertex("B");
    // G.add_vertex("C");
    // G.add_vertex("D");
    // G.add_vertex("E");
    // G.add_vertex("F");
    // G.add_vertex("G");
    // G.add_vertex("H");

    // G.add_directed_edge("A", "B");
    // G.add_directed_edge("B", "C");
    // G.add_directed_edge("B", "E");
    // G.add_directed_edge("C", "D");
    // G.add_directed_edge("C", "G");
    // G.add_directed_edge("D", "C");
    // G.add_directed_edge("D", "H");
    // G.add_directed_edge("H", "H");
    // G.add_directed_edge("E", "A");
    // G.add_directed_edge("E", "F");
    // G.add_directed_edge("F", "G");
    // G.add_directed_edge("G", "F");
    // G.add_directed_edge("G", "H");

    // std::map<std::string, vertex_search_prop> dfs_results = strongly_connected_components(G);
    // for (const std::pair<std::string, vertex_search_prop> &p : dfs_results) {
    //     std::cout <<"<<Vertex id : "<<p.first<<">>"<<std::endl;
    //     std::cout <<"Parent : "<<p.second.parent()<<", ST : "<<p.second.start_time()<<", ET : "<<p.second.end_time()<<std::endl;
    // }
    // std::cout <<std::endl;

    // graph G;

    // G.add_vertex("A");
    // G.add_vertex("B");
    // G.add_vertex("C");
    // G.add_vertex("D");
    // G.add_vertex("E");
    // G.add_vertex("F");
    // G.add_vertex("G");
    // G.add_vertex("H");
    // G.add_vertex("I");

    // G.add_edge("A", "B", 4);
    // G.add_edge("A", "H", 8);
    // G.add_edge("B", "H", 11);
    // G.add_edge("B", "C", 8);
    // G.add_edge("C", "D", 7);
    // G.add_edge("H", "G", 1);
    // G.add_edge("G", "F", 2);
    // G.add_edge("H", "I", 7);
    // G.add_edge("I", "C", 2);
    // G.add_edge("I", "G", 6);
    // G.add_edge("C", "F", 4);
    // G.add_edge("D", "F", 14);
    // G.add_edge("D", "E", 9);
    // G.add_edge("F", "E", 10);

    // graph MST;
    // mst_prim(G, "A", MST);

    // std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    // pq.push(50);
    // pq.push(25);
    // pq.push(55);
    // pq.push(1);

    // while (!pq.empty()) {
    //     std::cout <<pq.top()<<"\t";
    //     pq.pop();
    // }
    // size_t mst_weight = 0;
    // MST.foreach_edge([&mst_weight] (edge e) {
    //     mst_weight += e.weight();
    // });

    // std::cout <<"MST Weight : "<<mst_weight / 2<<std::endl;

    // graph G;

    // G.add_vertex("S");
    // G.add_vertex("T");
    // G.add_vertex("Y");
    // G.add_vertex("X");
    // G.add_vertex("Z");

    // G.add_directed_edge("S", "T", 6);
    // G.add_directed_edge("S", "Y", 7);
    // G.add_directed_edge("T", "Y", 8);
    // G.add_directed_edge("T", "X", 5);
    // G.add_directed_edge("X", "T", -2);
    // G.add_directed_edge("Y", "X", -3);
    // G.add_directed_edge("T", "Z", -4);
    // G.add_directed_edge("Z", "S", 2);
    // G.add_directed_edge("Z", "X", 7);

    // std::map<std::string, vertex_search_prop> results;
    // if (bellman_ford(G, "S", results) == true) {
    //     for (const std::pair<std::string, vertex_search_prop> &p : results) {
    //         std::cout <<"V : "<<p.first<<", D : "<<p.second.dist_from_root()<<std::endl;
    //     }
    // }
    // std::cout <<std::endl;

    // graph G;

    // G.add_vertex("S");
    // G.add_vertex("T");
    // G.add_vertex("Y");
    // G.add_vertex("X");
    // G.add_vertex("Z");

    // G.add_directed_edge("S", "T", 10);
    // G.add_directed_edge("S", "Y", 5);
    // G.add_directed_edge("T", "Y", 2);
    // G.add_directed_edge("Y", "T", 3);
    // G.add_directed_edge("T", "X", 1);
    // G.add_directed_edge("Y", "Z", 2);
    // G.add_directed_edge("Y", "X", 9);
    // G.add_directed_edge("X", "Z", 4);
    // G.add_directed_edge("Z", "X", 6);
    // G.add_directed_edge("Z", "S", 7);

    // std::map<std::string, vertex_search_prop> results = djikstra(G, "S");
    // for (const std::pair<std::string, vertex_search_prop> &p : results) {
    //     std::cout <<"V : "<<p.first<<", D : "<<p.second.dist_from_root()<<std::endl;
    // }

    // std::vector<std::tuple<int, int>> points;

    // points.push_back(std::make_tuple(5, 0));
    // points.push_back(std::make_tuple(1, -5));

    // double angle = angle_between_points(points[0], points[1]);

    std::string str = "➡︎℞∋⁉︎௹";
    std::cout <<"Len : "<<str.length()<<std::endl;
    std::cout <<str<<std::endl;
    for (const char c : str) {
        std::wcout<<c<<"\t";
    }

    return 0;
}
