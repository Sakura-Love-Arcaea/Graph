#include "./headers/graph.h"


int main() {
    Graph *graph = createGraph();
    addVertex(graph, 'A');
    addVertex(graph, 'B');
    addVertex(graph, 'C');
    addVertex(graph, 'D');
    addVertex(graph, 'E');
    addVertex(graph, 'F');
    addVertex(graph, 'G');
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 5, 6);

    depthFirstTraversal(graph, 0);
    breadthFirstTraversal(graph, 0);



    return 0;
}
