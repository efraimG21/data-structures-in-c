//
//  SinglyLinkedList.h
//  data structures in c
//
//  Created by efraim g on 08/03/2024.
//

#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

typedef struct Person Person_t;

struct Person {
    int id;
    char name[10];
    int age;

    Person_t* next;
};

Person_t* ListInsertHead(Person_t* head, Person_t* item);
Person_t* ListRemoveHead(Person_t* head, Person_t** item);
Person_t* ListInsertByKey(Person_t* head, int key, Person_t* item);
Person_t* ListRemoveByKey(Person_t* head, int key, Person_t** item);
Person_t* ListInsertByKeyRec(Person_t* head, int key, Person_t* item);
Person_t* ListRemoveByKeyRec(Person_t* head, int key, Person_t** item);

void PrintList(Person_t* head);


#endif /* SinglyLinkedList_h */
