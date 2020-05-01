#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Heap.h"
#include "Queue.h"


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
    FILE *fp;
    int numOfArray, check, count = 1;
    char temp[100];
    char* tok;
    int result[10000];

    /************** Read Input File & Copy to Array **************/
    fp = fopen("input1-2.txt", "rt");
    if(fp == NULL)
    {
        printf("fail\n");
        return 1;
    }

	fgets(temp, 100, fp);
	numOfArray = atoi(temp);

    Queue inputArray[101];
    
    for(int i = 1; i <= numOfArray; i++)
    {
        InitQueue(&inputArray[i]);
        fgets(temp, 100, fp);

        Enqueue(&inputArray[i], atoi(strtok(temp, " ")) );

        for(int j=1; j < 50; j++)
        {
            tok = strtok(NULL, " ");
            if(tok == NULL)
                break;

            Enqueue(&inputArray[i], atoi(tok) );
        }
    }

    fclose(fp);
    /************** Read Input File & Copy to Array **************/
    
    Heap heap;
    HeapInit(&heap, MinRule);

    // 정렬된 k개의 배열에서 한 개씩 원소를 뽑아 최소힙 만들기 : O(k)
	for (int i = 1; i <= numOfArray ; i++)
	{
        heap.heapArr[i] = Dequeue(&inputArray[i]);
        heap.numOfData++;
	}

    check = BuildHeap(&heap);

    // 가장 최소의 원소를 가지고 있던 배열에서 가지고와서 Heapify, 모든 배열 종합해서 정렬
    while(heap.numOfData >= 1)
    {
        result[count] = heap.heapArr[1];
        count++;

        int pop = Dequeue(&inputArray[check]);

        if(pop == -1)
        {
            heap.heapArr[1] = heap.heapArr[heap.numOfData];
            heap.numOfData--;

            pop = Dequeue(&inputArray[check]);
            check = BuildHeap(&heap);
        }
        else
        {
            heap.heapArr[1] = pop;
            check = Heapify(&heap, 1);
        }
    }

    //Print out result
    for(int i = 1; i < count; i++)
        printf("%d ", result[i]);

    return 0;
}