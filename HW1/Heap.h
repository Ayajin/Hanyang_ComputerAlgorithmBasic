#ifndef Heap_H
#define Heap_H

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 10000

typedef int DATATYPE;
typedef int (*PriorityComp) (DATATYPE a, DATATYPE b);

typedef struct _Heap
{
    int numOfData;
    DATATYPE heapArr[HEAP_LEN];
    PriorityComp comp;

    //Checking Array for 1-2
    int CheckArr[100];
} Heap;

int GetParentIdx(int idx);
int GetLChildIdx(int idx);
int GetRChildIdx(int idx);

int GetHighPriorityChildIdx(Heap *Heap, int idx);

void HeapInit(Heap *Heap, PriorityComp comp);
int IsHeapEmpty(Heap *Heap);

int Heapify(Heap *Heap, int idx);
int BuildHeap(Heap *Heap);

#endif