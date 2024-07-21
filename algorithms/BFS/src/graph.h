#ifndef GRAPH_H
#define GRAPH_H

#include <cstddef>
#include <iostream>

template <typename T>
class Node {
public:
    Node<T>()
    : vertex{}, next{nullptr} {}

    Node<T>* CreateNode(T vert) {
        Node<T>* new_node = new Node<T>;

        if (new_node) {
            new_node->vertex = vert;
            new_node->next = nullptr;
        }

        return new_node;
    }

public:
    T vertex;
    Node<T>* next;
};

template <typename T>
class Graph {
public:
    Graph<T>()
    : m_vertices{0}, m_adjlist{nullptr} {}

    Graph<T>* CreateGraph(size_t vertices) {
        Graph<T>* new_graph = new Graph<T>;

        if (new_graph) {
            new_graph->m_vertices = vertices;
            new_graph->m_adjlist = new Node<T>*[vertices];

            for (size_t i = 0; i < vertices; ++i) {
                new_graph->m_adjlist[i] = nullptr;
            }
        }

        return new_graph;
    }

    void AddEdge(T source, T dest) {
        // add edge source to dest
        Node<T>* new_node = new Node<T>;
        new_node = new_node->CreateNode(dest);
        new_node->next = m_adjlist[source];
        m_adjlist[source] = new_node;

        // add edge dest to source
        new_node = new_node->CreateNode(source);
        new_node->next = m_adjlist[dest];
        m_adjlist[dest] = new_node;
    }

    Node<T>* GetNeighbours(size_t at) {
        return m_adjlist[at];
    }

    void PrintGraph() {
        for (size_t i = 0; i < m_vertices; ++i) {
            Node<T>* temp = m_adjlist[i];
            std::cout << "Vertex " << i << ": [";
            while (temp) {
                std::cout << temp->vertex << ", ";
                temp = temp->next;
            }
            std::cout << "\b\b]\n";
        }
    }

    void RemoveGraph() {
        for (size_t i = 0; i < m_vertices; ++i) {
            while (m_adjlist[i]) {
                Node<T>* temp = m_adjlist[i];
                m_adjlist[i] = m_adjlist[i]->next;
                delete temp;
                temp = nullptr;
            }
        }
    }

private:
    size_t m_vertices;
    Node<T>** m_adjlist;
};

#endif // !GRAPH_H
