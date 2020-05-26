#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void CutRod(int PriceOfLength[], int MaximumRevenue[], int CutPosition[], int RodLength);
void PrintCutPos(int CutPosition[], int RodLength);

int main(void)
{
    FILE *fp;
    char temp[100];
    char* tok;

    int RodLength;
    int PriceOfLength[101];
    int MaximumRevenue[101];
    int CutPosition[101];

    //Read Input File & Get Price of specific length of Rod
    fp = fopen("input2-1.txt", "rt");
    if(fp == NULL)
    {
        printf("fail\n");
        return 1;
    }

    fgets(temp, 100, fp);

    RodLength = atoi(strtok(temp, " "));
    if (RodLength > 100)
    {
        printf("error");
        return -1;
    }

    fgets(temp, MAX_LEN, fp);

    PriceOfLength[0] = 0;
    PriceOfLength[1] = atoi(strtok(temp, " "));

    for(int i = 2; i < MAX_LEN; i++)
    {
        tok = strtok(NULL, " ");

        if(tok == NULL)
            break;

        PriceOfLength[i] = atoi(tok);
    }

    fclose(fp);

    //입력받은 PriceOfLength 배열과 RodLength를 이용하여 MaximumRevenue 배열과 CutPosition 배열을 채운다.
    CutRod(PriceOfLength ,MaximumRevenue, CutPosition, RodLength);

    //최대의 이익을 출력한다.
    printf("%d\n", MaximumRevenue[RodLength]);

    //각각 어디서 잘라야하는지를 기록해놓은 CutPosition 배열을 출력하는 함수를 호출한다.
    PrintCutPos(CutPosition, RodLength);   

    return 0;
}

void CutRod(int PriceOfLength[], int MaximumRevenue[], int CutPosition[], int RodLength)
{
    MaximumRevenue[0] = 0;

    for (int j = 1; j <= RodLength; j++)
    {
        int max = 0;

        for(int i = 1; i <= j; i++)
        {
            if (max < (PriceOfLength[i] + MaximumRevenue[j - i]))
            {
                max = PriceOfLength[i] + MaximumRevenue[j - i];
                CutPosition[j] = i;
            }
        }
        MaximumRevenue[j] = max;
    }
}

void PrintCutPos(int CutPosition[], int RodLength)
{
    while(RodLength != CutPosition[RodLength])
    {
        printf("%d ", CutPosition[RodLength]);
        RodLength -= CutPosition[RodLength];
    } 

    printf("%d", CutPosition[RodLength]);

}