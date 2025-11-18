#include "load.h"
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void LoadRun(const char* const libName, unsigned int size)
{
	void* lib;
	void (*func)(int, int*);
	lib = LoadLibrary(libName);
	//загрузка библиотеки в память
	if (!lib)
	{
		printf("Не удалось загрузить библиотеку '%s'\n", libName);
		return;
	}
	printf("Загружена библиотека '%s'\n", libName);

	int* arr = malloc(size * sizeof(int));
	if (!arr)
	{
		printf("Память под массив не выделилась");
		return;
	}

	func = (void (*)(int, int*))GetProcAddress((HINSTANCE)lib, "FillArrRndmNum");
	if (func == NULL)
		printf("Не удалось загрузить функцию 'FillArrRndmNum'\n");
	else
		func(size, arr);

	int exit = 0, choice, res;
	while (!exit)
	{
		puts("\nДействия над массивом:");
		puts("1. Заполнить случайными числами");
		puts("2. Заменить числа кратные тройке на единицу");
		puts("3. Вывести массив");
		puts("4. Выход");

		res = scanf("%d", &choice);
        if (res != 1)
        {
            // Если ввод не соответствует формату %d
            puts("Ошибка: введите число от 1 до 4");
            // Полностью очищаем буфер ввода
            for(int c;(c = getchar()) != '\n' && c != EOF;);

            continue;
        }

		switch (choice)
		{
		case 1:
			func = (void (*)(int, int*))GetProcAddress((HINSTANCE)lib, "FillArrRndmNum");
			if (func == NULL)
				printf("Не удалось загрузить функцию 'FillArrRndmNum'\n");
			else
				func(size, arr);
			break;
		case 2:
			func = (void (*)(int, int*))GetProcAddress((HINSTANCE)lib, "ChangeArray");
			if (func == NULL)
				printf("Не удалось загрузить функцию 'ChangeArray'\n");
			else
				func(size, arr);
			break;
		case 3:
			func = (void (*)(int, int*))GetProcAddress((HINSTANCE)lib, "OutputArray");
			if (func == NULL)
				printf("Не удалось загрузить функцию 'OutputArray'\n");
			else
				func(size, arr);
			break;
		case 4:
			exit = 1;
			break;
		default:
		    {
		        while (getchar() != '\n'); // Очистка буфера
                puts("Неверный ввод");
		    }
		}
	}

	free(arr);
	FreeLibrary((HINSTANCE)lib); //выгрузка библиотеки
	printf("\nБиблиотека '%s' выгружена\n", libName);
}
