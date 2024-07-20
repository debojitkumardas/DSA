/**
 * @file queue.h
 * @author Debojit Kumar Das
 * @brief This file defines and implements queue datastructure
 * @version 0.1
 * @date 2024-06-10
 *
 * @copyright Copyright (c) 2024
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

/**
 * @brief Defines a class that holds data and pointer to the next node.
 * @tparam T type to work with
 */
template <typename T>
class Node {
public:
    T data;         /**< data for node */
    Node* next;     /**< pointer pointing to the next node */
};

/**
 * @brief Defines a class that implements the queue datastructure.
 * @tparam T type to work with
 */
template <typename T>
class Queue {
public:
    /**
     * @brief Constructor for the queue class
     *
     * Initialises node pointer to null
     */
    Queue<T>()
        : m_head(nullptr), m_tail(nullptr), m_len(0) {}

    /**
     * @brief Destructor for the queue class
     *
     * Frees up the resources used by the queue class
     */
    ~Queue<T>() {
        while (!IsEmpty()) {
            Node<T>* temp_h = m_head;
            m_head = m_head->next;
            delete temp_h;
            temp_h = nullptr;
        }
        if (m_head == nullptr) {
            m_tail = nullptr;
        }
        m_len = 0;
    }

    /**
     * @brief Inserts data at front of the queue
     * @param data data to be pushed into the queue
     */
    void Enqueue(T data) {
        Node<T>* new_node = new Node<T>;

        if (new_node) {
            new_node->data = data;
            new_node->next = nullptr;
            ++m_len;
        }

        if (IsEmpty()) {
            m_head = new_node;
        } else {
            m_tail->next = new_node;
        }

        m_tail = new_node;
    }

    /**
     * @brief Removes data from front of the queue
     */
    void Dequeue() {
        if (!IsEmpty()) {
            Node<T>* temp_h = m_head;
            m_head = m_head->next;
            delete temp_h;
            temp_h = nullptr;
            --m_len;
        }
        if (IsEmpty()) {
            m_tail = nullptr;
        }
    }

    /**
     * @brief Checks whether the queue is empty
     * @return Returns true is the queue is empty otherwise returns false
     */
    bool IsEmpty() const {
        if (m_head) {
            return false;
        }

        return true;
    }

    /**
     * @brief Get the front element of queue without removing it
     * @return Returns the front element of the stack
     */
    T Peek() {
        if (!IsEmpty()) {
            return m_head->data;
        }

        return {};
    }

    /**
     * @brief Get the number of elements in the queue
     * @return Returns the number of the elements in the queue
     */
    size_t GetSize() {
        return m_len;
    }

private:
    Node<T>* m_head;    /**< Node to hold data and pointer to the front of the queue */
    Node<T>* m_tail;    /**< Node to hold data and pointer to the tail of the queue */
    size_t m_len;       /**< To count the number of elements in queue */
};

#endif // !QUEUE_H
