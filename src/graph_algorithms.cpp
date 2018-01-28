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

// std::map<std::string, vertex_search_prop> dfs(graph &G)
std::map<std::string, vertex_search_prop> dfs(graph &G)
{
    std::map<std::string, vertex_search_prop> dfs_results;
    std::atomic<size_t> time_counter(0);

    G.foreach_vertex([&dfs_results] (std::string id) {
        dfs_results.emplace(id, vertex_search_prop());
    });

    G.foreach_vertex([&G, &time_counter, &dfs_results] (std::string id) {
        if (dfs_results[id].color() == vertex_color::white) {
            dfs_walk(G, id, time_counter, dfs_results);
        }
    });

    return dfs_results;
}

void dfs_walk(graph &G, std::string from_vertex_id, std::atomic<size_t> &time_counter, std::map<std::string, vertex_search_prop> &dfs_results)
{
    dfs_results[from_vertex_id].set_vertex_color(vertex_color::gray);
    dfs_results[from_vertex_id].set_start_time(++time_counter);

    G.foreach_adj_edge(from_vertex_id, [&G, &from_vertex_id, &time_counter, &dfs_results] (edge e) {
        if (dfs_results[e.to()].color() == vertex_color::white) {
            dfs_results[e.to()].set_parent(from_vertex_id);

            dfs_walk(G, e.to(), time_counter, dfs_results);
        }
    });

    dfs_results[from_vertex_id].set_end_time(++time_counter);
    dfs_results[from_vertex_id].set_vertex_color(vertex_color::black);
}

std::map<std::string, edge_type> classify_edges(graph &G)
{
    std::map<std::string, vertex_color> vertex_colors;
    std::map<std::string, edge_type> edge_results;

    G.foreach_vertex([&vertex_colors] (std::string id) {
        vertex_colors[id] = vertex_color::white;
    });

    G.foreach_edge([&edge_results] (edge e) {
        edge_results.emplace(e.from() + "-" + e.to(), edge_type::uninit);
    });

    G.foreach_vertex([&G, &vertex_colors, &edge_results] (std::string id) {
        if (vertex_colors[id] == vertex_color::white) {
            dfs_walk_to_classify_edges(G, id, vertex_colors, edge_results);
        }
    });

    return edge_results;
}

void dfs_walk_to_classify_edges(graph &G, std::string from_vertex_id, std::map<std::string, vertex_color> &vertex_colors, std::map<std::string, edge_type> &edge_results)
{
    vertex_colors[from_vertex_id] = vertex_color::gray;

    G.foreach_adj_edge(from_vertex_id, [&G, &from_vertex_id, &vertex_colors, &edge_results] (edge e) {
        vertex_color to_color = vertex_colors[e.to()];
        if (to_color == vertex_color::white) {
            edge_results[e.from() + "-" + e.to()] = edge_type::tree;
        } else if (to_color == vertex_color::gray) {
            edge_results[e.from() + "-" + e.to()] = edge_type::back;
        } else if (to_color == vertex_color::black) {
            edge_results[e.from() + "-" + e.to()] = edge_type::forward_or_cross;
        }

        if (vertex_colors[e.to()] == vertex_color::white) {
            dfs_walk_to_classify_edges(G, e.to(), vertex_colors, edge_results);
        }
    });

    vertex_colors[from_vertex_id] = vertex_color::black;
}
