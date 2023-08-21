#ifndef GRAPH_H
#define GRAPH_H

typedef struct Vertex Vertex;
typedef struct Graph Graph;

struct Vertex {
    int value;
    int weight;
    Vertex* next;
};

struct Graph {
    int num_vertices;
    int* visited;
    Vertex** adj_list;
};

Vertex* CreateVertex(int value, int weight);
Graph* CreateGraph(int vertices);
void AddEdge(Graph** graph, int src, int dest, int weight);
void PrintGraph(Graph* graph);
void DeleteGraph(Graph** graph);

#endif // !GRAPH_H
