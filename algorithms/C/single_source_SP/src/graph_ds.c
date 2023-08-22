#include "hdr/graph_ds.h"
#include <stdio.h>
#include <stdlib.h>

Vertex* CreateVertex(int value, int weight) {
    Vertex* new_node = malloc(sizeof(Vertex));

    if (new_node != NULL) {
        new_node->value = value;
        new_node->weight = weight;
        new_node->next = NULL;
    }

    return new_node;
}

Graph* CreateGraph(int vertices) {
    Graph* new_graph = malloc(sizeof(Graph));

    if (new_graph != NULL) {
        new_graph->num_vertices = vertices;
        new_graph->visited = malloc(vertices * sizeof(int));
        new_graph->adj_list = malloc(vertices * sizeof(Vertex*));

        for (int v = 0; v < vertices; ++v) {
            new_graph->visited[v] = 0;
            new_graph->adj_list[v] = NULL;
        }
    }

    return new_graph;
}

void AddEdge(Graph **graph, int src, int dest, int weight) {
    Vertex* node = CreateVertex(dest, weight);
    node->next = (*graph)->adj_list[src];
    (*graph)->adj_list[src] = node;
}

void PrintGraph(Graph *graph) {
    int vertices = graph->num_vertices;

    for (int v = 0; v < vertices; ++v) {
        printf("%d: [", v);
        Vertex* temp = graph->adj_list[v];

        if (temp == NULL)
            printf("  ");

        while (temp != NULL) {
            printf("(%d, %d), ", temp->value, temp->weight);
            temp = temp->next;
        }
        printf("\b\b]\n");
    }
}

void DeleteGraph(Graph **graph) {
    int vertices = (*graph)->num_vertices;

    free((*graph)->visited);

    for (int v = 0; v < vertices; ++v) {
        Vertex* temp = (*graph)->adj_list[v];
        while (temp != NULL) {
            Vertex* tmp = temp;
            temp = temp->next;
            free(tmp);
        }
    }

    free((*graph)->adj_list);
    free(*graph);
}
