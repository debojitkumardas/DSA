#include "../hdr/graph_ds.h"
#include "hdr/queue_ds.h"
#include <stdio.h>

int Solve(int start, int end) {
    Node* head = NULL;
    Node* tail = NULL;

    Enqueue(&head, &tail, start);

    //
}

void ReconstructPath(int start, int end, int prev);

void BreadthFirstSearch(Graph* graph, int start, int end) {
    int prev = Solve(start, end);

    ReconstructPath(start, end, prev);
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

    DeleteGraph(&graph);

    return 0;
}
