//
//  Queue.c
//  data structures in c
//

#include <stdio.h>
#include <stdlib.h>

#include "ADTErr.h"
#include "Queue.h"

struct Queue
{
    int* vec;
    size_t size;
    size_t numOfItems;
    size_t head;
    size_t tail;
};

// Create a new queue with the given size
Queue_t* QueueCreate(size_t size) {
    if (size == 0) {
        return NULL; // Invalid size
    }

    Queue_t* que = (Queue_t*)malloc(sizeof(Queue_t));
    if (!que) {
        return NULL; // Memory allocation failed for the queue
    }

    que->vec = (int*)malloc(sizeof(int) * size);
    if (!que->vec) {
        free(que);
        return NULL; // Memory allocation failed for the underlying array
    }

    que->size = size;
    que->numOfItems = 0;
    que->head = 0;
    que->tail = 0;

    return que;
}

// Destroy the queue and free allocated memory
void QueueDestroy(Queue_t* queue) {
    if (queue) {
        free(queue->vec);
        free(queue);
    }
}

// Insert an item into the queue
ADTErr QueueInsert(Queue_t* queue, int item) {
    if (!queue) {
        return ERR_NOT_INITIALIZED; // Queue not initialized
    }

    if (queue->numOfItems == queue->size) {
        return ERR_OVERFLOW; // Queue is full
    }

    *(queue->vec + queue->tail) = item;
    queue->tail = (queue->tail + 1) % queue->size;
    ++queue->numOfItems;

    return ERR_OK;
}

// Delete an item from the queue
ADTErr QueueDelete(Queue_t* queue, int* item) {
    if (!queue || !item) {
        return ERR_NOT_INITIALIZED; // Queue or item pointer not initialized
    }

    if (!queue->numOfItems) {
        return ERR_UNDERFLOW; // Queue is empty
    }

    *item = *(queue->vec + queue->head);
    queue->head = (queue->head + 1) % queue->size;
    --queue->numOfItems;

    return ERR_OK;
}

// Check if the queue is empty
int QueueIsEmpty(Queue_t* queue) {
    if (!queue) {
        return 1; // Queue not initialized
    }

    return !queue->numOfItems;
}

// Print the contents of the queue
void QueuePrint(Queue_t* queue) {
    if (!(queue && queue->numOfItems)) {
        return; // Queue not initialized or empty
    }

    printf("------------------------------------------------\n");
    for (size_t i = 0, index = queue->head; i < queue->numOfItems; ++i, ++index) {
        index %= queue->size;
        printf("%d ", queue->vec[index]);
    }
    printf(" \n------------------------------------------------\n");
}
