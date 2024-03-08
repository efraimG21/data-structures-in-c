//
//  Vector.h
//  data structures in c
//

#ifndef Vector_h
#define Vector_h

typedef struct Vector Vector_t;

Vector_t* VectorCreate(size_t _size, size_t blockSize);
void      VectorDestroy(Vector_t* vector);
ADTErr    VectorAdd(Vector_t* vector, int  item);
ADTErr    VectorDelete(Vector_t* vector, int* item);
ADTErr    VectorGet(Vector_t* _vector, size_t index, int* item);
ADTErr    VectorSet(Vector_t* vector, size_t index, int  item);
ADTErr    VectorItemsNum(Vector_t* _vector, size_t* _numOfItems);
void      VectorPrint(Vector_t* vector);

#endif /* Vector_h */
