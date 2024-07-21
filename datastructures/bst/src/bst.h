/**
 * @file bst.h
 * @author Debojit Kumar Das
 * @brief This file defines and implements stack datastructure
 * @version 0.1
 * @date 2024-07-20
 *
 * @copyright Copyright (c) 2024
 */

#ifndef BST_H
#define BST_H

#include <cstddef>
#include <iostream>

/**
 * @brief Defines a class that holds data and pointers of a node.
 * @tparam T type to work with
 */
template <typename T>
class Node {
public:
    T data;         /**< data for node */
    Node* left;     /**< pointer pointing to the left child */
    Node* right;    /**< pointer pointing to the right child */
    Node* parent;   /**< pointer pointing to the parent */
};

/**
 * @brief Defines a class that implements the Binary Search Tree datastructure.
 * @tparam T type to work with
 */
template <typename T>
class BST {
public:
    /**
     * @brief Constructor for the stack class
     *
     * Initialises node pointer to null
     */
    BST<T>()
        : m_root(nullptr) {}

    /**
     * @brief Inserts data in BST
     * @param data data to be inserted in the child node
     */
    void InserNode(T data) {
        Node<T>* new_node = new Node<T>;

        if (new_node) {
            new_node->data = data;
            new_node->left = nullptr;
            new_node->right = nullptr;
            new_node->parent = nullptr;
        }

        if (IsEmpty()) {
            m_root = new_node;
        } else {
            Node<T>* temp = m_root;
            Node<T>* ntemp = nullptr;
            bool is_right = false;
            while (temp != nullptr) {
                ntemp = temp;
                if (data > temp->data) {
                    temp = temp->right;
                    is_right = true;
                } else {
                    temp = temp->left;
                    is_right = false;
                }
            }

            if (is_right) {
                ntemp->right = new_node;
            } else {
                ntemp->left = new_node;
            }
            new_node->parent = ntemp;
        }
    }

    T Search(T value) {
        Node<T>* temp = m_root;
        temp = mSearchNode(temp, value);
        if (temp) {
            return temp->data;
        } else {
            return -1;
        }
    }

    T FindMax() {
        Node<T>* temp = mFindMax(m_root);
        if (temp) {
            return temp->data;
        } else {
            return -1;
        }
    }

    T FindMin() {
        Node<T>* temp = mFindMin(m_root);
        if (temp) {
            return temp->data;
        } else {
            return -1;
        }
    }

    T Successor(T value) {
        Node<T>* temp = mSuccessor(mSearchNode(m_root, value), value);
        if (temp) {
            return temp->data;
        } else {
            return -1;
        }
    }

    T Predecessor(T value) {
        Node<T>* temp = mPredecessor(mSearchNode(m_root, value), value);
        if (temp) {
            return temp->data;
        } else {
            return -1;
        }
    }

    /**
     * @brief Removes data from BST
     */
    void RemoveNode() {
        if (!IsEmpty()) {
        }
    }

    /**
     * @brief Checks whether the BST is empty
     * @return Returns true if the BST is empty otherwise returns false
     */
    bool IsEmpty() const {
        if (m_root != nullptr) {
            return false;
        }

        return true;
    }

    /**
     * @brief PrintBST  Prints the BST given choice
     */
    void PrintBST(int ch = -1) {
        if (ch == -1) {
            Node<T>* temp = m_root;
            std::cout << "BST Nodes In Order\n";
            mPrintInOrder(temp);
            std::cout << '\n';
            temp = m_root;
            std::cout << "BST Nodes Pre Order\n";
            mPrintPreOrder(temp);
            std::cout << '\n';
            temp = m_root;
            std::cout << "BST Nodes Post Order\n";
            mPrintPostOrder(temp);
            std::cout << '\n';
        } else {
            if (ch == 1) {
                Node<T>* temp = m_root;
                std::cout << "BST Nodes In Order\n";
                mPrintInOrder(temp);
                std::cout << '\n';
            } else if (ch == 2) {
                Node<T>* temp = m_root;
                std::cout << "BST Nodes Pre Order\n";
                mPrintPreOrder(temp);
                std::cout << '\n';
            } else if (ch == 3) {
                Node<T>* temp = m_root;
                std::cout << "BST Nodes Post Order\n";
                mPrintPostOrder(temp);
                std::cout << '\n';
            } else {
                std::cout << "Wrong option\n";
            }
        }
    }

