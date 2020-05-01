#include <stdio.h>
#include "Queue.h"

void InitQueue(Queue * Queue)
{
    Queue->head = 0;
    Queue->tail = 0;
}

int IsQueue_empty(Queue * Queue)
{
    if(Queue->head == Queue->tail)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *Queue, int data)
{
    Queue->head = Queue->head + 1;
    Queue->arr[Queue->head] = data;
}

int Dequeue(Queue *Queue)
{
    int data;

    if( IsQueue_empty(Queue))
        return -1;
    
    Queue->tail = Queue->tail + 1;
    data = Queue->arr[Queue->tail];

    return data;
}