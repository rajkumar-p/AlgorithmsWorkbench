#include "graph_algorithms.hpp"
#include <queue>
#include <iostream>

std::map<std::string, vertex_search_prop> bfs(graph &G, std::string source_id)
{
    std::map<std::string, vertex_search_prop> bfs_results;

    G.foreach_vertex([&bfs_results](std::string id) {
        bfs_results.emplace(id, vertex_search_prop());
    });

    if (bfs_results.find(source_id) == bfs_results.end()) {
        return bfs_results;
    }

    bfs_results[source_id].set_dist_from_root(0);
    bfs_results[source_id].set_vertex_color(vertex_color::gray);
    bfs_results[source_id].set_parent("NIL");

    std::queue<std::string> Q;
    Q.push(source_id);

    while (!Q.empty()) {
        std::string top_vertex_id = Q.front();
        Q.pop();

        G.foreach_adj_edge(top_vertex_id, [&Q, &bfs_results, top_vertex_id](edge e) {
            if (bfs_results[e.to()].color() == vertex_color::white) {
                bfs_results[e.to()].set_dist_from_root(bfs_results[top_vertex_id].dist_from_root() + 1);
                bfs_results[e.to()].set_parent(top_vertex_id);
                bfs_results[e.to()].set_vertex_color(vertex_color::gray);

                Q.push(e.to());
            }
        });

        bfs_results[top_vertex_id].set_vertex_color(vertex_color::black);
    }

    return bfs_results;
}

void print_bfs_path(std::map<std::string, vertex_search_prop> &bfs_results, std::string target_id)
{
    if (bfs_results.find(target_id) == bfs_results.end()) {
        std::cout <<"NIL";
        return;
    }

    std::string vertex_id = target_id;
    while (vertex_id != "NIL") {
        std::cout <<vertex_id<<"<-";
        vertex_id = bfs_results[vertex_id].parent();
    }
    
    std::cout <<"NIL"<<std::endl;
}