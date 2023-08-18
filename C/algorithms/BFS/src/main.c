#include "../hdr/graph_ds.h"
#include "hdr/queue_ds.h"
#include <stdio.h>

void BreadthFirstSearch(Graph* graph, int start) {
    Node* head = NULL;
    Node* tail = NULL;
    int current;

    Enqueue(&head, &tail, start);

    while (head != NULL) {
        current = head->value;
        Dequeue(&head, &tail);

        if (graph->visited[current] == 1)
            continue;
        graph->visited[current] = 1;
        printf("%d\n", current);

        Node* neighbour = graph->adj_list[current];
        while (neighbour != NULL) {
            Enqueue(&head, &tail, neighbour->value);
            neighbour = neighbour->next;
        }
    }

    DeleteQueue(&head, &tail);
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

    printf("BFS\n");
    BreadthFirstSearch(graph, 0);

    DeleteGraph(&graph);

    return 0;
}
