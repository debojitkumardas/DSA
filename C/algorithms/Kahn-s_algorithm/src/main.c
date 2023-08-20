#include "hdr/graph_ds.h"
#include <stdio.h>
#include <stdlib.h>

int* KahnsAlgorithm(Graph* graph) {
    int vertices = graph->num_vertices;
    int* in_degree = malloc(vertices * sizeof(int));
    int* order = malloc(vertices * sizeof(int));
    int index = 0;
    int current;

    Node* head = NULL;
    Node* tail = NULL;

    for (int v = 0; v < vertices; ++v) {
        in_degree[v] = 0;
        order[v] = -1;
    }

    for (int v = 0; v < vertices; ++v) {
        Node* neighbour = graph->adj_list[v];
        while (neighbour != NULL) {
            in_degree[neighbour->value] += 1;
            neighbour = neighbour->next;
        }
    }

    for (int v = 0; v < vertices; ++v) {
        if (in_degree[v] == 0)
            Enqueue(&head, &tail, v);
    }

    while (head != NULL) {
        current = head->value;
        Dequeue(&head, &tail);

        order[index] = current;
        ++index;

        Node* neighbour = graph->adj_list[current];

        while (neighbour != NULL) {
            in_degree[neighbour->value] -= 1;
            if (in_degree[neighbour->value] == 0) {
                Enqueue(&head, &tail, neighbour->value);
            }
            neighbour = neighbour->next;
        }
    }

    free(in_degree);
    DeleteQueue(&head, &tail);

    if (index != vertices) {
        // graph contains cycle(s)
        free(order);
        return NULL;
    }

    return order;
}

int main(void) {
    int vertices = 6;
    Graph* graph = CreateGraph(vertices);

    /*
     * Not a DAG
     */
    AddEdge(&graph, 0, 2);
    AddEdge(&graph, 0, 3);
    AddEdge(&graph, 1, 2);
    AddEdge(&graph, 2, 3);
    AddEdge(&graph, 3, 5);
    AddEdge(&graph, 4, 1);
    AddEdge(&graph, 4, 2);
    AddEdge(&graph, 4, 5);
    AddEdge(&graph, 5, 2);

    /*
    AddEdge(&graph, 0, 2);
    AddEdge(&graph, 0, 3);
    AddEdge(&graph, 0, 6);
    AddEdge(&graph, 1, 4);
    AddEdge(&graph, 2, 6);
    AddEdge(&graph, 3, 1);
    AddEdge(&graph, 3, 4);
    AddEdge(&graph, 4, 5);
    AddEdge(&graph, 4, 8);
    AddEdge(&graph, 6, 7);
    AddEdge(&graph, 6, 11);
    AddEdge(&graph, 7, 4);
    AddEdge(&graph, 7, 12);
    AddEdge(&graph, 9, 2);
    AddEdge(&graph, 9, 10);
    AddEdge(&graph, 10, 6);
    AddEdge(&graph, 11, 12);
    AddEdge(&graph, 12, 8);
    */

    PrintGraph(graph);

    int* order = KahnsAlgorithm(graph);

    if (order != NULL) {
        for (int v = 0; v < vertices; ++v) {
            printf("%d ", order[v]);
        }
        printf("\b\n");
    }
    else {
        printf("Provided graph contains cycle. Topological ordering not possible.\n");
    }

    free(order);

    DeleteGraph(&graph);

    return 0;
}
