#include "func.h"
#include "load.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
	system("cls");
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a = 0, b = 1, res;
	int arrSize = 76, matrixSize = 5*6;

	while (b)
	{
		printf("\nВыберите библиотеку:\n1. ArrayLib\n2. MatrixLib\n3. Выход\n");
		res = scanf("%d", &a);
        if (res != 1)
        {
            // Если ввод не соответствует формату %d
            puts("Ошибка: введите число от 1 до 3");
            // Полностью очищаем буфер ввода
            for(int c; (c = getchar()) != '\n' && c != EOF;);

            continue;
        }
		if (a == 1)
		{
			system("cls");
			LoadRun("arrayfunc.dll", arrSize);
		}
		else if (a == 2)
		{
			system("cls");
			LoadRun("matrixfunc.dll", matrixSize);
		}
		else if (a == 3)
			b = 0;
        else
            while (getchar() != '\n'); // Очистка буфера
	}
	return 0;
}
