#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"
HEAP *heapInit(int capacity)
{
    HEAP *heap;
    heap = (HEAP *) calloc(1, sizeof(HEAP));
    heap->capacity = capacity; 
    heap->size = 0;
    
    heap->elements = (ElementT *) calloc(capacity+1, sizeof(ElementT));
    return heap;
}

void printHeap(HEAP *H)
{   
    printf("capacity=%d, size=%d\n", H->capacity, H->size);
    int len = H->size - 1;
    for (int j=1; j<=len; j++){
        printf("%d, ", H->elements[j]->key);
    }
    printf("%d\n", H->elements[len+1]->key);
}

int sizeOf(HEAP *H)
{
    return H->size;
}

// inserts object type element into the heap
void insert(HEAP *H, int value)
{
    ElementT element = (ElementT) malloc(sizeof(ELEMENT));
    element->key=value;
    int j = H->size + 1;
    H->elements[j] = element;
    H->size++;
    buildMinHeap(H);
}


// deletes minimum element from the heap
int extractMin(HEAP *H)
{
    H->heaps_called = 0;
    if ((H->size == 1))
    {
        H->size--;
        printf("Deleted key: %d\n", H->elements[1]->key);
        return H->elements[1]->key;
    }
    int len = H->size;
    int minimum_key = H->elements[1]->key;
    printf("Deleted key: %d\n", minimum_key);
    H->elements[1] = H->elements[len];
    H->size--;

    minHeapify(H, 1);
    
    return minimum_key;
}

// decreases key of heap[index] to value
void decreaseKey(HEAP *H, int index, int value)
{
    H->elements[index]->key = value;
    while ((index != 1) && (H->elements[parent(index)]->key > H->elements[index]->key))
    {
        swap(H->elements[index], H->elements[parent(index)]);
        index = parent(index);            
    }
}

void buildMinHeap(HEAP *H)
{   
    H->heaps_called = -1;
    int len = H->size / 2 + 1;
    for (int i = len; i >= 1; i--)
    {
        minHeapify(H, i);
    }

}

void minHeapify(HEAP *H, int index)
{
    H->heaps_called++;
    int l = left(index);
    int r = right(index);
    int smallest = index;
    if((l < (H->size+1)) && (H->elements[l]->key < H->elements[index]->key))
    {
        smallest = l;
    }
    if((r < (H->size+1)) && (H->elements[r]->key < H->elements[smallest]->key))
    {
        smallest = r;
    }
    if(smallest != index) 
    {
        swap(H->elements[index], H->elements[smallest]);
        minHeapify(H, smallest);
    }
}

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return 2*i + 1;
}

int parent(int i)
{
    return i / 2;
}

void swap(ELEMENT *index, ELEMENT *smallest) 
{ 
    int temp;
    temp = index->key; 
    index->key = smallest->key; 
    smallest->key = temp; 
}