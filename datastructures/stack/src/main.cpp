/*
 * Stack<int> var;
 * var.push(1);
*/

#include "stack.h"
#include <iostream>

int main() {
    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    std::cout << "Peek: " << stack.Peek() << '\n';
    std::cout << "Pop: " << stack.Pop() << '\n';
    std::cout << "Peek: " << stack.Peek() << '\n';
    std::cout << "Pop: " << stack.Pop() << '\n';
    std::cout << "Peek: " << stack.Peek() << '\n';
    std::cout << "Pop: " << stack.Pop() << '\n';
    std::cout << "Peek: " << stack.Peek() << '\n';
    std::cout << "Pop: " << stack.Pop() << '\n';

    return 0;
}
