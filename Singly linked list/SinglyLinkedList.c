//
//  SinglyLinkedList.c
//  data structures in c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "SinglyLinkedList.h"

// Function to insert a new person at the head of the list
Person_t* ListInsertHead(Person_t* head, Person_t* item) {
    assert(item);

    // Set the next pointer of the new person to the current head
    item->next = head;
    return item;  // Return the new head of the list
}

// Function to remove the person at the head of the list
Person_t* ListRemoveHead(Person_t* head, Person_t** item) {
    assert(head && item);

    // Set the next pointer of the head to NULL and return the head
    // while saving a reference to the removed person in *item
    Person_t* tmp = head->next;
    head->next = NULL;
    *item = head;

    return tmp;  // Return the new head of the list
}

// Function to insert a new person in the list based on their key (id)
Person_t* ListInsertByKey(Person_t* head, int key, Person_t* item) {
    Person_t* tmp = head;
    assert(item);

    // If the list is empty or the new person has a smaller key than the head
    if (!head || head->id >= key) {
        // Insert the new person at the head
        item->next = head;
        return item;
    }

    // Traverse the list to find the correct position for the new person
    while (head->next && head->next->id < key) {
        head = head->next;
    }

    // Insert the new person in the correct position
    item->next = head->next;
    head->next = item;

    return tmp;  // Return the original head of the list
}

// Recursive function to insert a new person in the list based on their key (id)
Person_t* ListInsertByKeyRec(Person_t* head, int key, Person_t* item) {
    assert(item);

    // If the list is empty or the new person has a smaller key than the head
    if (!head || head->id >= key) {
        // Insert the new person at the head
        item->next = head;
        return item;
    }

    // Recursively insert the new person in the rest of the list
    head->next = ListInsertByKeyRec(head->next, key, item);
    return head;  // Return the original head of the list
}

// Function to remove a person from the list based on their key (id)
Person_t* ListRemoveByKey(Person_t* head, int key, Person_t** item) {
    assert(head && item);

    Person_t* orgHead = head;

    // If the person to be removed is at the head
    if (head->id == key) {
        *item = head;
        head = head->next;
        (*item)->next = NULL;
        return head;  // Return the new head of the list
    }

    // Traverse the list to find the person before the one to be removed
    while (head->next && head->next->id != key) {
        head = head->next;
    }

    // If the person to be removed is found
    if (head->next && head->next->id == key) {
        *item = head->next;
        head->next = head->next->next;
        (*item)->next = NULL;
    }

    return orgHead;  // Return the original head of the list
}

// Recursive function to remove a person from the list based on their key (id)
Person_t* ListRemoveByKeyRec(Person_t* head, int key, Person_t** item) {
    assert(item);

    // If the list is empty
    if (!head) {
        return NULL;
    }

    // If the person to be removed is at the head
    if (head->id == key) {
        *item = head;
        head = head->next;
        (*item)->next = NULL;
        return head;  // Return the new head of the list
    }

    // Recursively remove the person in the rest of the list
    head->next = ListRemoveByKeyRec(head->next, key, item);
    return head;  // Return the original head of the list
}

// Function to print the contents of the list
void PrintList(Person_t* head) {
    while (head) {
        printf("Current Person:\nName: %s Age: %d\n", head->name, head->age);
        head = head->next;
    }
}
