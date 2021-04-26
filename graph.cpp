#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "heap.h"


void printPath(int n, int source, int destination, int s, int t)
{
    PATH *pPATH;
    PATH *pNODE;
    int u, v;

    if (V[t].color == 0){
        if (destination < 1 || destination > n || t == destination){
            printf("No %d-%d path exists.\n", s, t);
            return;
        } else {
            printf("No %d-%d path has been computed.\n", s, t);
            return;
        }
    } else if (V[t].color == 1) {
        printf("Path not known to be shortest: <%d", s);
    } else if (V[t].color == 2) {
        printf("Shortest path: <%d", s);
    }

    // push onto stack
    pNODE = (PATH *) malloc(sizeof(PATH));
    pNODE->vertex = t;
    pNODE->next = NULL;
    pPATH = pNODE;
    v = pNODE->vertex;
    while (V[v].pi){
        u = V[v].pi;
        pNODE = (PATH *) malloc(sizeof(PATH));
    }
}

// int main(int argc, char *argv[])
// {
//     int i;

//     for (i = 0; i<argc-1; i++){
//         printf("%s ", argv[i]);
//     }
//     printf("%s\n", argv[argc-1]);

//     printf("argc=%d\n", argc);
//     for(i = 0; i<argc; i++){ 
//         printf("argv[%d]=%s\n", i, argv[i]);
//     }

//     return 0;
// }

void dijkstra(int n, pNODE *A, int s, int t, int flag)
{
    printf("Did it seg fault yet");
    pNODE node;
    HEAP *heap;
    ELEMENT *element;

    int u, v, i;
    float w;

    int pos;
    int count_Heapify;

    for (i=1; i<=n; i++){
        V[i].color = 0;
        V[i].pi = 0;
    }   
    V[s].dist = 0;
    V[s].color = 1;

    // // instead of initializing a single source, initialize a minheap
    heap = heapInit(n);
    buildMinHeap(heap);
    


    element = (ELEMENT *) malloc(sizeof(ELEMENT));
    element->vertex = s;
    element->key = 0;
    bool Error = false;
    if (Insert(heap, element) == 0)
    {
        Error = false;
    }
    else {
        Error = true;
    }
    if (flag == 1){
        // print insertion information
        printf("Insert vertex %d, key=%12.4f\n", element->vertex, element->key);
    }
    while (heap->size){
        element = DeleteMin(heap, &flag, &count_Heapify);
        if (flag == 1){
            printf("Delete vertex %d, key=%12.4f\n", element->vertex, element->key);
        }
        u = element->vertex;
        V[u].color = 2;
        if (element->vertex == t){ 
            break;
        }
        free(element);

        node = A[u];
        while (node) {
            v = node->v;
            w = node->w;
            if (V[v].color == 0) {
                V[v].dist = V[u].dist + w;
            }
            node = node->next;
        }
        printf("loop 2 exited");
    }    
}

void relax(){

}