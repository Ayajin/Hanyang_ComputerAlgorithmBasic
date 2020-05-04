#ifndef _Queue_H_
#define _Queue_H_

#define TRUE 1
#define FALSE 0

#define Queue_Size 100

typedef struct queue{
    int head;
    int tail;
    int arr[Queue_Size];
}Queue;

void InitQueue(Queue * Queue);
int IsQueue_Empty(Queue * Queue);
void Enqueue(Queue * Queue, int data);
int Dequeue(Queue * Queue);

#endif