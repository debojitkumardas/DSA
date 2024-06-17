/**
 * @file main.cpp
 * @author Debojit Kumar Das
 * @brief This is the main file
 * @version 0.1
 * @date 2024-06-10
 *
 * @copyright Copyright (c) 2024
 */

#include "queue.h"
#include <iostream>

int main() {
    Queue<int> queue;   /**< declare a stack object */

    queue.Enqueue(1);   /**< enqueue element into queue */
    queue.Enqueue(2);   /**< enqueue element into queue */
    queue.Enqueue(3);   /**< enqueue element into queue */
    queue.Enqueue(4);   /**< enqueue element into queue */

    while (!queue.IsEmpty()) {
        std::cout << "Size of Queue: " << queue.GetSize() << '\n';
        std::cout << "Peek: " << queue.Peek() << '\n';
        std::cout << "Dequeue: " << queue.Dequeue() << '\n';
    }
    std::cout << "Size of Queue: " << queue.GetSize() << '\n';
}
