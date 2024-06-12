#ifndef QUEUE_H
#define QUEUE_H

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
class Queue {
public:
    Queue<T>()
        : m_head(nullptr), m_tail(nullptr) {}

    ~Queue<T>() {
        while (!IsEmpty()) {
            Node<T>* temp = m_head;
            m_head = m_head->m_next;
            delete temp;
            temp = nullptr;
        }
        if (m_head == nullptr) {
            delete m_tail;
            m_tail = nullptr;
        }
    }

    void Enqueue(T data) {
        Node<T>* new_node = new Node<T>;

        if (new_node) {
            new_node->m_data = data;
            new_node->m_next = nullptr;
        }

        if (IsEmpty()) {
            m_head = new_node;
        }

        if (m_tail) {
            m_tail->m_next = new_node;
        }
        m_tail = new_node;
    }

    T Dequeue() {
        if (!IsEmpty()) {
            Node<T>* temp_h = m_head;
            Node<T>* temp_t = m_tail;
            T retval = temp_t->m_data;
            while (temp_h->m_next != m_tail) {
                temp_h = temp_h->m_next;
            }
            m_tail = temp_h;
            delete temp_t;
            temp_t = nullptr;

            return retval;
        }

        if (m_tail == nullptr) {
            delete m_head;
            m_head = nullptr;
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
    Node<T>* m_tail;
};

#endif // !QUEUE_H
