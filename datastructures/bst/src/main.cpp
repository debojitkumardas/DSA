/**
 * @file main.cpp
 * @author Debojit Kumar Das
 * @brief This is the main file
 * @version 0.1
 * @date 2024-06-08
 *
 * @copyright Copyright (c) 2024
 */

#include "bst.h"

int main() {
    BST<int>* obj = new BST<int>();

    obj->InserNode(30);
    obj->InserNode(20);
    obj->InserNode(40);
    obj->InserNode(15);
    obj->InserNode(25);
    obj->InserNode(35);
    obj->InserNode(45);
    obj->InserNode(12);
    obj->InserNode(18);
    // obj->InserNode(22);
    obj->InserNode(28);
    obj->InserNode(32);
    obj->InserNode(38);
    obj->InserNode(42);
    obj->InserNode(48);

    obj->PrintBST();
    std::cout << "max value for node: " << obj->FindMax() << '\n';
    std::cout << "min value for node: " << obj->FindMin() << '\n';
    std::cout << "find value for node: " << obj->Search(25) << '\n';
    std::cout << "find successor for node (25): " << obj->Successor(25) << '\n';
    std::cout << "find predecessor for node (25): " << obj->Predecessor(25) << '\n';

    return 0;
}
