# Queue Data Structure

A queue is a linear data structure which models real world queues by having two primary operations, namely `enqueue` and `dequeue`. Enqueue refers to the act of adding element to the end of the queue and dequeue refers to the act of removing element from the front of the queue. The provided implementation is done using singly-linked list.

Usage of Queue:
    - Can be used to efficiently keep track of the `n` most recently added elements.
    - Web server request management where you want first come first serve.
    - Breadth First Search (BFS) graph traversal.

Complexity:
    - Enqueue: `O(1)`
    - Dequeue: `O(1)`
    - Peeking: `O(1)` -> get value from the front of queue without removing it
    - Searching: `O(n)`
    - Size: `O(1)`
