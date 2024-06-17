/**
 * @file main.cpp
 * @author Debojit Kumar Das
 * @brief This is the main file
 * @version 0.1
 * @date 2024-06-08
 *
 * @copyright Copyright (c) 2024
 */

#include "stack.h"
#include <iostream>

int main() {
    Stack<int> stack;   /**< declare a stack object */

    stack.Push(1);  /**< push element into stack */
    stack.Push(2);  /**< push element into stack */
    stack.Push(3);  /**< push element into stack */
    stack.Push(4);  /**< push element into stack */

    while (!stack.IsEmpty()) {
        std::cout << "Size of stack: " << stack.GetSize() << '\n';
        std::cout << "Peek: " << stack.Peek() << '\n';
        std::cout << "Pop: " << stack.Pop() << '\n';
    }
    std::cout << "Size of stack: " << stack.GetSize() << '\n';

    return 0;
}
