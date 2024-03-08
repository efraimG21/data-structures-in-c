//
//  Vector.c
//  data structures in c
//
//  Created by efraim g on 08/03/2024.
//

#include <stdio.h>
#include <stdlib.h>

#include "ADTErr.h"
#include "Vector.h"

#define REALLOC_FACTOR 2

struct Vector
{
    int* items;          // Array to store the elements of the vector
    size_t originalSize; // Initial size of the vector
    size_t blockSize;    // Block size to be added during reallocation
    size_t currSize;     // Current size of the vector
    size_t nItems;       // Number of items in the vector
};

// Function to create a new vector
Vector_t* VectorCreate(size_t size, size_t blockSize)
{
    Vector_t* vector;

    // Check for invalid size and block size
    if ((size == 0) && (blockSize == 0))
    {
        return NULL;
    }

    // Allocate memory for the vector structure
    vector = (Vector_t*)malloc(sizeof(Vector_t));
    if (!vector)
    {
        return NULL;
    }

    // Allocate memory for the vector items array
    vector->items = (int*)malloc(sizeof(int) * size);
    if (!vector->items)
    {
        free(vector);
        return NULL;
    }

    // Initialize vector properties
    vector->currSize = size;
    vector->originalSize = size;
    vector->blockSize = blockSize;
    vector->nItems = 0;

    return vector;
}

// Function to destroy a vector and free allocated memory
void VectorDestroy(Vector_t* vector)
{
    if (vector)
    {
        free(vector->items);
        free(vector);
    }
}

// Function to add an item to the vector
ADTErr VectorAdd(Vector_t* vector, int item)
{
    int* tmp;

    // Check if the vector is initialized
    if (!vector)
    {
        return ERR_NOT_INITIALIZED;
    }

    // Check if the vector is full
    if (vector->nItems == vector->currSize)
    {
        // If blockSize is 0, return overflow error
        if (vector->blockSize == 0)
        {
            return ERR_OVERFLOW;
        }

        // Reallocate memory with additional blockSize
        tmp = (int*)realloc(vector->items,
            sizeof(int) * (vector->currSize + vector->blockSize));

        if (NULL == tmp)
        {
            return ERR_REALLOCATION_FAILED;
        }
        vector->items = tmp;
        vector->currSize += vector->blockSize;
    }

    // Add item to the vector and update the count
    *(vector->items + vector->nItems) = item;
    ++vector->nItems;

    return ERR_OK;
}

// Function to delete an item from the end of the vector
ADTErr VectorDelete(Vector_t* vector, int* item)
{
    int* tmp;

    // Check if the vector or item pointer is not initialized
    if (!vector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    // Check if the vector is empty
    if (vector->nItems == 0)
    {
        return ERR_UNDERFLOW;
    }

    // Check if reallocation is possible and needed
    if ((vector->currSize > vector->originalSize) &&
        (vector->nItems <= vector->currSize - (vector->blockSize * REALLOC_FACTOR)))
    {
        // Shrink the vector by blockSize during reallocation
        tmp = (int*)realloc(vector->items,
            sizeof(int) * (vector->currSize - vector->blockSize));
        if (!tmp)
        {
            return (ERR_REALLOCATION_FAILED);
        }
        vector->items = tmp;
        vector->currSize -= vector->blockSize;
    }

    // Retrieve the item from the end of the vector and update the count
    *item = *(vector->items + vector->nItems - 1);
    --vector->nItems;

    return ERR_OK;
}

// Function to get an item from the vector at a specific index
ADTErr VectorGet(Vector_t* vector, size_t index, int* item)
{
    // Check if the vector or item pointer is not initialized
    if (!vector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    // Check if the index is out of bounds
    if (index > vector->nItems || index < 1)
    {
        return ERR_WRONG_INDEX;
    }

    // Retrieve the item at the specified index
    *item = *(vector->items + index - 1);

    return ERR_OK;
}

// Function to set an item in the vector at a specific index
ADTErr VectorSet(Vector_t* vector, size_t index, int item)
{
    // Check if the vector is not initialized
    if (!vector)
    {
        return ERR_NOT_INITIALIZED;
    }
    // Check if the index is out of bounds
    if (index > vector->nItems || index < 1)
    {
        return ERR_WRONG_INDEX;
    }

    // Set the item at the specified index
    *(vector->items + (index - 1)) = item;
    return ERR_OK;
}

// Function to get the number of items in the vector
ADTErr VectorItemsNum(Vector_t* vector, size_t* numOfItems)
{
    // Check if the vector or numOfItems pointer is not initialized
    if (!vector || !numOfItems)
    {
        return ERR_NOT_INITIALIZED;
    }

    // Retrieve the number of items in the vector
    *numOfItems = vector->nItems;

    return ERR_OK;
}

// Function to print the details and items of the vector
void VectorPrint(Vector_t* vector)
{
    if (!vector)
    {
        return;
    }
    printf("----------------------------------------\n");

    // Print vector details
    printf("<Vector Details> | BlockSize=%zu | nItems=%zu | currSize=%zu | originalSize=%zu |\n <Vector Items> ",
        vector->blockSize, vector->nItems, vector->currSize, vector->originalSize);

    // Print vector items
    for (int i = 0; i < vector->nItems; ++i)
    {
        printf("%d ", *(vector->items + i));
    }

    printf("\n----------------------------------------\n");
}
