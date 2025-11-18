#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillArrRndmNum(int size, int* matrix)
{
    srand(time(0));
    int max = 50, min = -50;
    for (int i = 0; i < size; i++)
    {
        matrix[i] = min + rand() % (max - min + 1);
    }
    puts("\nМатрица заполнена случайными числами");
}

void ChangeArray(int size, int* matrix)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix[i] % 3 == 0)
        {
            matrix[i] = 1;
        }
    }
    puts("\nЭлементы матрицы кратные трём заменены на еденицы");
}

void OutputArray(int size, int* matrix)
{
    puts("\nMatrix:");
    for (int i = 0; i < size; i++)
    {
        if (i % 5 == 0)
            printf("\n%d|\t", (i / 5) + 1);
        printf("%d\t", matrix[i]);
    }
    puts("");
}
