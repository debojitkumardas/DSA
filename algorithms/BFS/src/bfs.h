#ifndef BFS_H
#define BFS_H

#include "graph.h"

template <typename T>
class DFS {
public:
    DFS(Graph<T>* graph, size_t nodes)
    : m_graph{graph}, m_nodes{nodes} {
        m_visited = new bool[nodes];

        for (size_t i = 0; i < nodes; ++i)
            m_visited[i] = false;
    }

    void Search(T at) {
        if (m_visited[at]) {
            return;
        }
        std::cout << "visiting: " << at << '\n';
        m_visited[at] = true;

        Node<T>* neighbours = m_graph->GetNeighbours(at);

        while (neighbours) {
            Search(neighbours->vertex);
            neighbours = neighbours->next;
        }
    }

    void RemoveRes() {
        delete m_visited;
        m_visited = nullptr;
    }

private:
    Graph<T>* m_graph;
    size_t m_nodes;
    bool* m_visited;
};

#endif // !BFS_H
