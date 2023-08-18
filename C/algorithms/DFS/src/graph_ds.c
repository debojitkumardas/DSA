#include "../hdr/graph_ds.h"
#include <stdio.h>
#include <stdlib.h>

Graph* CreateGraph(int vertices) {
    Graph* new_graph = malloc(sizeof(Graph));

    if (new_graph != NULL) {
        new_graph->num_vertices = vertices;
        new_graph->visited = malloc(vertices * sizeof(int));
        new_graph->adj_list = malloc(vertices * sizeof(Node*));

        for (int i = 0; i < vertices; ++i) {
            new_graph->visited[i] = 0;
            new_graph->adj_list[i] = NULL;
        }
    }

    return new_graph;
}

void AddEdge(Graph** graph, int src, int dest) {
    // making a connection from src to dest
    Node* node = CreateNode(dest);
    node->next = (*graph)->adj_list[src];
    (*graph)->adj_list[src] = node;

    // making a connection from dest to src
    node = CreateNode(src);
    node->next = (*graph)->adj_list[dest];
    (*graph)->adj_list[dest] = node;
}

void PrintGraph(Graph* graph) {
    int vertices = graph->num_vertices;

    for (int v = 0; v < vertices; ++v) {
        Node* temp = graph->adj_list[v];
        printf("%d: [", v);
        while (temp != NULL) {
            printf("%d, ", temp->value);
            temp = temp->next;
        }
        printf("\b\b]\n");
    }
}

void DeleteGraph(Graph** graph) {
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
