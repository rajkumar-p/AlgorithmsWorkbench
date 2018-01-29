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

std::list<std::string> topological_sort(graph &G)
{
    std::map<std::string, vertex_search_prop> dfs_results = dfs(G);
    std::vector<std::tuple<std::string, size_t>> ids_and_end_time;

    for (const std::pair<std::string, vertex_search_prop> &p : dfs_results) {
        ids_and_end_time.push_back(std::make_tuple(p.first, p.second.end_time()));
    }

    std::sort(ids_and_end_time.begin(), ids_and_end_time.end(), 
        [] (const std::tuple<std::string, size_t> &e1, const std::tuple<std::string, size_t> &e2) {
        return std::get<1>(e1) > std::get<1>(e2);
    });

    std::list<std::string> sorted_ids;
    for (const std::tuple<std::string, size_t> &t : ids_and_end_time) {
        sorted_ids.push_back(std::get<0>(t));
    }

    return sorted_ids;
}

std::map<std::string, vertex_search_prop> dfs_custom_order(graph &G, std::vector<std::string> vertices_order)
{
    std::map<std::string, vertex_search_prop> dfs_results;
    std::atomic<size_t> time_counter(0);

    G.foreach_vertex([&dfs_results] (std::string id) {
        dfs_results.emplace(id, vertex_search_prop());
    });

    for (const std::string &id : vertices_order) {
        if (dfs_results[id].color() == vertex_color::white) {
            dfs_walk(G, id, time_counter, dfs_results);
        }
    }

    return dfs_results;
}

std::map<std::string, vertex_search_prop> strongly_connected_components(graph &G)
{
    std::map<std::string, vertex_search_prop> dfs_results;
    dfs_results = dfs(G);

    graph GT;
    transverse_of(G, GT);

    std::vector<std::tuple<std::string, size_t>> ids_and_end_time;
    for (const std::pair<std::string, vertex_search_prop> &p : dfs_results) {
        ids_and_end_time.push_back(std::make_tuple(p.first, p.second.end_time()));
    }

    std::sort(ids_and_end_time.begin(), ids_and_end_time.end(), 
        [] (const std::tuple<std::string, size_t> &e1, const std::tuple<std::string, size_t> &e2) {
        return std::get<1>(e1) > std::get<1>(e2);
    });

    std::vector<std::string> vertices_order;
    for (const std::tuple<std::string, size_t> &t : ids_and_end_time) {
        vertices_order.push_back(std::get<0>(t));
    }

    dfs_results.clear();
    dfs_results = dfs_custom_order(GT, vertices_order);

    return dfs_results;
}

void transverse_of(graph &G, graph &GT)
{
    G.foreach_vertex([&GT] (const std::string id) {
        GT.add_vertex(id);
    });

    G.foreach_edge([&GT] (edge e) {
        GT.add_directed_edge(e.to(), e.from());
    });
}

void mst_prim(graph &G, const std::string source_id, graph &output_tree)
{
    struct vertex { 
        std::string id;
        size_t key;
        std::string parent;
    };

    struct compare {
        bool operator()(vertex &v1, vertex &v2) {
            return v1.key > v2.key;
        }
    };

    std::map<std::string, bool> visited;
    std::map<std::string, int> vertex_weights;

    std::priority_queue<vertex, std::vector<vertex>, compare> max_pq;
    G.foreach_vertex([&max_pq, &source_id, &visited, &vertex_weights] (const std::string id) {
        vertex v;
        v.id = id;
        v.parent = "NIL";
        v.key = id == source_id ? 0 : INT32_MAX;

        max_pq.push(v);
        visited[id] = false;
        vertex_weights[id] = v.key;
    });

    while (!max_pq.empty()) {
        vertex v = max_pq.top();
        max_pq.pop();

        if (!visited[v.id]) {
            G.foreach_adj_edge(v.id, [&max_pq, &visited, &vertex_weights] (edge e) {
                if (!visited[e.to()] && e.weight() < vertex_weights[e.to()]) {
                    vertex v;
                    v.id = e.to();
                    v.parent = e.from();
                    v.key = e.weight();

                    max_pq.push(v);

                    vertex_weights[e.to()] = e.weight();
                }
            });
            visited[v.id] = true;

            output_tree.add_vertex(v.id);
            if (v.parent != "NIL") {
                output_tree.add_edge(v.parent, v.id, v.key);
            }
        }

    }
}

