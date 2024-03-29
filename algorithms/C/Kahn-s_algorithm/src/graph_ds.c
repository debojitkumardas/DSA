#include "../hdr/graph_ds.h"
#include <stdlib.h>
#include <stdio.h>

Graph* CreateGraph(int vertices) {
    Graph* new_graph = malloc(sizeof(Graph));

    if (new_graph != NULL) {
        new_graph->num_vertices = vertices;
        new_graph->visited = malloc(vertices * sizeof(int));
        new_graph->adj_list = malloc(vertices * sizeof(Node*));

        for (int v = 0; v < vertices; ++v) {
            new_graph->visited[v] = 0;
            new_graph->adj_list[v] = NULL;
        }
    }

    return new_graph;
}

void AddEdge(Graph **graph, int src, int dest) {
    Node* node = CreateNode(dest);
    node->next = (*graph)->adj_list[src];
    (*graph)->adj_list[src] = node;
}

void PrintGraph(Graph *graph) {
    int vertices = graph->num_vertices;

    for (int v = 0; v < vertices; ++v) {
        printf("%d: [", v);

        Node* temp = graph->adj_list[v];

        if (temp == NULL)
            printf("  ");

        while (temp != NULL) {
            printf("%d, ", temp->value);
            temp = temp->next;
        }
        printf("\b\b]\n");
    }
}

void DeleteGraph(Graph **graph) {
    int vertices = (*graph)->num_vertices;

    free((*graph)->visited);

    for (int v = 0; v < vertices; ++v) {
        Node* temp = (*graph)->adj_list[v];
        while (temp != NULL) {
            Node* tmp = temp;
            temp = temp->next;
            free(tmp);
        }
    }

    free((*graph)->adj_list);
    free(*graph);
}
