//
//  HashMap.h
//  Data Structures in C
//

#ifndef HashMap_h
#define HashMap_h

typedef struct HashMap HashMap_t;

HashMap_t* MapCreate(size_t size);
void       MapDestroy(HashMap_t* map);
ADTErr     MapInsert(HashMap_t* map, Person_t* person);
ADTErr     MapRemove(HashMap_t* map, Person_t* person);
ADTErr     MapGet(HashMap_t* map, Person_t* person);
void       MapPrint(HashMap_t* map);

#endif /* HashMap_h */
