#ifndef _graph_h
#define _graph_h 1

#include <stdio.h>


typedef struct TAG_VERTEX{
    int vertex; // vertex ID
    int color;
    int pi;
    float key; // current distance from source vertex
    float dist; // added to fix error
    int pos;
    char *name;
}VERTEX;
typedef VERTEX *pVERTEX;
/*
v[1],v[2], ..., v[n] form an array of n structs of type VERTEX
*/
typedef struct TAG_NODE{
    int u;
    int v;
    float w;        /* weight of edge (u, v) */
    TAG_NODE *next; /* pointer to next node */
}NODE;
typedef NODE *pNODE;
/*
A[1], A[2], ..., A[n] form an array of n pointer of type pNODE.
A[i] is the adjacency list of vertex i.
*/

typedef struct TAG_PATH{
    int vertex;
    TAG_PATH *next;
}PATH;
typedef PATH *pPATH;


void printPath(int n, int source, int destination, int s, int t);
void dijkstra(int n, pNODE *A, int s, int t, int flag);

extern VERTEX *V;

#endif