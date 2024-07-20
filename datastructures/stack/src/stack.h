/**
 * @file stack.h
 * @author Debojit Kumar Das
 * @brief This file defines and implements stack datastructure
 * @version 0.1
 * @date 2024-06-08
 *
 * @copyright Copyright (c) 2024
 */

#ifndef STACK_H
#define STACK_H

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
 * @brief Defines a class that implements the stack datastructure.
 * @tparam T type to work with
 */
template <typename T>
class Stack {
public:
    /**
     * @brief Constructor for the stack class
     *
     * Initialises node pointer to null
     */
    Stack<T>()
        : m_head(nullptr), m_len(0) {}

    /**
     * @brief Destructor for the stack class
     *
     * Frees up the resources used by the stack class
     */
    ~Stack<T>() {
        while (!IsEmpty()) {
            Node<T>* temp = m_head;
            m_head = m_head->next;
            delete temp;
            temp = nullptr;
        }

        if (m_head) {
            delete m_head;
            m_head = nullptr;
        }
        m_len = 0;
    }

    /**
     * @brief Inserts data at top of the stack
     * @param data data to be pushed into the stack
     */
    void Push(T data) {
        Node<T>* new_node = new Node<T>;

        if (new_node) {
            new_node->data = data;
            new_node->next = nullptr;
            ++m_len;
        }

        if (!IsEmpty()) {
            new_node->next = m_head;
        }
        m_head = new_node;
    }

    /**
     * @brief Removes data from top of the stack
     */
    void Pop() {
        if (!IsEmpty()) {
            Node<T>* temp = m_head;
            m_head = m_head->next;
            delete temp;
            temp = nullptr;
            --m_len;
        }
    }

    /**
     * @brief Checks whether the stack is empty
     * @return Returns true is the stack is empty otherwise returns false
     */
    bool IsEmpty() const {
        if (m_head) {
            return false;
        }

        return true;
    }

    /**
     * @brief Get the top element of stack without removing it
     * @return Returns the top element of the stack
     */
    T Peek() {
        if (!IsEmpty()) {
            return m_head->data;
        }

        return {};
    }

    /**
     * @brief The number of elements in the stack
     * @return Returns the number of the elements in the stack
     */
    size_t GetSize() {
        return m_len;
    }

private:
    Node<T>* m_head;    /**< Node to hold data and pointer to next node for stack */
    size_t m_len;       /**< To count the number of elements in stack */
};

#endif // !STACK_H
