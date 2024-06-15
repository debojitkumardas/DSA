#include "queue.h"
#include <iostream>

int main() {
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);

    while (!queue.IsEmpty()) {
        std::cout << "Size of Queue: " << queue.GetSize() << '\n';
        std::cout << "Peek: " << queue.Peek() << '\n';
        std::cout << "Dequeue: " << queue.Dequeue() << '\n';
    }
    std::cout << "Size of Queue: " << queue.GetSize() << '\n';
}
