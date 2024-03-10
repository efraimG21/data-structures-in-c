//
// BinaryHeap.h
// Header file for Binary Heap data structure in C
//

#ifndef BinaryHeap_h
#define BinaryHeap_h

#include "Vector.h"  // Include necessary header file for Vector

typedef struct Heap Heap_t;

// Function to build a binary heap from an existing vector
Heap_t* BinHeapBuild(Vector_t* vec);

// Function to destroy a binary heap
void BinHeapDestroy(Heap_t* heap);

// Function to get the maximum item from the binary heap
ADTErr BinHeapMax(Heap_t* heap, int* item);

// Function to insert an item into the binary heap
ADTErr BinHeapInsert(Heap_t* heap, int item);

// Function to remove the maximum item from the binary heap
ADTErr BinHeapRemove(Heap_t* heap, int* item);

// Function to print the binary heap
void BinHeapPrint(Heap_t* heap);

#endif /* BinaryHeap_h */
