#include "graph_algorithms.hpp"
#include <queue>

// vertex_search_details *get_vertex_search_details(std::map<std::string, vertex_search_details *> *search_details, std::string id)
// {
//     std::map<std::string, vertex_search_details *>::iterator it;
//     it = search_details->find(id);

//     if (it != search_details->end()) {
//         return it->second;
//     }

//     return nullptr;
// }

// std::map<std::string, vertex_search_details *> *bfs(graph *G, vertex *source)
// {
//     std::map<std::string, vertex_search_details *> *search_details = new std::map<std::string, vertex_search_details *>();

//     G->foreach_vertex([search_details](const vertex *v) {
//         vertex_search_details *vsd = new vertex_search_details(v->id());
//         vsd->set_color(vertex_color::white);
//         vsd->set_dist_from_root(0);
//         vsd->set_parent(nullptr);

//         search_details->insert(std::pair<std::string, vertex_search_details *>(vsd->id(), vsd));
//     });

//     vertex_search_details *vsd = get_vertex_search_details(search_details, source->id());
//     vsd->set_color(vertex_color::gray);

//     std::queue<vertex *> Q = std::queue<vertex *>();
//     Q.push(source);

//     while (!Q.empty()) {
//         vertex *v = Q.front();
//         std::list<vertex *> *adj_vertices = G->get_adj_vertices_to(v);

//         for (vertex *av : *adj_vertices) {
//             vertex_search_details *av_vsd = get_vertex_search_details(search_details, av->id());
//             if (av_vsd != nullptr) {
//                 av_vsd->set_color(vertex_color::gray);
//                 av_vsd->set_dist_from_root(vsd->dist_from_root() + 1);
//                 av_vsd->set_parent(v);
//             }

//             Q.push(av);
//         }

//         vsd->set_color(vertex_color::black);
//     }

//     return search_details;
// }