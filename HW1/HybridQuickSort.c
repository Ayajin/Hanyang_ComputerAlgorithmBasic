#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HybridQuickSort.h"

const int CONVERT_QUICK = 10;

static int Max(int a, int b)
{
    return a >= b ? a : b;
}

static int Min(int a, int b)
{
    return a < b ? a : b;
}

static int Middle(int a, int b, int c)
{
    return a + b + c - Max(Max(a, b), c) - Min(Min(a, b), c);
}

static int PickMedianOfThree(int arr[], int left, int right)
{
    int a, b, c, result;
    int len = right - left + 1;

    srand((unsigned int)time(NULL));

    a = rand()%len + left;
    b = rand()%len + left;
    c = rand()%len + left;

    result = Middle(arr[a], arr[b], arr[c]);

    if(arr[a] == result)
        return a;

    else if(arr[b] == result)
        return b;

    else
        return c;    
}

static void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

static int Partition(int arr[], int left, int right)
{
    int pivotIndex = PickMedianOfThree(arr, left, right);
    int pivotValue = arr[pivotIndex];

    Swap(arr, left, pivotIndex);

    int low = left + 1;
    int high = right;

    while(low <= high)
    {
        while(pivotValue >= arr[low])
            low++;

        while(pivotValue < arr[high])
            high--;

        if(low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, left, high);

    return high;
}

void InsertionSort(int arr[], int left, int right)
{
    int i, j;
    int insertData;

    for(i = left + 1; i <= right; i++)
    {
        insertData = arr[i];

        for(j = i - 1; j>=0; j--)
        {
            if(arr[j] > insertData)
                arr[j+1] = arr[j];
            else
                break;
        }
        
        arr[j+1] = insertData;
    }
}

void HybridQuickSort(int arr[], int left, int right)
{
    if(left + CONVERT_QUICK > right)
        InsertionSort(arr, left, right);
    else if(left <= right)
    {
        int pivotIdx = Partition(arr, left, right);
        HybridQuickSort(arr, left, pivotIdx - 1);
        HybridQuickSort(arr, pivotIdx + 1, right);
    }
    return;
}


