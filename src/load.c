#include "load.h"
#include "func.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

void LoadRun(const char* const libName, unsigned int size)
{
    // Объявления для обеих платформ
#ifdef _WIN32
    HINSTANCE lib;
#else
    void* lib;
#endif
    void (*func)(int, int*);

    // Загрузка библиотеки
#ifdef _WIN32
    lib = LoadLibrary(libName);
#else
    lib = dlopen(libName, RTLD_LAZY);
#endif
    if (!lib)
    {
#ifdef _WIN32
        printf("Не удалось загрузить библиотеку '%s'\n", libName);
#else
        printf("Не удалось загрузить библиотеку '%s': %s\n", libName, dlerror());
#endif
        return;
    }
    printf("Библиотека загружена '%s'\n", libName);

    // Выделение памяти для массива
    int* arr = malloc(size * sizeof(int));
    if (!arr)
    {
        printf("Память под массив не выделена");
#ifdef _WIN32
        FreeLibrary(lib);
#else
        dlclose(lib);
#endif
        return;
    }

    // Получение функции FillArrRndmNum
#ifdef _WIN32
    func = (void (*)(int, int*))GetProcAddress(lib, "FillArrRndmNum");
#else
    func = (void (*)(int, int*))dlsym(lib, "FillArrRndmNum");
#endif
    if (func == NULL)
    {
#ifdef _WIN32
        printf("Не удалось загрузить функцию 'FillArrRndmNum'\n");
#else
        printf("Не удалось загрузить функцию 'FillArrRndmNum': %s\n", dlerror());
#endif
    }
    else
    {
        func(size, arr);
    }

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
            for(int c; (c = getchar()) != '\n' && c != EOF;);
            continue;
        }

        switch (choice)
        {
        case 1:
#ifdef _WIN32
            func = (void (*)(int, int*))GetProcAddress(lib, "FillArrRndmNum");
#else
            func = (void (*)(int, int*))dlsym(lib, "FillArrRndmNum");
#endif
            if (func == NULL)
            {
#ifdef _WIN32
                printf("Не удалось загрузить функцию 'FillArrRndmNum'\n");
#else
                printf("Не удалось загрузить функцию 'FillArrRndmNum': %s\n", dlerror());
#endif
            }
            else
            {
                func(size, arr);
            }
            break;

        case 2:
#ifdef _WIN32
            func = (void (*)(int, int*))GetProcAddress(lib, "ChangeArray");
#else
            func = (void (*)(int, int*))dlsym(lib, "ChangeArray");
#endif
            if (func == NULL)
            {
#ifdef _WIN32
                printf("Не удалось загрузить функцию 'ChangeArray'\n");
#else
                printf("Не удалось загрузить функцию 'ChangeArray': %s\n", dlerror());
#endif
            }
            else
            {
                func(size, arr);
            }
            break;

        case 3:
#ifdef _WIN32
            func = (void (*)(int, int*))GetProcAddress(lib, "OutputArray");
#else
            func = (void (*)(int, int*))dlsym(lib, "OutputArray");
#endif
            if (func == NULL)
            {
#ifdef _WIN32
                printf("Не удалось загрузить функцию 'OutputArray'\n");
#else
                printf("Не удалось загрузить функцию 'OutputArray': %s\n", dlerror());
#endif
            }
            else
            {
                func(size, arr);
            }
            break;

        case 4:
            exit = 1;
            break;

        default:
            puts("Некорректный ввод");
            while (getchar() != '\n');
        }
    }

    free(arr);

    // Выгрузка библиотеки
#ifdef _WIN32
    FreeLibrary(lib);
#else
    dlclose(lib);
#endif
    printf("\nБиблиотека выгружена '%s'\n", libName);
}
