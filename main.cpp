#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "heap.h"
int main()
{
    char c;
    int n, flag, value;

    HEAP *heap;
    ElementT element;
    FILE *ifile, *ofile;
    int j, number;

    heap = NULL;

    while(1){
        c = nextCommand(&n, &flag, &value);
        switch (c) {
            case 's':
            case 'S': 
                exit(0);
            
            case 'c':
            case 'C': 
                heap = heapInit(n);
                break;
            
            case 'r':
            case 'R': 
                ifile = fopen("HEAPinput.txt", "r");
                if (!ifile){
                    printf("Error: cannot open file for reading\n");
                    break;
                }
                fscanf(ifile, "%d", &n);
                if (heap==NULL || heap->capacity < n) {
                    printf("Error: heap overflow\n");
                    break;
                }
                heap->size = 0;
                for (j=1; j<=n; j++){
                    fscanf(ifile, "%d", &number);
                    element = (ElementT) malloc(sizeof(ELEMENT));
                    element->key=number;
                    heap->elements[j] = element;
                    heap->size++;
                } 
                if (flag == 1){
                    buildMinHeap(heap);
                    printf("Number of Heapify calls: %d\n", heap->heaps_called);
                }
                else {
                    buildMinHeap(heap);
                }
                break;

            case 'w':
            case 'W':
                if (heap == NULL){
                    printf("Error: cannot write\n");
                    break;
                }
                ofile = fopen("HEAPoutput.txt", "w");
                if (!ofile) { 
                    printf("Error: cannot open file for writing\n");
                    break;
                }
                fprintf(ofile, "%d\n", heap->size);
                for (j=1; j<=heap->size; j++){
                    fprintf(ofile, "%d\n", heap->elements[j]->key);
                }
                fclose(ofile);
                break;

            case 'p':
            case 'P':
                if ((heap == NULL)||(heap->size == 0)){
                    printf("capacity=%d, size=%d\n", heap->capacity, heap->size);
                    printf("Error: heap is NULL or empty\n");
                    exit(0);
                    break;
                }
                printHeap(heap);
                break;

            case 'd':
            case 'D':
                if ((heap == NULL)||(heap->size == 0))
                {
                    printf("Error: heap is NULL or empty\n");
                    break;
                }
                if (flag == 1){
                    extractMin(heap);
                    if(heap->size == 0){
                        printf("Number of Heapify calls: %d\n",1);
                    }
                    else {
                        printf("Number of Heapify calls: %d\n", heap->heaps_called);
                    }
                }
                else {
                    extractMin(heap);
                }
                break;
            
            case 'i':
            case 'I':
                if ((heap == NULL)||(heap->size == heap->capacity))
                {
                    printf("Error: heap is NULL or full\n");
                    break;
                }
                insert(heap, flag);
                break;
            
            case 'k':
            case 'K':
                if ((heap == NULL)||(flag > heap->size))
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                decreaseKey(heap, flag, value);
                break;


            default: 
                break;
        }
    }
    exit(0);
}