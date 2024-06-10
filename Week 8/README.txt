=================================================================================================
=================================================================================================

Graph Structure Design

GraphNode				Edge				Graph
     |					 |				  |

1. Mainly a location		1. path between locations	  1. has all the nodes and edges
2. Name				2. weight			  2. functions*
3. List of 'neighbors'

								*adding nodes and edges,
								 finding shortest path,
								 minimum spanning tree

== Sorry if this isn't exactly the diagram you want, I believe it works for what I'm trying to show!

Add Node and Edge: Quick and simple, like adding contacts or connections.

Shortest Path: Takes longer as it checks all routes smartly to find the shortest one, similar to finding the quickest way between friends' houses on a map.

Minimum Spanning Tree: Takes a bit longer due to sorting paths and efficiently connecting towns without creating loops, similar to setting up the cheapest road network.


Example: A graph that represents a dungeon in a game.

Graph Structure Design

    Vertices:
        Each node represents a room in the dungeon.

    Edges:
        Each edge is a corridor connecting two rooms.
        Edges' weights can represent the difficulty of the room.

Room1 --1-- Room2 --1-- Room3
  |         /  |         |
  2        2   1        1
  |       /    |       /
Room4 --1-- Room5 --1-- Room6

^^something like this

=================================================================================================

TESTING:


//test for adding vertices
void test_add_vertices() {
    Graph graph;
    GraphNode A{'A'};
    GraphNode B{'B'};
    
    graph.add_node(&A);
    graph.add_node(&B);
    
    std::cout << "Test Add Vertices: ";
    if (graph.get_nodes().size() == 2 && graph.get_nodes()[0] == &A && graph.get_nodes()[1] == &B) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

//test for adding edges
void test_add_edges() {
    Graph graph;
    GraphNode A{'A'};
    GraphNode B{'B'};
    graph.add_node(&A);
    graph.add_node(&B);

    Edge AB{7, &A, &B};
    graph.add_edge(&AB);

    std::cout << "Test Add Edges: ";
    if (graph.get_edges().size() == 1 && graph.get_edges()[0] == &AB && A.neighbors.size() == 1 && B.neighbors.size() == 1) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

int main() {
    std::cout << "Running tests..." << std::endl;
    test_add_vertices();
    test_add_edges();

    std::cout << "Tests completed." << std::endl;
    return 0;
}

=================================================================================================

FUNCTIONALITIES:

add vertex:

//adds new vertex to the graph by adding pointer to the list of vertices.
void Graph::add_vertex(GraphNode *node) {
    nodes.push_back(node);
}

add edge:

//adds ew edge to graph by adding edge pointer to list and updates neighbors
void Graph::add_edge(Edge *edge) {
    edges.push_back(edge);
    edge->source->neighbors.push_back(edge);
    edge->destination->neighbors.push_back(edge);
}

shortest path:

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


minimum spanning tree:

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

=================================================================================================

ANALYSIS:

Figuring out the shortest path between two points in the dungeon, say from one treasure room to another, with each path possibly being more or less difficult (weight). And when it comes to setting up the best network of passages to explore the dungeon efficiently, it's like laying out the most strategic routes, making going through the dungeon with as few obstacle as possible.

=================================================================================================

INPUTS & OUTPUTS:

Inputs:

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

// Test for finding the minimum spanning tree
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

Outputs:

Running tests...
Test Add Vertex: Passed
Test Add Edge: Passed
Test Shortest Path from A to E: Passed
Test Minimum Spanning Tree Edges: Passed
Tests completed.