    /**
     * @brief Destructor for the stack class
     *
     * Frees up the resources used by the stack class
     */
    ~BST<T>();

private:
    /**
     * @brief SearchNode BST for a given value
     * @param data  : value to be searched
     * @return      : returns pointer to node (child) if found or returns null
     */
    Node<T>* mSearchNode(Node<T>* root, T data) {
        while (root != nullptr) {
            if (data == root->data) {
                return root;
            } else if (data > root->data) {
                root = root->right;
            } else {
                root = root->left;
            }
        }

        return nullptr;
    }

    /**
     * @brief FindMax Finds the max value of nodes in BST
     * @return  Returns the max value in BST
     */
    Node<T>* mFindMax(Node<T>* root) {
        Node<T>* temp = root;
        T tempv = root->data;
        while (root != nullptr) {
            if (tempv < root->data) {
                tempv = root->data;
                temp = root;
            }
            root = root->right;
        }

        return temp;
    }

    /**
     * @brief FindMin Finds the min value of nodes in BST
     * @return  Returns the min value in BST
     */
    Node<T>* mFindMin(Node<T>* root) {
        Node<T>* temp = root;
        T tempv = root->data;
        while (root != nullptr) {
            if (tempv > root->data) {
                tempv = root->data;
                temp = root;
            }
            root = root->left;
        }

        return temp;
    }

    /**
     * @brief mPrintInOrder Prints the nodes In Order
     * @param root  : root node of BST
     */
    void mPrintInOrder(Node<T>* root) {
        if (root == nullptr) {
            return;
        }
        mPrintInOrder(root->left);
        std::cout << root->data << ' ';
        mPrintInOrder(root->right);
    }

    /**
     * @brief mPrintPreOrder Prints the nodes Pre Order
     * @param root  : root node of BST
     */
    void mPrintPreOrder(Node<T>* root) {
        if (root == nullptr) {
            return;
        }
        std::cout << root->data << ' ';
        mPrintInOrder(root->left);
        mPrintInOrder(root->right);
    }

    /**
     * @brief mPrintPostOrder Prints the nodes Post Order
     * @param root  : root node of BST
     */
    void mPrintPostOrder(Node<T>* root) {
        if (root == nullptr) {
            return;
        }
        mPrintInOrder(root->left);
        mPrintInOrder(root->right);
        std::cout << root->data << ' ';
    }

    Node<T>* mSuccessor(Node<T>* root, T data) {
        if (root == nullptr) {
            return nullptr;
        }

        Node<T>* temp = nullptr;
        if (root->right != nullptr) {
            temp = mFindMin(root->right);
        } else {
            while (data >= root->data) {
                root = root->parent;
            }
            temp = root;
            temp = mFindMax(temp->left) != nullptr ? root : nullptr;
        }

        return temp;

    }

    Node<T>* mPredecessor(Node<T>* root, T data) {
        if (root == nullptr) {
            return nullptr;
        }

        Node<T>* temp = nullptr;
        if (root->left != nullptr) {
            temp = mFindMax(root->left);
        } else {
            while (data <= root->data) {
                root = root->parent;
            }
            temp = root;
            temp = mFindMin(temp->right) != nullptr ? root : nullptr;
        }

        return temp;

    }

private:
    Node<T>* m_root;    /**< Node to hold data and pointer to next node for stack */
};

#endif // !BST_H
