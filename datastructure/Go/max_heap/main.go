package main

import "fmt"

// MaxHeap struct has a slice that holds the array

type MaxHeap struct {
    array []int
}

func GetParentIndex(i int) int {
    return (i - 1) / 2
}

func GetLeftChildIndex(i int) int  {
    return 2 * i + 1
}

func GetRightChildIndex(i int) int  {
    return 2 * i + 2
}

func (h *MaxHeap) Swap(i1, i2 int) {
    h.array[i1], h.array[i2] = h.array[i2], h.array[i1]
}

func (h *MaxHeap) MaxHeapifyUp(index int) {
    for h.array[GetParentIndex(index)] < h.array[index] {
        h.Swap(GetParentIndex(index), index)
        index = GetParentIndex(index)
    }
}

func (h *MaxHeap) MaxHeapifyDown(index int) {
    last_index := len(h.array) - 1
    left_child_index, right_child_index := GetLeftChildIndex(index), GetRightChildIndex(index)

    child_to_compare := 0

    for left_child_index <= last_index {
        if left_child_index == last_index {
            child_to_compare = left_child_index
        } else if h.array[left_child_index] > h.array[right_child_index] {
            child_to_compare = left_child_index
        } else {
            child_to_compare = right_child_index
        }

        if h.array[index] < h.array[child_to_compare] {
            h.Swap(index, child_to_compare)
            index = child_to_compare
            left_child_index, right_child_index = GetLeftChildIndex(index), GetRightChildIndex(index)
        } else {
            return
        }
    }
}

// Insert adds an element to the heap
func (h *MaxHeap) Insert(key int) {
    h.array = append(h.array, key)
    h.MaxHeapifyUp(len(h.array) - 1)
}

func (h *MaxHeap) Extract() int {
    extracted := h.array[0]
    last_index := len(h.array) - 1

    if last_index == -1 {
        fmt.Println("Array is empty. Exiting!!")
        return -1
    }

    h.array[0] = h.array[last_index]
    h.array = h.array[:last_index]

    h.MaxHeapifyDown(0)

    return extracted
}

func main() {
    m := &MaxHeap{}

    fmt.Println(m)

    build_heap := []int{10, 20, 30, 5, 7, 9, 11, 13, 15, 17}

    for _, v := range build_heap {
        m.Insert(v)
        fmt.Println(m)
    }

    for i := 0; i < 5; i++ {
        m.Extract()
        fmt.Println(m)
    }
}
