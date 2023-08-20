#include "../hdr/graph_ds.h"
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
        // --index;
        ++index;

        Node* neighbour = graph->adj_list[current];
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
    // int index = vertices - 1;
    int index = 0;
    int* order = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; ++i) {
        if (graph->visited[i] == 0) {
            index = DFSIter(graph, i, order, index);
        }
    }

    return order;
}

int main(void) {
    int vertices = 13;
    Graph* graph = CreateGraph(vertices);

    /*
     * Not a DAG
    AddEdge(&graph, 0, 2);
    AddEdge(&graph, 0, 3);
    AddEdge(&graph, 1, 2);
    AddEdge(&graph, 2, 3);
    AddEdge(&graph, 3, 5);
    AddEdge(&graph, 4, 1);
    AddEdge(&graph, 4, 2);
    AddEdge(&graph, 4, 5);
    AddEdge(&graph, 5, 2);
    */

    AddEdge(&graph, CTOI('a'), CTOI('d'));
    AddEdge(&graph, CTOI('b'), CTOI('d'));
    AddEdge(&graph, CTOI('c'), CTOI('a'));
    AddEdge(&graph, CTOI('c'), CTOI('b'));
    AddEdge(&graph, CTOI('d'), CTOI('g'));
    AddEdge(&graph, CTOI('d'), CTOI('h'));
    AddEdge(&graph, CTOI('e'), CTOI('a'));
    AddEdge(&graph, CTOI('e'), CTOI('d'));
    AddEdge(&graph, CTOI('e'), CTOI('f'));
    AddEdge(&graph, CTOI('f'), CTOI('j'));
    AddEdge(&graph, CTOI('f'), CTOI('k'));
    AddEdge(&graph, CTOI('g'), CTOI('i'));
    AddEdge(&graph, CTOI('h'), CTOI('i'));
    AddEdge(&graph, CTOI('h'), CTOI('j'));
    AddEdge(&graph, CTOI('i'), CTOI('l'));
    AddEdge(&graph, CTOI('j'), CTOI('l'));
    AddEdge(&graph, CTOI('j'), CTOI('m'));
    AddEdge(&graph, CTOI('k'), CTOI('j'));

    PrintGraph(graph);

    int* order = TopologicalSort(graph);

    if (order != NULL) {
        for (int v = 0; v < vertices; ++v)
            printf("%c ", ITOC(order[v]));
            // printf("%d ", order[v]);
        printf("\b\b\n");
    }

    free(order);
    DeleteGraph(&graph);

    return 0;
}
