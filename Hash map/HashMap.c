//
//  HashMap.c
//  Data Structures in C
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ADTErr.h"
#include "SinglyLinkedList.h"
#include "HashMap.h"

// Structure representing the HashMap
struct HashMap {
    Person_t** dataTable;  // Array of pointers to linked lists
    size_t tableSize;       // Size of the hash table
    size_t numOfItems;      // Total number of items in the hash map
    size_t numOfBuckets;    // Number of non-empty buckets (linked lists)
};

// Function to create a new HashMap
HashMap_t* MapCreate(size_t size) {
    assert(size > 0);

    // Allocate memory for the HashMap structure
    HashMap_t* map = (HashMap_t*)calloc(1, sizeof(HashMap_t));
    if (!map) {
        return NULL;
    }

    // Allocate memory for the array of pointers to linked lists
    map->dataTable = (Person_t**)calloc(size, sizeof(Person_t*));
    if (!map->dataTable) {
        free(map);
        return NULL;
    }

    // Initialize the HashMap parameters
    map->tableSize = size;

    return map;
}

// Function to destroy a HashMap and free associated memory
void MapDestroy(HashMap_t* map) {
    if (!map) {
        return;
    }

    size_t size = map->tableSize;

    // Free memory for each linked list in the HashMap
    for (size_t i = 0; i < size; ++i) {
        Person_t* curEntry = map->dataTable[i];
        Person_t* nextEntry = NULL;
        while (curEntry) {
            nextEntry = curEntry->next;
            free(curEntry);
            curEntry = nextEntry;
        }
    }

    // Free memory for the array of pointers and the HashMap structure
    free(map->dataTable);
    free(map);
}

// Function to insert a person into the HashMap
ADTErr MapInsert(HashMap_t* map, Person_t* person) {
    assert(map && person);

    if (!person->id) {
        return ERR_MISSING_ARGUMENT;
    }

    int index = person->id % map->tableSize;
    Person_t* tempListInsert = map->dataTable[index];

    // Check for duplicates in the linked list
    if (!tempListInsert) {
        if ((map->numOfBuckets + 1) / (float)map->tableSize > 0.7) {
            return ERR_OVERFLOW;
        }

        ++map->numOfBuckets;
    } else {
        while (tempListInsert) {
            if (tempListInsert->id == person->id) {
                return ERR_DUPLICATIOS_KEY;
            }
            tempListInsert = tempListInsert->next;
        }
    }

    // Insert at the head of the linked list
    map->dataTable[index] = ListInsertHead(map->dataTable[index], person);
    ++map->numOfItems;

    return ERR_OK;
}

// Function to remove a person from the HashMap
ADTErr MapRemove(HashMap_t* map, Person_t* person) {
    assert(map && person);

    int index = person->id % map->tableSize;
    Person_t* delItem = NULL;
    delItem = ListRemoveByKey(map->dataTable[index], person->id, &person);

    // Check if the item was found
    if (!delItem) {
        return ERR_WRONG_KEY;
    }

    // Copy the data, free the deleted item, and update counts
    *person = *delItem;
    free(delItem);

    if (!map->dataTable[index]) {
        --map->numOfBuckets;
    }

    --map->numOfItems;

    return ERR_OK;
}

// Function to retrieve a person from the HashMap
ADTErr MapGet(HashMap_t* map, Person_t* person) {
    assert(map && person);

    int index = person->id % map->tableSize;

    // Check if the linked list is empty
    if (!map->dataTable[index]) {
        return ERR_DATA_NOT_FOUND;
    }

    // Search for the person in the linked list
    Person_t* curPersonSearch = map->dataTable[index];
    while (curPersonSearch) {
        if (curPersonSearch->id == person->id) {
            *person = *curPersonSearch;
            return ERR_OK;
        }
        curPersonSearch = curPersonSearch->next;
    }

    return ERR_DATA_NOT_FOUND;
}

// Function to print the contents of the HashMap
void MapPrint(HashMap_t* map) {
    assert(map);

    size_t size = map->tableSize;
    printf("------------------------------------------------------\n");
    for (size_t i = 0; i < size; ++i) {
        if (map->dataTable[i]) {
            printf("Index: %zu\n----------------\n", i);
            PrintList(map->dataTable[i]);
            printf("\n----------------\n");
        }
    }
    printf("\n------------------------------------------------------\n");
}

