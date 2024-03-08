//
// Stack.c
// Data Structures in C
//


#include <stdio.h>
#include <stdlib.h>

#include "ADTErr.h"
#include "Vector.h"
#include "Stack.h"

// Structure representing a stack
struct Stack {
    Vector_t* vec;
};

// Function to create a new stack
Stack_t* StackCreate(size_t size, size_t sizeBlack) {
    Stack_t* stack = (Stack_t*)malloc(sizeof(Stack_t));
    if (stack == NULL) {
        return NULL; // Memory allocation failed
    }

    stack->vec = VectorCreate(size, sizeBlack);
    if (stack->vec == NULL) {
        free(stack);
        return NULL; // Vector creation failed
    }

    return stack;
}

// Function to destroy a stack
void StackDestroy(Stack_t* stack) {
    if (stack) {
        VectorDestroy(stack->vec);
        free(stack);
    }
}

// Function to push an item onto the stack
ADTErr StackPush(Stack_t* stack, int item) {
    if (!stack) {
        return ERR_NOT_INITIALIZED;
    }
    return VectorAdd(stack->vec, item);
}

// Function to pop an item from the stack
ADTErr StackPop(Stack_t* stack, int* item) {
    if (stack == NULL) {
        return ERR_NOT_INITIALIZED;
    }
    return VectorDelete(stack->vec, item);
}

// Function to get the top item from the stack without popping it
ADTErr StackTop(Stack_t* stack, int* item) {
    size_t nItem;
    if (stack == NULL || VectorItemsNum(stack->vec, &nItem)) {
        return ERR_NOT_INITIALIZED;
    }

    return VectorGet(stack->vec, nItem, item);
}

// Function to reverse the order of items in a stack
Stack_t* StackReverse(Stack_t* stack) {
    ADTErr err;
    size_t size;
    VectorItemsNum(stack->vec, &size);
    if (!stack || !size) {
        return NULL; // Cannot reverse an empty stack or uninitialized stack
    }

    Stack_t* reverseStack = StackCreate(size, 2);
    if (!reverseStack) {
        return NULL; // Memory allocation failed for the reversed stack
    }

    while (!StackIsEmpty(stack)) {
        int item;
        StackPop(stack, &item);
        StackPush(reverseStack, item);
    }

    return reverseStack;
}

// Function to check if the stack is empty
int StackIsEmpty(Stack_t* stack) {
    int nItem = 0;
    if (stack == NULL || VectorItemsNum(stack->vec, &nItem)) {
        return 1; // Stack is considered empty if it's not initialized or there are issues getting the item count
    }

    return !nItem;
}

// Function to print the stack
void StackPrint(Stack_t* stack) {
    if (stack) {
        VectorPrint(stack->vec);
    }
}
