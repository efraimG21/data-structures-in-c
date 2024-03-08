//
//  Stack.h
//  data structures in c
//
//  Created by efraim g on 08/03/2024.
//

#ifndef Stack_h
#define Stack_h

typedef struct Stack Stack_t;

Stack_t*  StackCreate(size_t size, size_t sizeBlack);
void      StackDestroy(Stack_t* stack);
ADTErr    StackPush(Stack_t* stack, int item);
ADTErr    StackPop(Stack_t* stack, int* item);
ADTErr    StackTop(Stack_t* stack, int* item);
Stack_t*  StackReverse(Stack_t* stack);
int       StackIsEmpty(Stack_t*);
void      StackPrint(Stack_t*);

#endif /* Stack_h */
