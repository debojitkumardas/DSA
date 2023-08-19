#include "../hdr/graph_ds.h"
#include <stdio.h>
#include <stdlib.h>

int* BreadthFirstSearch(Graph* graph, int start) {
    Node* head = NULL;
    Node* tail = NULL;
    int* list = malloc(graph->num_vertices * sizeof(int));
    int current;
    int index = 0;

    Enqueue(&head, &tail, start);

    for (int i = 0; i < graph->num_vertices; ++i)
        list[i] = -1;

    while (head != NULL) {
        current = head->value;
        Dequeue(&head, &tail);

        if (graph->visited[current] == 1)
            continue;
        graph->visited[current] = 1;

        list[index] = current;
        index++;

        Node* neighbour = graph->adj_list[current];
        while (neighbour != NULL) {
            Enqueue(&head, &tail, neighbour->value);
            neighbour = neighbour->next;
        }
    }

    DeleteQueue(&head, &tail);

    return list;
}

int* Solve(Graph* graph, int start) {
    Node* head = NULL;
    Node* tail = NULL;
    int* prev = malloc(graph->num_vertices * sizeof(int));
    int current;

    Enqueue(&head, &tail, start);

    for (int i = 0; i < graph->num_vertices; ++i) {
        prev[i] = -1;
    }

    graph->visited[start] = 1;

    while (head != NULL) {
        current = head->value;
        Dequeue(&head, &tail);

        Node* neighbour = graph->adj_list[current];
        while (neighbour != NULL) {
            if (graph->visited[neighbour->value] == 0) {
                Enqueue(&head, &tail, neighbour->value);
                graph->visited[neighbour->value] = 1;
                prev[neighbour->value] = current;
            }
            neighbour = neighbour->next;
        }
    }

    DeleteQueue(&head, &tail);

    return prev;
}

int* ReconstructPath(int start, int end, int* prev) {
    Node* head = NULL;
    Node* tail = NULL;
    int count = 0;

    for (int at = end; at != -1; at = prev[at]) {
        Enqueue(&head, &tail, at);
        count++;
    }

    int* path = malloc(count * sizeof(int));

    Node* temp = head;
    int index = count - 1;
    while (temp != NULL) {
        path[index] = temp->value;
        index--;
        temp = temp->next;
    }

    free(temp);
    DeleteQueue(&head, &tail);

    if (path[0] == start)
        return path;

    free(path);

    return NULL;
}

int* ShortestPath(Graph* graph, int start, int end) {
    int* prev = Solve(graph, start);

    int* path = ReconstructPath(start, end, prev);

    free(prev);

    return path;
}


int main(void) {
    Graph* graph = CreateGraph(13);

    /*
    AddEdge(&graph, 0, 1);
    AddEdge(&graph, 0, 2);
    AddEdge(&graph, 2, 4);
    AddEdge(&graph, 1, 4);
    AddEdge(&graph, 1, 3);
    AddEdge(&graph, 3, 5);
    */

    AddEdge(&graph, 0, 7);
    AddEdge(&graph, 0, 9);
    AddEdge(&graph, 0, 11);
    AddEdge(&graph, 1, 10);
    AddEdge(&graph, 1, 8);
    AddEdge(&graph, 2, 3);
    AddEdge(&graph, 2, 12);
    AddEdge(&graph, 3, 4);
    AddEdge(&graph, 3, 7);
    AddEdge(&graph, 5, 6);
    AddEdge(&graph, 6, 7);
    AddEdge(&graph, 7, 11);
    AddEdge(&graph, 8, 9);
    AddEdge(&graph, 8, 12);
    AddEdge(&graph, 9, 10);

    PrintGraph(graph);

    /*
    printf("BFS\n");
    int* list = BreadthFirstSearch(graph, 0);

    for (int i = 0; i < graph->num_vertices; ++i)
        printf("%d\n", list[i]);
    free(list);
    */

    int start = 0;
    int end = 3;

    int* path = ShortestPath(graph, start, end);

    // The following is a bit dodgy code need for make it better
    if (path != NULL) {
        while (*path != end) {
            printf("%d - ", *path);
            path++;
        }
        printf("%d\n", *path);
    }
    else {
        printf("Path doesn't exist!!\n");
    }

    // this is the dodgy part
    // as to free the memory it has to point to the original location
    while (*path != start) {
        path--;
    }

    free(path);
    DeleteGraph(&graph);

    return 0;
}
