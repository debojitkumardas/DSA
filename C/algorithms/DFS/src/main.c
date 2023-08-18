#include "../hdr/graph_ds.h"
#include <stdio.h>
#include <stdlib.h>

void DepthFirstSearchIter(Graph *graph, int source) {
    Node* head = NULL;
    PushNode(&head, source);

    int current;

    while (head != NULL) {
        current = head->value;
        PopNode(&head);

        if (graph->visited[current] == 1)
            continue;
        graph->visited[current] = 1;

        printf("%d\n", current);

        Node* neighbour = graph->adj_list[current];
        while (neighbour != NULL) {
            PushNode(&head, neighbour->value);
            neighbour = neighbour->next;
        }
    }

    DeleteStack(&head);
}

void DepthFirstSearchRec(Graph *graph, int current) {
    if (graph->visited[current] == 1)
        return;
    graph->visited[current] = 1;

    printf("%d\n", current);

    Node* neighbour = graph->adj_list[current];
    while (neighbour != NULL) {
        DepthFirstSearchRec(graph, neighbour->value);
        neighbour = neighbour->next;
    }
}

int main(void) {
    Graph* graph = CreateGraph(6);

    AddEdge(&graph, 0, 1);
    AddEdge(&graph, 0, 2);
    AddEdge(&graph, 2, 4);
    AddEdge(&graph, 1, 4);
    AddEdge(&graph, 1, 3);
    AddEdge(&graph, 3, 5);

    PrintGraph(graph);

    /*
    printf("Doing a depth first search traversal iteratively.\n");
    DepthFirstSearchIter(graph, 0);
    */

    printf("Doing a depth first search traversal recursively.\n");
    DepthFirstSearchRec(graph, 0);

    DeleteGraph(&graph);

    return 0;
}
