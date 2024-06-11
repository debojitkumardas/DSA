#ifndef STACK_H
#define STACK_H

/**
 *
 */
template <typename T>
class Node {
public:
    T m_data;
    Node* m_next;
};

/**
 */
template <typename T>
class Stack {
public:
    Stack<T>()
        : m_head(nullptr) {}

    ~Stack<T>() {
        while (!IsEmpty()) {
            Node<T>* temp = m_head;
            m_head = m_head->m_next;
            delete temp;
            temp = nullptr;
        }
    }

    void Push(T data) {
        Node<T>* new_node = new Node<T>;

        if (new_node) {
            new_node->m_data = data;
            new_node->m_next = nullptr;
        }

        if (m_head) {
            new_node->m_next = m_head;
        }
        m_head = new_node;
    }

    T Pop() {
        if (m_head) {
            Node<T>* temp = m_head;
            T retval = temp->m_data;
            m_head = m_head->m_next;
            delete temp;
            temp = nullptr;

            return retval;
        }

        return {};
    }

    bool IsEmpty() const {
        if (m_head) {
            return false;
        }

        return true;
    }

    T Peek() {
        if (m_head) {
            return m_head->m_data;
        }

        return {};
    }

private:
    Node<T>* m_head;
};

#endif // !STACK_H
