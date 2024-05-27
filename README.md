# Data Structures in C

Welcome to the "Data Structures in C" project, a comprehensive collection of essential data structures implemented in C. Explore the world of Vectors, Stacks, Queues, and the Abstract Data Type for Errors (ADTErr) to build a solid foundation in data structure concepts.

## Table of Contents

- [Introduction](#introduction)
- [Vector](#vector)
- [Generic vector](#generic-vector)
- [Stack](#stack)
- [Queue](#queue)
- [Singly Linked List](#singly-linked-list)
- [Hash map](#hash-map)
- [Binary heap](#binary-heap)
- [ADTErr](#adterr)

## Introduction

Understanding data structures is fundamental to efficient algorithm design, playing a pivotal role in writing robust and scalable software. This project serves as a resource for those looking to explore and implement essential data structures in the C programming language.

## Vector

### Overview

The **Vector** is a dynamic array implementation that facilitates dynamic addition, deletion, and retrieval of elements. It provides automatic memory management and resizing capabilities, making it a versatile tool for managing sequences of data.

### Operations and Runtime Complexities

1. **VectorCreate(size_t size, size_t blockSize):**
   - Creates a new vector with an initial size and block size for reallocation.
   - **Time Complexity:** O(1)

2. **VectorAdd(Vector_t* vector, int item):**
   - Adds an item to the end of the vector. Resizes if needed.
   - **Time Complexity:** O(1) amortized

3. **VectorDelete(Vector_t* vector, int* item):**
   - Deletes the last item from the vector. Shrinks if needed.
   - **Time Complexity:** O(1) amortized

4. **VectorPrint(Vector_t* vector):**
   - Prints details and items of the vector.
   - **Time Complexity:** O(n), where n is the number of items.


## Generic Vector

### Overview

The **Generic Vector** is a dynamic array implementation designed to store elements of any data type. It provides dynamic addition, deletion, and retrieval of items, offering flexibility for various use cases.

### Operations and Runtime Complexities

1. **GenVectorCreate(size_t size, size_t blockSize):**
   - Creates a new generic vector with an initial size and block size for reallocation.
   - **Time Complexity:** O(1)

2. **GenVectorAdd(GenVector_t* vec, void* item):**
   - Adds an item to the end of the generic vector. Resizes if needed.
   - **Time Complexity:** O(1) amortized

3. **GenVectorDelete(GenVector_t* vec, void** item):**
   - Deletes the last item from the generic vector. Shrinks if needed.
   - **Time Complexity:** O(1) amortized

4. **GenVectorGet(GenVector_t* vec, size_t index, void** item):**
   - Retrieves an item from the generic vector by index.
   - **Time Complexity:** O(1)

5. **GenVectorSet(GenVector_t* vec, size_t index, void* item):**
   - Sets an item in the generic vector by index.
   - **Time Complexity:** O(1)

6. **GenVectorItemsNum(GenVector_t* vec, size_t* numOfItems):**
   - Gets the number of items in the generic vector.
   - **Time Complexity:** O(1)

### Usage

1. **Include "GenericVector.h" in your project.**
2. Utilize the provided functions for creating, modifying, and accessing elements in the generic vector.


## Stack

### Overview

The **Stack** is a fundamental data structure built on top of the Vector. It follows the Last In, First Out (LIFO) principle, making it suitable for scenarios where the order of processing matters.

### Operations and Runtime Complexities

1. **StackCreate(size_t size, size_t blockSize):**
   - Creates a new stack with an initial size and block size for reallocation.
   - **Time Complexity:** O(1)

2. **StackPush(Stack_t* stack, int item):**
   - Pushes an item onto the stack using VectorAdd.
   - **Time Complexity:** O(1) amortized

3. **StackPop(Stack_t* stack, int* item):**
   - Pops an item from the stack using VectorDelete.
   - **Time Complexity:** O(1) amortized

4. **StackReverse(Stack_t* stack):**
   - Reverses the order of items in the stack.
   - **Time Complexity:** O(n), where n is the number of items in the stack.

## Queue

### Overview

The **Queue** is a versatile data structure that follows the First In, First Out (FIFO) principle. It allows efficient insertion and deletion operations, making it suitable for scenarios like task scheduling and breadth-first search algorithms.

### Operations and Runtime Complexities

1. **QueueCreate(size_t size):**
   - Creates a new queue with the given size.
   - **Time Complexity:** O(1)

2. **QueueInsert(Queue_t* queue, int item):**
   - Inserts an item into the queue.
   - **Time Complexity:** O(1)

3. **QueueDelete(Queue_t* queue, int* item):**
   - Deletes an item from the queue.
   - **Time Complexity:** O(1)

4. **QueueIsEmpty(Queue_t* queue):**
   - Checks if the queue is empty.
   - **Time Complexity:** O(1)

5. **QueuePrint(Queue_t* queue):**
   - Prints the contents of the queue.


## Singly Linked List

### Overview

The **Singly Linked List** is a linear data structure where elements are stored in nodes, and each node points to the next node in the sequence. This simple yet powerful structure allows for efficient insertion and deletion of elements, making it useful in various scenarios.

### Operations and Runtime Complexities

1. **ListInsertHead(Person_t* head, Person_t* item):**
   - Inserts a new node at the beginning of the linked list.
   - **Time Complexity:** O(1)

2. **ListRemoveHead(Person_t* head, Person_t** item):**
   - Removes the node at the beginning of the linked list.
   - **Time Complexity:** O(1)

3. **ListInsertByKey(Person_t* head, int key, Person_t* item):**
   - Inserts a new node with a specific key value into the sorted linked list.
   - **Time Complexity:** O(n), where n is the number of elements in the list.

4. **ListRemoveByKey(Person_t* head, int key, Person_t** item):**
   - Removes the node with a specific key value from the linked list.
   - **Time Complexity:** O(n), where n is the number of elements in the list.

5. **ListInsertByKeyRec(Person_t* head, int key, Person_t* item):**
   - Recursively inserts a new node with a specific key value into the sorted linked list.
   - **Time Complexity:** O(n), where n is the number of elements in the list.

6. **ListRemoveByKeyRec(Person_t* head, int key, Person_t** item):**
   - Recursively removes the node with a specific key value from the linked list.
   - **Time Complexity:** O(n), where n is the number of elements in the list.

7. **PrintList(Person_t* head):**
   - Prints the elements of the linked list.
   - **Time Complexity:** O(n), where n is the number of elements in the list.

### Usage

1. **Include "SinglyLinkedList.h" in your project.**
2. Utilize the provided functions for inserting, removing, and printing elements in the singly linked list.

## Hash Map

### Overview

The **Hash Map** is a versatile data structure that uses a hash function to map keys to indices, allowing for efficient insertion, retrieval, and deletion of key-value pairs. It provides fast access to data by minimizing the time complexity of these operations.

### Operations and Runtime Complexities

1. **MapCreate(size_t size):**
   - Creates a new hash map with the given size.
   - **Time Complexity:** O(1)

2. **MapInsert(HashMap_t* map, Person_t* person):**
   - Inserts a key-value pair into the hash map.
   - **Time Complexity:** O(1) on average

3. **MapRemove(HashMap_t* map, Person_t* person):**
   - Removes a key-value pair from the hash map.
   - **Time Complexity:** O(1) on average

4. **MapGet(HashMap_t* map, Person_t* person):**
   - Retrieves the value associated with a key from the hash map.
   - **Time Complexity:** O(1) on average

5. **MapPrint(HashMap_t* map):**
   - Prints the contents of the hash map.

### Usage

1. **Include "HashMap.h" in your project.**
2. Utilize the provided functions for inserting, removing, and retrieving key-value pairs in the hash map.


## Binary Heap

### Overview

The **Binary Heap** is a complete binary tree-based data structure that satisfies the heap property. In a max heap, the key of each node is always greater than or equal to the keys of its children, making the node with the highest key always at the root.

### Operations and Runtime Complexities

1. **BinHeapBuild(Vector_t* vec):**
   - Builds a binary heap from an existing vector.
   - **Time Complexity:** O(n), where n is the number of elements in the vector.

2. **BinHeapDestroy(Heap_t* heap):**
   - Destroys the binary heap, freeing allocated memory.
   - **Time Complexity:** O(1)

3. **BinHeapMax(Heap_t* heap, int* item):**
   - Retrieves the maximum item from the binary heap.
   - **Time Complexity:** O(1)

4. **BinHeapInsert(Heap_t* heap, int item):**
   - Inserts an item into the binary heap.
   - **Time Complexity:** O(log n), where n is the number of elements in the heap.

5. **BinHeapRemove(Heap_t* heap, int* item):**
   - Removes the maximum item from the binary heap.
   - **Time Complexity:** O(log n), where n is the number of elements in the heap.

6. **BinHeapPrint(Heap_t* heap):**
   - Prints the contents of the binary heap.
   - **Time Complexity:** O(n), where n is the number of elements in the heap.

### Usage

1. **Include "BinaryHeap.h" in your project.**
2. Create a binary heap using `BinHeapBuild` with an existing vector.
3. Utilize the provided functions for various binary heap operations.



## ADTErr

### Overview

**ADTErr** is an Abstract Data Type for error handling within the data structures. It provides a standardized set of error codes and corresponding descriptions to assist developers in identifying and addressing issues in their code.

### Usage

1. **Include "ADTErr.h" in your project.**
2. Use the provided error codes in your data structure operations.
3. Handle errors using the `HandleErr` function in "ADTErr.c."

### Examples
```c
// Example usage of ADTErr
ADTErr result = performOperation();
HandleErr(result, "Error occurred during the operation");
```

## Contributing

Feel free to contribute to the project by opening issues or pull requests.


Feel free to customize the content as needed for your project. If you have any specific requirements or if you'd like further modifications, please let me know!


This revised README provides a bit more context about why understanding data structures is important, introduces each data structure, and outlines their key operations and runtime complexities. Adjustments can be made based on your project's specific goals and audience.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

