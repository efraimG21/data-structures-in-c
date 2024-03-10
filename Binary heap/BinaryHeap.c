//
// BinaryHeap.c
// Implementation of Binary Heap data structure in C
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ADTErr.h"
#include "Vector.h"
#include "BinaryHeap.h"

// Structure representing the Binary Heap
struct Heap {
    Vector_t* vec;    // Vector to store heap elements
    size_t heapSize;   // Number of elements in the heap
};

// Forward declarations of helper functions
void Heapify(Heap_t* subHeap, int index);
void HeapifyBottomUp(Heap_t* heap, int i);

// Function to build a binary heap from an existing vector
Heap_t* BinHeapBuild(Vector_t* vec) {
    assert(vec);

    // Allocate memory for the heap structure
    Heap_t* heap = (Heap_t*)calloc(1, sizeof(Heap_t));
    if (!heap) {
        return NULL;
    }

    heap->vec = vec;
    size_t sizeHeap;
    VectorItemsNum(vec, &sizeHeap);

    heap->heapSize = sizeHeap;

    // Build the heap bottom-up starting from the last non-leaf node
    for (int i = sizeHeap / 2; i > 0; --i) {
        Heapify(heap, i);
    }

    return heap;
}

// Helper function to maintain the heap property
void Heapify(Heap_t* subHeap, int curFatherIndex) {
    int indexLargest = curFatherIndex, leftIndex = curFatherIndex * 2, rightIndex = curFatherIndex * 2 + 1;
    int largestNum, leftValue, rightValue, fatherNum;

    if (leftIndex > subHeap->heapSize) {
        return;
    }

    VectorGet(subHeap->vec, curFatherIndex, &fatherNum);

    if ((VectorGet(subHeap->vec, leftIndex, &leftValue) == ERR_OK) && (fatherNum <= leftValue)) {
        indexLargest = leftIndex;
        largestNum = leftValue;
    } else {
        largestNum = fatherNum;
    }

    if ((VectorGet(subHeap->vec, rightIndex, &rightValue) == ERR_OK) && (largestNum <= rightValue)) {
        indexLargest = rightIndex;
        largestNum = rightValue;
    }

    if (curFatherIndex != indexLargest) {
        // Swap the current father with the largest child
        VectorSet(subHeap->vec, curFatherIndex, largestNum);
        VectorSet(subHeap->vec, indexLargest, fatherNum);
        Heapify(subHeap, indexLargest);
    } else {
        return;
    }
}

// Function to destroy a binary heap
void BinHeapDestroy(Heap_t* heap) {
    assert(heap);

    free(heap);
}

// Function to insert an item into the binary heap
ADTErr BinHeapInsert(Heap_t* heap, int item) {
    assert(heap);

    // Increment heap size
    ++heap->heapSize;
    // Add the new item to the vector
    VectorAdd(heap->vec, item);
    // Restore the heap property by moving the new item up the heap
    HeapifyBottomUp(heap, heap->heapSize);

    return ERR_OK;
}

// Helper function to maintain the heap property after inserting an item
void HeapifyBottomUp(Heap_t* heap, int i) {
    if (i / 2 == 0 || i == 1) {
        return; // Reached the root of the heap
    }

    int son, father;
    VectorGet(heap->vec, i, &son);
    VectorGet(heap->vec, i / 2, &father);

    if (son > father) {
        // Swap the current son with its parent
        VectorSet(heap->vec, i, father);
        VectorSet(heap->vec, i / 2, son);
        // Continue moving up the heap
        HeapifyBottomUp(heap, i / 2);
    } else {
        return; // Heap property is restored
    }
}

// Function to get the maximum item from the binary heap
ADTErr BinHeapMax(Heap_t* heap, int* item) {
    assert(heap);

    // Get the root (maximum) item
    ADTErr err = VectorGet(heap->vec, 1, item);

    return err;
}

// Function to get the number of items in the binary heap
ADTErr BinHeapItemsNum(Heap_t* heap, size_t* heapSize) {
    assert(heap);

    // Return the current heap size
    *heapSize = heap->heapSize;

    return ERR_OK;
}

// Function to remove the maximum item from the binary heap
ADTErr BinHeapRemove(Heap_t* heap, int* item) {
    assert(heap && item);

    if (!heap->heapSize) {
        return ERR_UNDERFLOW; // Heap is empty
    }

    int lastItem;
    // Get the root (maximum) item
    VectorGet(heap->vec, 1, item);
    // Get the last item in the heap
    VectorGet(heap->vec, heap->heapSize, &lastItem);
    // Replace the root with the last item
    VectorSet(heap->vec, 1, lastItem);
    VectorSet(heap->vec, heap->heapSize, *item);
    // Remove the last item from the heap
    VectorDelete(heap->vec, item);
    // Decrement the heap size
    --(heap->heapSize);
    // Restore the heap property by moving the new root down the heap
    Heapify(heap, 1);

    return ERR_OK;
}

// Function to print the binary heap
void BinHeapPrint(Heap_t* heap) {
    VectorPrint(heap->vec);
}

