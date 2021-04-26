#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"
#include "graph.h"


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
    heap->H = (pELEMENT *) malloc(sizeof(pELEMENT));
    
    return heap;
}

// inserts object type element into the heap
int HeapInsert(HEAP *heap, pELEMENT item)
{
    if (heap->size >= heap->capacity){
        printf("Problem in Insert: Heap full...\n");
        return 1;
    }
    heap->size++;
    heap->H[heap->size]=item;
    heap->H[heap->size]->pos = heap->size;
    
    MovingUp(heap, heap->size);
    
    return 0;
}

int Insert(HEAP *heap, pELEMENT item)
{
    if (heap->size >= heap->capacity){
        printf("Problem in Insert: Heap full...\n");
        return 1;
    }
    heap->size++;
    heap->H[heap->size]=item;
    V[heap->H[heap->size]->vertex].pos = heap->size;
    MovingUp(heap, heap->size);
    return 0;
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
        V[heap->H[parent]->vertex].pos = parent;
        MovingUp(heap, parent);
    }

}


// decreases key of heap[index] to value
int DecreaseKey(HEAP *heap, int pos, int newKey)
{
    if (pos < 1 || pos > heap->size || newKey >= heap->H[pos]->key){
        printf("Error: invalid call to DecreaseKey\n");
        return 1;
    }
    heap->H[pos]->key = newKey;
    MovingUp(heap, pos);
    return 0;
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
    
    // MovingDown(heap, 1, flag, count_Heapify);
    
    V[min->vertex].pos = 0;
    return min;
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

void minHeapify(HEAP *heap, int index)
{
    heap->heaps_called++;
    int l = left(index);
    int r = right(index);
    int smallest = index;
    if((l < (heap->size+1)) && (heap->elements[l]->key < heap->elements[index]->key))
    {
        smallest = l;
    }
    if((r < (heap->size+1)) && (heap->elements[r]->key < heap->elements[smallest]->key))
    {
        smallest = r;
    }
    if(smallest != index) 
    {
        swap(heap->elements[index], heap->elements[smallest]);
        minHeapify(heap, smallest);
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



// void printHeap(HEAP *H)
// {   
//     printf("capacity=%d, size=%d\n", H->capacity, H->size);
//     int len = H->size - 1;
//     for (int j=1; j<=len; j++){
//         printf("%d, ", H->elements[j]->key);
//     }
//     printf("%d\n", H->elements[len+1]->key);
// } 

int sizeOf(HEAP *H)
{
    return H->size;
}

