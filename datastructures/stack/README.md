# Stack Data Structure

A stack is a linear data-structure which models a real world stack by having two primary operations, namely `push` and `pop`. Push refers to the act of adding element to the top of stack and pop refers to the act of removing element from the top of stack. The provided implementation is done using singly-linked list.

Usage of Stack:
    - Used by undo mechanisms in text editors
    - Used in compiler syntax checking for matching brackets anc braces
    - Used behind the scenes to support recursion by keeping track of previous functions calls.
    - Can be used to do a Depth First Search (DFS) on a graph.

Complexity:
    - Push: `O(1)`
    - Pop: `O(1)`
    - Peek: `O(1)` -> get value from the top of stack without removing it
    - Search: `O(n)`
    - Size: `O(1)`
