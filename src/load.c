#include "load.h"
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void LoadRun(const char* const libName, unsigned int size)
{
    void* lib;
    void (*func)(int, int*);

    // Загрузка библиотеки в память
    lib = dlopen(libName, RTLD_LAZY);
    if (!lib)
    {
        printf("Не удалось загрузить библиотеку '%s': %s\n", libName, dlerror());
        return;
    }
    printf("Библиотека загружена '%s'\n", libName);

    int* arr = malloc(size * sizeof(int));
    if (!arr)
    {
        printf("Память под массив не выделена");
        dlclose(lib);
        return;
    }

    func = (void (*)(int, int*))dlsym(lib, "FillArrRndmNum");
    if (func == NULL)
        printf("Не удалось загрузить функцию 'FillArrRndmNum': %s\n", dlerror());
    else
        func(size, arr);

    int exit = 0, choice, res;
    while (!exit)
    {
        puts("\nВыберите действие:");
        puts("1. Заполнить случайными числами");
        puts("2. Заменить числа кратные 3 на 1");
        puts("3. Вывести массив");
        puts("4. Назад");

        res = scanf("%d", &choice);

        if (res != 1)
        {
            puts("Некорректный ввод");
            for(int c;(c = getchar()) != '\n' && c != EOF;);
            continue;
        }

        switch (choice)
        {
        case 1:
            func = (void (*)(int, int*))dlsym(lib, "FillArrRndmNum");
            if (func == NULL)
                printf("Не удалось загрузить функцию 'FillArrRndmNum': %s\n", dlerror());
            else
                func(size, arr);
            break;
        case 2:
            func = (void (*)(int, int*))dlsym(lib, "ChangeArray");
            if (func == NULL)
                printf("Не удалось загрузить функцию 'ChangeArray': %s\n", dlerror());
            else
                func(size, arr);
            break;
        case 3:
            func = (void (*)(int, int*))dlsym(lib, "OutputArray");
            if (func == NULL)
                printf("Не удалось загрузить функцию 'OutputArray': %s\n", dlerror());
            else
                func(size, arr);
            break;
        case 4:
            exit = 1;
            break;
        default:
            puts("Некорректный ввод");
        }
    }

    free(arr);
    dlclose(lib);  // Выгрузка библиотеки
    printf("\nБиблиотека выгружена '%s'\n", libName);
}
