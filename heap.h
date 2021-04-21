#ifndef _heap_h
#define _heap_h 1
#include <stdio.h>
#include "graph.h"

typedef VERTEX ELEMENT;
typedef VERTEX *pELEMENT;

typedef struct TAG_HEAP{
    int capacity;
    int size;
    pELEMENT *H;
}HEAP;

void heapFree(HEAP *heap);

HEAP *heapInit(int capacity);
void heapPrint(HEAP *heap); 

void MovingUp(HEAP *heap, int pos);
 
// typedef struct TAG_ELEMENT{
//     int key;
// }ELEMENT;

// typedef ELEMENT *ElementT;

// typedef struct TAG_HEAP{
//     int capacity; /* max size of the heap */
//     int size;
//     int heaps_called = 0;
//     /* current size of the heap */
//     ElementT *elements; /* pointer to pointers to elements */
// }HEAP;


HEAP *heapInit(int capacity);
void printHeap(HEAP *H);
int sizeOf(HEAP *H);
void insert(HEAP *H, int value);
int extractMin(HEAP *H);
void decreaseKey(HEAP *H, int index, int value);
void buildMinHeap(HEAP *H);
void minHeapify(HEAP *H, int index);
int left(int i);
int right(int i);
int parent(int i);
void swap(ELEMENT *x, ELEMENT *y);
// // void PercUp(HEAP *H, int pos);
// // void PercDown(HEAP *H, int pos);

#endif