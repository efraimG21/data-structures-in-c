//
//  main.c
//  data structures in c
//
//  Created by efraim g on 09/03/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ADTErr.h"
#include "Vector.h"
#include "BinaryHeap.h"

int main(void) {

    ADTErr err;
    Vector_t* vec = VectorCreate(10, 2);

    /*VectorAdd(vec, 7);
    VectorAdd(vec, 8);
    VectorAdd(vec, 70);
    VectorAdd(vec, 3);
    VectorAdd(vec, 6);
    VectorAdd(vec, 10);
    VectorAdd(vec, 100);
    VectorAdd(vec, 100);
    VectorAdd(vec, 150);*/

    VectorAdd(vec, 35);
    VectorAdd(vec, 4);
    VectorAdd(vec, 25);
    VectorAdd(vec, 15);
    VectorAdd(vec, 20);
    VectorAdd(vec, 60);
    VectorAdd(vec, 150);
    /*VectorPrint(vec);*/
    Heap_t* heap = BinHeapBuild(vec);
    
    BinHeapInsert(heap, 65);
    
    int item;
    BinHeapPrint(heap);
    BinHeapRemove(heap, &item);
    printf("%d \n", item);
    BinHeapPrint(heap);

    BinHeapMax(heap, &item);
    printf("%d \n", item);

    //VectorPrint(vec);
    return 0;
}
