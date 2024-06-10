#pragma once

struct GraphNode;

struct Edge {
    int weight;
    GraphNode *source;
    GraphNode *destination;
};