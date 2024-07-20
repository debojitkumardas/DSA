/**
 * @file dfs.h
 * @author Debojit Kumar Das
 * @brief This file defines and implements stack datastructure
 * @version 0.1
 * @date 2024-06-10
 *
 * @copyright Copyright (c) 2024
 */

#ifndef DFS_H
#define DFS_H

#include "graph.h"

/**
 * @brief Defines a class that holds data and pointer to the next node.
 * @tparam T type to work with
 */
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
    Graph<T>* m_graph;  /**< holds the graph data using adjacency list */
    size_t m_nodes;     /**< number of nodes in the graph */
    bool* m_visited;    /**< list of visited nodes in the graph */
};

#endif // !DFS_H
