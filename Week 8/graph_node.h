#pragma once

#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

struct Edge;

struct GraphNode {
    char name;
    std::vector<Edge *> neighbors;
};

struct Edge {
    int weight;
    GraphNode *source;
    GraphNode *destination;
};

class Graph {
private:
    //all nodes in the graph
    std::vector<GraphNode *> nodes;
    //all edges in the graph
    std::vector<Edge *> edges;

public:
    //adds new vertex to graph
    void add_vertex(GraphNode *node);

    //adds new edge to graph and updates neighbors
    void add_edge(Edge *edge);

    //finds shortest path between source and destination nodes
    std::vector<GraphNode *> shortest_path(GraphNode *source, GraphNode *destination);

    //minimum spanning tree
    std::vector<Edge *> min_span_tree();

    //getter for nodes
    const std::vector<GraphNode *> &get_nodes() const {
        return nodes;
    }

    //getter for edges
    const std::vector<Edge *> &get_edges() const {
        return edges;
    }
};
