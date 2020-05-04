#include "Heap.h"

int GetParentIdx(int idx)
{
    return idx/2;
}

int GetLChildIdx(int idx)
{
    return idx*2;
}

int GetRChildIdx(int idx)
{
    return idx*2 + 1;
}

int GetHighPriorityChildIdx(Heap *Heap, int idx)
{
    //arr[idx] has no child
    if(Heap->numOfData < GetLChildIdx(idx))
        return 0;

    //arr[idx] only has left child
    else if(Heap->numOfData == GetLChildIdx(idx))
        return GetLChildIdx(idx);

    //arr[idx] has 2 child
    else
    {
        //compare left child and right child, if left has more priority
        if(Heap->comp( Heap->heapArr[GetLChildIdx(idx)], Heap->heapArr[GetRChildIdx(idx)]) > 0)
            return GetLChildIdx(idx);
        else
            return GetRChildIdx(idx);      
    }
}

void HeapInit(Heap *Heap, PriorityComp comp)
{
    Heap->numOfData = 0;
    Heap->comp = comp;

    for(int i = 0; i < 100; i++)
        Heap->CheckArr[i] = i;
}

int IsHeapEmpty(Heap *Heap)
{
    if (Heap->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int Heapify(Heap *Heap, int idx)
{
    int highPriorityNode = GetHighPriorityChildIdx(Heap, idx);

    //Parent node has more High Priority || node(idx) has High Priority than other 2 child node
    if(Heap->comp( Heap->heapArr[idx], Heap->heapArr[highPriorityNode] ) >= 0 || highPriorityNode == 0)
        return Heap->CheckArr[1];
    
    DATATYPE temp = Heap->heapArr[idx];
    Heap->heapArr[idx] = Heap->heapArr[highPriorityNode];
    Heap->heapArr[highPriorityNode] = temp;

    //For solve 1-2 by check original array
    int checkTemp = Heap->CheckArr[idx];
    Heap->CheckArr[idx] = Heap->CheckArr[highPriorityNode];
    Heap->CheckArr[highPriorityNode] = checkTemp;
    
    Heapify(Heap, highPriorityNode);
}

int BuildHeap(Heap *Heap)
{
    int check;

    int len = Heap->numOfData;
    int i = len / 2;

    for(i; i > 0; i--)
        check = Heapify(Heap, i);
    
    return check;
}