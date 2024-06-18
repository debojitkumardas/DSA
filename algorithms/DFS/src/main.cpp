#include "graph.h"
#include "dfs.h"

int main() {
    size_t vertices = 5;
    Graph<int>* graph = new Graph<int>();
    graph = graph->CreateGraph(vertices);

    graph->AddEdge(0, 1);
    graph->AddEdge(0, 2);
    graph->AddEdge(1, 3);
    graph->AddEdge(2, 3);
    graph->AddEdge(3, 4);

    graph->PrintGraph();

    DFS<int> obj(graph, vertices);

    obj.Search(0);
    obj.RemoveRes();

    graph->RemoveGraph();

    return 0;
}