bool bellman_ford(graph &G, std::string source_id, std::map<std::string, vertex_search_prop> &results)
{
    G.foreach_vertex([&results] (std::string id) {
        vertex_search_prop vsp;
        vsp.set_parent("NIL");
        vsp.set_dist_from_root(INT32_MAX);

        results.emplace(id, vsp);
    });

    if (results.find(source_id) == results.end()) {
        return true;
    }

    results[source_id].set_dist_from_root(0);
    size_t vertex_count = G.get_vertex_count();
    for (size_t i = 1; i <= vertex_count - 1; ++i) {
        G.foreach_edge([&results] (edge e) {
            if (results[e.from()].dist_from_root() + e.weight() < results[e.to()].dist_from_root()) {
                results[e.to()].set_dist_from_root(results[e.from()].dist_from_root() + e.weight());
                results[e.to()].set_parent(e.from());
            }
        });
    }

    bool contains_neg_cycle = false;
    G.foreach_edge([&results, &contains_neg_cycle] (edge e) {
        if (results[e.from()].dist_from_root() + e.weight() < results[e.to()].dist_from_root()) {
            contains_neg_cycle = true;
            return;
        }
    });

    if (contains_neg_cycle) { return false; }

    return true;
}

std::map<std::string, vertex_search_prop> dag_shortest_path(graph &DAG, std::string source_id)
{
    std::map<std::string, vertex_search_prop> results;

    DAG.foreach_vertex([&results] (std::string id) {
        vertex_search_prop vsp;
        vsp.set_parent("NIL");
        vsp.set_dist_from_root(INT32_MAX);

        results.emplace(id, vsp);
    });

    std::list<std::string> top_sorted_vertices = topological_sort(DAG);
    for (const std::string &id : top_sorted_vertices) {
        DAG.foreach_adj_edge(id, [&results] (edge e) {
            if (results[e.from()].dist_from_root() + e.weight() < results[e.to()].dist_from_root()) {
                results[e.to()].set_dist_from_root(results[e.from()].dist_from_root() + e.weight());
                results[e.to()].set_parent(e.from());
            }
        });
    }

    return results;
}

std::map<std::string, vertex_search_prop> djikstra(graph &G, std::string source_id)
{
    struct vertex { 
        std::string id;
        size_t key;
        std::string parent;
    };

    struct compare {
        bool operator()(vertex &v1, vertex &v2) {
            return v1.key > v2.key;
        }
    };

    std::map<std::string, bool> visited;
    std::map<std::string, int> vertex_weights;

    std::priority_queue<vertex, std::vector<vertex>, compare> max_pq;
    G.foreach_vertex([&max_pq, &source_id, &visited, &vertex_weights] (const std::string id) {
        vertex v;
        v.id = id;
        v.parent = "NIL";
        v.key = id == source_id ? 0 : INT32_MAX;

        max_pq.push(v);
        visited[id] = false;
        vertex_weights[id] = v.key;
    });

    std::map<std::string, vertex_search_prop> results;
    while (!max_pq.empty()) {
        vertex v = max_pq.top();
        max_pq.pop();

        if (!visited[v.id]) {
            G.foreach_adj_edge(v.id, [&max_pq, &visited, &vertex_weights] (edge e) {
                if (!visited[e.to()] && vertex_weights[e.from()] + e.weight() < vertex_weights[e.to()]) {
                    vertex v;
                    v.id = e.to();
                    v.parent = e.from();
                    v.key = vertex_weights[e.from()] + e.weight();

                    max_pq.push(v);

                    vertex_weights[e.to()] = vertex_weights[e.from()] + e.weight();
                }
            });
            visited[v.id] = true;

            vertex_search_prop vsp;
            vsp.set_dist_from_root(vertex_weights[v.id]);
            vsp.set_parent(v.parent);

            results.emplace(v.id, vsp);
        }
    }

    return results;
}