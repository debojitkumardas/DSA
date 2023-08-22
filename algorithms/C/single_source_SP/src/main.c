#include "hdr/stack_ds.h"
#include "hdr/graph_ds.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CTOI(ch) (int)ch - (int)'a'
#define ITOC(in) (char)(in + (int)'a')

int DFSIter(Graph* graph, int start, int* order, int index) {
    int current;
    Node* head = NULL;

    PushNode(&head, start);

    while (head != NULL) {
        current = head->value;
        PopNode(&head);

        if (graph->visited[current] == 1)
            continue;
        graph->visited[current] = 1;

        order[index] = current;
        ++index;

        Vertex* neighbour = graph->adj_list[current];
        while (neighbour != NULL) {
            PushNode(&head, neighbour->value);
            neighbour = neighbour->next;
        }
    }

    DeleteStack(&head);

    return index;
}

int* TopologicalSort(Graph* graph) {
    int vertices = graph->num_vertices;
    int index = 0;
    int* order = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; ++i) {
        if (graph->visited[i] == 0) {
            index = DFSIter(graph, i, order, index);
        }
    }

    return order;
}

int* SSSPath(Graph* graph, int src, int dest) {
    int vertices = graph->num_vertices;
    int* order = TopologicalSort(graph);
    int* dist = malloc(vertices * sizeof(int));

    for (int v = 0; v < vertices; ++v)
        dist[v] = INFINITY;

    for (int v = src; v < vertices; ++v) {
        //
    }
}

int main(void) {
    int vertices = 8;
    Graph* graph = CreateGraph(vertices);

    AddEdge(&graph, CTOI('a'), CTOI('b'), 3);
    AddEdge(&graph, CTOI('a'), CTOI('c'), 6);
    AddEdge(&graph, CTOI('b'), CTOI('c'), 4);
    AddEdge(&graph, CTOI('b'), CTOI('d'), 4);
    AddEdge(&graph, CTOI('b'), CTOI('e'), 11);
    AddEdge(&graph, CTOI('c'), CTOI('d'), 8);
    AddEdge(&graph, CTOI('c'), CTOI('g'), 11);
    AddEdge(&graph, CTOI('d'), CTOI('e'), -4);
    AddEdge(&graph, CTOI('d'), CTOI('f'), 5);
    AddEdge(&graph, CTOI('d'), CTOI('g'), 2);
    AddEdge(&graph, CTOI('e'), CTOI('h'), 9);
    AddEdge(&graph, CTOI('f'), CTOI('h'), 1);
    AddEdge(&graph, CTOI('g'), CTOI('h'), 2);

    PrintGraph(graph);

    int* order = TopologicalSort(graph);

    if (order != NULL) {
        for (int v = 0; v < vertices; ++v)
            printf("%c ", ITOC(order[v]));
        printf("\n");
    }

    free(order);

    DeleteGraph(&graph);

    return 0;
}
