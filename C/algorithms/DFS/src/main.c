#include "../hdr/graph_ds.h"
#include "../hdr/2D_list_ds.h"
#include <stdio.h>
#include <stdlib.h>

int* DepthFirstSearchIter(Graph *graph, int start) {
    int* list = malloc(graph->num_vertices * sizeof(int));
    Node* head = NULL;

    PushNode(&head, start);

    for (int i = 0; i < graph->num_vertices; ++i) {
        list[i] = -1;
    }

    int current;
    int index = 0;

    while (head != NULL) {
        current = head->value;
        PopNode(&head);

        if (graph->visited[current] == 1)
            continue;
        graph->visited[current] = 1;

        list[index] = current;
        index++;

        Node* neighbour = graph->adj_list[current];
        while (neighbour != NULL) {
            PushNode(&head, neighbour->value);
            neighbour = neighbour->next;
        }
    }

    DeleteStack(&head);

    return list;
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

void FindConnectedComponents(Graph* graph) {
    // call DFS on every node
    // push the list of connected components to an array (that's how we get the set of island)
    // count the instances dfs is called (which will give the number of connected components)

    ListNode* head = NULL;
    int vertices = graph->num_vertices;
    int* list = NULL;
    int count = 0;

    for (int v = 0; v < vertices; ++v) {
        // call DFS on every Node
        if (graph->visited[v] == 0) {
            count++;
            list = DepthFirstSearchIter(graph, v);
            PushValue(&head, list, vertices);
            free(list);
        }
    }

    printf("The number of connected components is/are: %d\n", count);

    PrintList(head);

    DeleteList(&head);
}

int main(void) {
    Graph* graph = CreateGraph(18);

    /*
    AddEdge(&graph, 0, 1);
    AddEdge(&graph, 0, 2);
    AddEdge(&graph, 2, 4);
    AddEdge(&graph, 1, 4);
    AddEdge(&graph, 1, 3);
    AddEdge(&graph, 3, 5);
    */

    AddEdge(&graph, 0, 4);
    AddEdge(&graph, 0, 8);
    AddEdge(&graph, 0, 13);
    AddEdge(&graph, 0, 14);
    AddEdge(&graph, 4, 8);
    AddEdge(&graph, 8, 14);
    AddEdge(&graph, 14, 13);
    AddEdge(&graph, 6, 7);
    AddEdge(&graph, 6, 11);
    AddEdge(&graph, 7, 11);
    AddEdge(&graph, 1, 5);
    AddEdge(&graph, 5, 16);
    AddEdge(&graph, 5, 17);
    AddEdge(&graph, 2, 9);
    AddEdge(&graph, 2, 15);
    AddEdge(&graph, 3, 9);
    AddEdge(&graph, 9, 15);
    AddEdge(&graph, 10, 15);

    PrintGraph(graph);

    /*
    printf("Doing a depth first search traversal iteratively.\n");
    int* list = DepthFirstSearchIter(graph, 0);

    int visited = graph->num_vertices;
    for (int i = 0; i < visited; ++i)
        printf("%d\n", list[i]);
    free(list);
    */

    /*
    printf("Doing a depth first search traversal recursively.\n");
    DepthFirstSearchRec(graph, 0);
    */

    FindConnectedComponents(graph);

    DeleteGraph(&graph);

    return 0;
}
