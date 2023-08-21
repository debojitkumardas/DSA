#include "hdr/queue_ds.h"
#include "hdr/graph_ds.h"
#include <stdio.h>

#define CTOI(ch) (int)ch - (int)'a'

int main(void) {
    int vertices = 8;
    Graph* graph = CreateGraph(vertices);

    AddEdge(&graph, CTOI('a'), CTOI('b'), 3);
    AddEdge(&graph, CTOI('a'), CTOI('c'), 6);
    AddEdge(&graph, CTOI('b'), CTOI('c'), 4);
    AddEdge(&graph, CTOI('b'), CTOI('d'), 4);
    AddEdge(&graph, CTOI('b'), CTOI('e'), 11);
    AddEdge(&graph, CTOI('c'), CTOI('d'), 8);
    AddEdge(&graph, CTOI('c'), CTOI('g'), 11);
    AddEdge(&graph, CTOI('d'), CTOI('e'), -4);
    AddEdge(&graph, CTOI('d'), CTOI('f'), 5);
    AddEdge(&graph, CTOI('d'), CTOI('g'), 2);
    AddEdge(&graph, CTOI('e'), CTOI('h'), 9);
    AddEdge(&graph, CTOI('f'), CTOI('h'), 1);
    AddEdge(&graph, CTOI('g'), CTOI('h'), 2);

    PrintGraph(graph);

    DeleteGraph(&graph);

    return 0;
}
