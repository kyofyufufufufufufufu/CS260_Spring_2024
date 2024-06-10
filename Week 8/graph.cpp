#include "graph_node.h"

//adds new vertex to the graph by adding pointer to the list of vertices.
void Graph::add_vertex(GraphNode *node) {
    nodes.push_back(node);
}

//adds ew edge to graph by adding edge pointer to list and updates neighbors
void Graph::add_edge(Edge *edge) {
    edges.push_back(edge);
    edge->source->neighbors.push_back(edge);
    edge->destination->neighbors.push_back(edge);
}

//checks neighbor points and keeps track of shortest path
std::vector<GraphNode *> Graph::shortest_path(GraphNode *source, GraphNode *destination) {
    std::unordered_map<GraphNode *, int> distances;
    std::unordered_map<GraphNode *, GraphNode *> previous;
    auto cmp = [&distances](GraphNode *left, GraphNode *right) { return distances[left] > distances[right]; };
    std::priority_queue<GraphNode *, std::vector<GraphNode *>, decltype(cmp)> queue(cmp);

    for (auto node : nodes) {
        distances[node] = INT_MAX;
        previous[node] = nullptr;
    }

    distances[source] = 0;
    queue.push(source);

    while (!queue.empty()) {
        auto current = queue.top();
        queue.pop();

        if (current == destination) break;

        for (auto edge : current->neighbors) {
            auto neighbor = (edge->source == current) ? edge->destination : edge->source;
            int new_dist = distances[current] + edge->weight;

            if (new_dist < distances[neighbor]) {
                distances[neighbor] = new_dist;
                previous[neighbor] = current;
                queue.push(neighbor);
            }
        }
    }

    //creating shortest path from source to destination
    std::vector<GraphNode *> path;
    for (GraphNode *at = destination; at != nullptr; at = previous[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

//minimum spanning tree
std::vector<Edge *> Graph::min_span_tree() {
    std::vector<Edge *> mst;
    //sort edges by weight
    std::sort(edges.begin(), edges.end(), [](Edge *a, Edge *b) { return a->weight < b->weight; });
    std::unordered_map<GraphNode *, GraphNode *> parent;

    //find root of set with node
    auto find = [&parent](GraphNode *node) {
        while (parent[node] != node) {
            node = parent[node];
        }
        return node;
    };

    auto unite = [&parent, &find](GraphNode *a, GraphNode *b) {
        parent[find(a)] = find(b);
    };

    for (auto node : nodes) {
        parent[node] = node;
    }

    for (auto edge : edges) {
        auto root_source = find(edge->source);
        auto root_destination = find(edge->destination);

        if (root_source != root_destination) {
            mst.push_back(edge);
            unite(root_source, root_destination);
        }
    }

    return mst;
}