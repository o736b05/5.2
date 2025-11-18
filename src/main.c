#include "func.h"
#include "load.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("clear");
    int a = 0, b = 1, res;
    int arrSize = 76, matrixSize = 5*6;

    while (b)
    {
        printf("\nВыберите библиотеку:\n1. ArrayLib\n2. MatrixLib\n3. Выход\n");
        res = scanf("%d", &a);

        if(res != 1)
        {
            puts("Некорректный ввод");
            for(int c;(c = getchar()) != '\n' && c != EOF;);
            continue;
        }

        if (a == 1)
        {
            system("clear");
            LoadRun("libarrayfunc.so", arrSize);
        }
        if (a == 2)
        {
            system("clear");
            LoadRun("libmatrixfunc.so", matrixSize);
        }
        if (a == 3)
            b = 0;
    }
    return 0;
}
