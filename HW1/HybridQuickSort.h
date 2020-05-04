#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

static int Max(int a, int b);
static int Min(int a, int b);
static int Middle(int a, int b, int c);
static int PickMedianOfThree(int arr[], int left, int right);

static void Swap(int arr[], int idx1, int idx2);
static int Partition(int arr[], int left, int right);

void InsertionSort(int arr[], int left, int right);
void HybridQuickSort(int arr[], int left, int right);

#endif
