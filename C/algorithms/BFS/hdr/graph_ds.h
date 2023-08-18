#ifndef GRAPH_DS
#define GRAPH_DS

#include "queue_ds.h"

typedef struct Graph Graph;

struct Graph {
    int num_vertices;
    int* visited;
    Node** adj_list;
};

Graph* CreateGraph(int vertices);
void AddEdge(Graph** graph, int src, int dest);
void PrintGraph(Graph* graph);
void DeleteGraph(Graph** graph);

#endif // !GRAPH_DS
