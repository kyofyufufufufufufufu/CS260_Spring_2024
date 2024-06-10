#include <iostream>
#include "graph_node.h"

using std::cout;
using std::endl;

/*
Typical main test file. However these tests and more are included in the test_graph.cpp file.
*/

int main() {
    GraphNode A{'A'};
    GraphNode B{'B'};
    GraphNode C{'C'};
    GraphNode D{'D'};
    GraphNode E{'E'};
    GraphNode F{'F'};

    Edge AB{7, &A, &B};
    Edge AC{9, &A, &C};
    Edge AF{14, &A, &F};
    Edge BC{10, &B, &C};
    Edge BD{15, &B, &D};
    Edge CD{11, &C, &D};
    Edge CF{2, &C, &F};
    Edge DE{6, &D, &E};
    Edge EF{9, &E, &F};

    Graph graph;
    graph.add_vertex(&A);
    graph.add_vertex(&B);
    graph.add_vertex(&C);
    graph.add_vertex(&D);
    graph.add_vertex(&E);
    graph.add_vertex(&F);

    graph.add_edge(&AB);
    graph.add_edge(&AC);
    graph.add_edge(&AF);
    graph.add_edge(&BC);
    graph.add_edge(&BD);
    graph.add_edge(&CD);
    graph.add_edge(&CF);
    graph.add_edge(&DE);
    graph.add_edge(&EF);

    //shortest path test
    auto path = graph.shortest_path(&A, &E);
    cout << "Shortest path from A to E: ";
    for (auto node : path) {
        cout << node->name << " ";
    }
    cout << endl;

    //min spanning tree test
    auto mst = graph.min_span_tree();
    cout << "Minimum spanning tree edges: ";
    for (auto edge : mst) {
        cout << "(" << edge->source->name << "-" << edge->destination->name << ") ";
    }
    cout << endl;

    return 0;
}