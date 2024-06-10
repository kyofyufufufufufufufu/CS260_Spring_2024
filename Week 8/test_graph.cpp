#include <iostream>
#include "graph_node.h"

//test for adding vertices
void test_add_vertex() {
    Graph graph;
    GraphNode A{'A'};
    GraphNode B{'B'};

    graph.add_vertex(&A);
    graph.add_vertex(&B);

    std::cout << "Test Add Vertex: ";
    if (graph.get_nodes().size() == 2 && graph.get_nodes()[0] == &A && graph.get_nodes()[1] == &B) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

//test for adding edges
void test_add_edge() {
    Graph graph;
    GraphNode A{'A'};
    GraphNode B{'B'};
    graph.add_vertex(&A);
    graph.add_vertex(&B);

    Edge AB{7, &A, &B};
    graph.add_edge(&AB);

    std::cout << "Test Add Edge: ";
    if (graph.get_edges().size() == 1 && graph.get_edges()[0] == &AB &&
        A.neighbors.size() == 1 && B.neighbors.size() == 1 &&
        A.neighbors[0] == &AB && B.neighbors[0] == &AB) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

//test for finding the shortest path
void test_shortest_path() {
    Graph graph;
    GraphNode A{'A'};
    GraphNode B{'B'};
    GraphNode C{'C'};
    GraphNode D{'D'};
    GraphNode E{'E'};
    graph.add_vertex(&A);
    graph.add_vertex(&B);
    graph.add_vertex(&C);
    graph.add_vertex(&D);
    graph.add_vertex(&E);

    Edge AB{1, &A, &B};
    Edge BC{1, &B, &C};
    Edge CD{1, &C, &D};
    Edge DE{1, &D, &E};
    graph.add_edge(&AB);
    graph.add_edge(&BC);
    graph.add_edge(&CD);
    graph.add_edge(&DE);

    auto path = graph.shortest_path(&A, &E);

    std::cout << "Test Shortest Path from A to E: ";
    std::vector<GraphNode *> expected_path = {&A, &B, &C, &D, &E};
    bool passed = (path.size() == expected_path.size());
    for (size_t i = 0; i < path.size(); ++i) {
        if (path[i] != expected_path[i]) {
            passed = false;
            break;
        }
    }
    if (passed) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

//min spanning tree
void test_min_span_tree() {
    Graph graph;
    GraphNode A{'A'};
    GraphNode B{'B'};
    GraphNode C{'C'};
    GraphNode D{'D'};
    GraphNode E{'E'};
    graph.add_vertex(&A);
    graph.add_vertex(&B);
    graph.add_vertex(&C);
    graph.add_vertex(&D);
    graph.add_vertex(&E);

    Edge AB{1, &A, &B};
    Edge BC{1, &B, &C};
    Edge CD{1, &C, &D};
    Edge DE{1, &D, &E};
    Edge AE{1, &A, &E};
    graph.add_edge(&AB);
    graph.add_edge(&BC);
    graph.add_edge(&CD);
    graph.add_edge(&DE);
    graph.add_edge(&AE);

    auto mst = graph.min_span_tree();

    std::cout << "Test Minimum Spanning Tree Edges: ";
    std::vector<Edge *> expected_mst = {&AB, &BC, &CD, &DE};
    bool passed = (mst.size() == expected_mst.size());
    for (size_t i = 0; i < mst.size(); ++i) {
        if (mst[i] != expected_mst[i]) {
            passed = false;
            break;
        }
    }
    if (passed) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

int main() {
    std::cout << "Running tests..." << std::endl;
    test_add_vertex();
    test_add_edge();
    test_shortest_path();
    test_min_span_tree();
    std::cout << "Tests completed." << std::endl;
    return 0;
}
