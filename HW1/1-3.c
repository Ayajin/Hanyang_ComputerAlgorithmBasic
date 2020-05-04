#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "HybridQuickSort.h"

#define MAX_NUM 10000

int main (void)
{
    FILE *fp;
    char* tok;
    char temp[MAX_NUM];
    int inputArray[MAX_NUM];
    int count = 0;

    clock_t start, end;
    float delay;

    //Read Input File & Copy to Array
    fp = fopen("input1-3.txt", "rt");
    if(fp == NULL)
    {
        printf("fail\n");
        return 1;
    }

    fgets(temp, MAX_NUM, fp);

    inputArray[0] = atoi(strtok(temp, " "));
    count++;
    if (inputArray[0] >= 1000)
    {
        printf("error");
        return -1;
    }

    for(int i = 1; i < MAX_NUM; i++)
    {
        tok = strtok(NULL, " ");
        if(tok == NULL)
            break;

        inputArray[i] = atoi(tok);
        count++;

        if (inputArray[i] >= 1000)
        {
            printf("error");
            return -1;
        }
    }
    if (count < 3)
    {
        printf("error");
        return -1;
    }
    fclose(fp);

    
    start = clock();
    HybridQuickSort(inputArray, 0, count - 1);
    end = clock();
    delay = (float)(end - start) / CLOCKS_PER_SEC ;
    

    //Write Output File
    fp = fopen("output1-3.txt", "w");
    if(fp == NULL)
    {
        printf("fail\n");
        return 1;
    }

    for(int i = 0; i < count; i++)
        fprintf(fp, "%d ", inputArray[i]);
    
    fprintf(fp, "\n%f s", delay);

    fclose(fp);

    return 0;
}