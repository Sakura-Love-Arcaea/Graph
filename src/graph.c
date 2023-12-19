#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"
#include "../headers/queue.h"
#include "../headers/graph.h"

Graph *createGraph() {
    Graph* graph = (Graph *) malloc(sizeof(Graph));
    graph->vertexCount = 0;
    graph->adjacencyMatrix = (int **) malloc(sizeof(int *) * GRAPH_SIZE_MAX);
    for (int i = 0; i < GRAPH_SIZE_MAX; i++) {
        graph->adjacencyMatrix[i] = (int*) malloc(sizeof(int) * GRAPH_SIZE_MAX);
    }
    for (int i = 0; i < GRAPH_SIZE_MAX; i++) {
        for (int j = 0; j < GRAPH_SIZE_MAX; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
        printf("\n");
    }
    graph->Vertices = (Vertex **) malloc(sizeof(Vertex *) * GRAPH_SIZE_MAX);
    return graph;
}

void addVertex(Graph *graph, char label) {
    Vertex *vertex = (Vertex *) malloc(sizeof(Vertex));
    vertex->label = label;
    vertex->visited = 0;
    graph->Vertices[graph->vertexCount++] = vertex;
}
void reset(Graph *graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        graph->Vertices[i]->visited = UNVISITED;
    }
}
void addEdge(Graph *graph, int start, int end) {
    graph->adjacencyMatrix[start][end] = 1;
    graph->adjacencyMatrix[end][start] = 1;
}
void displayVertex(Graph *graph, int VertexIndex) {
    printf("%c ", graph->Vertices[VertexIndex]->label);
}
int getUnvisitedVertex(Graph *graph, int VertexIndex) {
    for (int i = 0; i < graph->vertexCount; i++) {
        if (graph->adjacencyMatrix[VertexIndex][i] == 1 && graph->Vertices[i]->visited == UNVISITED) {
            return i;
        }
    }
    return -1;
}

void depthFirstTraversal(Graph *graph, int startFrom) {
    graph->Vertices[startFrom]->visited = VISITED;
    displayVertex(graph, startFrom);
    Stack *stack = createStack();
    push(stack, startFrom);

    while(!StackIsEmpty(stack)) {
        for (;;) {
            int currentVertex = peek(stack);
            int getChild = getUnvisitedVertex(graph, currentVertex);
            if (getChild == -1) {
                pop(stack);
                break;
            }
            displayVertex(graph, getChild);
            push(stack, getChild);
            graph->Vertices[getChild]->visited = VISITED;
        }
    }
    printf("\n");
    reset(graph);
}

void breadthFirstTraversal(Graph *graph, int startFrom) {
    graph->Vertices[startFrom]->visited = VISITED;
    displayVertex(graph, startFrom);
    Queue *queue = createQueue();
    enqueue(queue, startFrom);
    while (!QueueIsEmpty(queue)) {
        for(;;) {
            int currentVertex = front(queue);
            int getChild = getUnvisitedVertex(graph, currentVertex);
            if (getChild == -1) {
                dequeue(queue);
                break;
            }
            displayVertex(graph, getChild);
            enqueue(queue, getChild);
            graph->Vertices[getChild]->visited = VISITED;
        }
    }
    printf("\n");
    reset(graph);
}