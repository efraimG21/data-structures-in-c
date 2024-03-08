//
//  Queue.h
//  data structures in c
//


#ifndef Queue_h
#define Queue_h

typedef struct Queue Queue_t;

Queue_t* QueueCreate(size_t size);
void QueueDestroy(Queue_t* queue);
ADTErr QueueInsert(Queue_t* queue, int item);
ADTErr QueueDelete(Queue_t* queue, int* item);
int QueueIsEmpty(Queue_t* queue);
void QueuePrint(Queue_t* queue);

#endif /* Queue_h */
