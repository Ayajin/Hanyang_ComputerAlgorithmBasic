#include <stdio.h>
#include "Heap.h"


int MaxRule(int a, int b)
{
    //For MaxHeap
    return a-b;

    //For MinHeap
    //return b-a;
}

int MinRule(int a, int b)
{
    //For MaxHeap
    // return a-b;

    // For MinHeap
    return b-a;
}

int main()
{
	int temp, size;
    Heap heap;
    HeapInit(&heap, MaxRule);

	//input n natural number
	for (int i = 1; i < 101; i++)
	{
		scanf("%d", &temp);

        if(temp == -1)
		    break;

        heap.heapArr[i] = temp;
        heap.numOfData++;
	}

    BuildHeap(&heap);

    while(heap.numOfData >= 1)
    {
        temp = heap.heapArr[1];

        printf("%d ", temp);

        heap.heapArr[1] = heap.heapArr[heap.numOfData];

        heap.numOfData--;
        Heapify(&heap, 1);
    }

    return 0;
}