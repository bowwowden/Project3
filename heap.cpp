#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

// free
void heapFree(HEAP *heap)
{
    free(heap->H);
    free(heap);
}

HEAP *heapInit(int capacity)
{
    HEAP *heap;
    heap = (HEAP *) calloc(1, sizeof(HEAP));
    heap->capacity = capacity; 
    heap->size = 0;
    
    heap->elements = (ElementT *) calloc(capacity+1, sizeof(ElementT));
    return heap;
}

// inserts object type element into the heap
void HeapInsert(HEAP *H, int value)
{
    if (heap->size >= heap->capacity){
        printf("Problem in Inser: Heap full...\n");
        return 1;
    }
    
    heap->size++;
    heap->H[heap->size]=item;
    V[heap->H[heap->size]->vertex].pos = heap->size;
    MovingUp(heap, heap->size);
    return 0;
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


void MovingUp (HEAP *heap, int pos) 
{
    pELEMENT temp;
    int parent;

    parent = pos/2;
    if (pos > 1 && heap->H[pos]->key < heap->H[parent]->key)
    {
        temp = heap->H[pos];
        heap->H[pos] = heap->H[parent];
        heap->H[parent] = temp;
        V[heap->H[pos]->vertex].pos = pos;
        V[heap->H[parent]->vertex].parent = parent;
        MovingUp(heap, parent);
    }

}

pELEMENT DeleteMin (HEAP *heap, int *flag, int *count_Heapify)
{
    pELEMENT min, last;
    
    if (heap->size <= 0) {
        printf("Error in DeleteMin: heap empty\n");
        return NULL;
    }
    min = heap->H[1];
    last = heap->H[heap->size--];
    heap->H[1] = last;
    V[heap->H[1]->vertex].pos = 1;
    MovingDown(heap, 1, flag, count_Heapify);
    V[min->vertex].pos = 0;
    return min;
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