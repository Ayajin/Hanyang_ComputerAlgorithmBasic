#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_LEN 500
 
void backTracking(int m, int n);

int main()
{
    FILE *fp;
    char Input1[500];
    char Input2[500];
    int Map[501][501];
    char result[501];
    
    //Read Input File & put strings to each array
    fp = fopen("input2-2.txt", "rt");
    if(fp == NULL)
    {
        printf("fail\n");
        return 1;
    }

    fgets(Input1, MAX_LEN, fp);
    fgets(Input2, MAX_LEN, fp);

    fclose(fp);


    // 개행문자 제거
    Input1[strlen(Input1) - 1] = '\0';

    // LCS를 위해 앞에 '0'을 넣는다.
    char temp1[501] = "0";
    char temp2[501] = "0";
    char* str1 = strcat(temp1, Input1);
    char* str2 = strcat(temp2, Input2);
 
    // 길이측정, 0을 임의로 추가했기에 1을 빼준다.
    int len1 = strlen(str1) - 1;
    int len2 = strlen(str2) - 1;

    // LCS Alogrithm을 통해 Map 배열을 채운다.
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if ((i == 0) || (j == 0))
                Map[i][j] = 0;
            else
            {
                // 현재 비교하는 값이 서로 같다면, lcs는 + 1
                if (str1[i] == str2[j])
                    Map[i][j] = Map[i - 1][j - 1] + 1;
 
                // 서로 다르다면 LCS의 값을 왼쪽 혹은 위에서 가져온다.
                else
                {
                    if (Map[i - 1][j] > Map[i][j - 1])
                        Map[i][j] = Map[i - 1][j];
                    else
                        Map[i][j] = Map[i][j - 1];
                }
            }
        }
    }

    //Map 배열을 통해서 Longest Common Subsequence 출력, 역추적해서 result 배열에 넣어준다.
    int i = len1;
    int j = len2;
    int LCSlen = Map[i][j]; // 총 길이 입력
    result[LCSlen] = '\0';  // 문자열 끝 널문자 추가
    LCSlen--;

    while(LCSlen + 1) // result[LCSlen]이 0번째 index까지 채워줘야하므로 LCSlen + 1 까지 돌게 한다.
    {
        if((i == 0) || (j == 0))
            break;

        if(str1[i] == str2[j])
        {
            result[LCSlen] = str2[j]; // 같으므로 대입
            i--; j--;
            LCSlen--;
        }
        else
        {
            if(Map[i][j] == Map[i-1][j])
            {
                i--;
            }
            else if(Map[i][j] == Map[i][j-1])
            {
                j--;
            }
            else
            {
                i--; j--;
            }
        }
    }
    
    //결과 출력
    printf("%s", result);

    return 0;
}

