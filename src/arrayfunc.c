#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillArrRndmNum(int size, int* arr)
{
    srand(time(0));
    int max = 50, min = -50;
    for (int i = 0; i < size; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
    puts("\nМассив заполнен случайными числами");
}

void ChangeArray(int size, int* arr)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 3 == 0)
        {
            arr[i] = 1;
        }
    }
    puts("\nЭлементы массива кратные трём заменены на единицы");
}

void OutputArray(int size, int* arr)
{
    puts("\nArray:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d.\t%d\n", i + 1, arr[i]);
    }
}
