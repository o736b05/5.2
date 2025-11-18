#include "func.h"
#include "load.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#define LIB_EXT ".dll"
#else
#define CLEAR_SCREEN "clear"
#define LIB_EXT ".so"
#endif

int main(void) {
    system(CLEAR_SCREEN);

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    #else
    setlocale(LC_ALL, "ru_RU.UTF-8");
    #endif

    int a = 0, b = 1, res;
    int arrSize = 76, matrixSize = 5*6;
    const char* arrayLibName = "libarrayfunc" LIB_EXT;
    const char* matrixLibName = "libmatrixfunc" LIB_EXT;

    while (b) {
        printf("\nВыберите библиотеку:\n1. ArrayLib\n2. MatrixLib\n3. Выход\n");
        res = scanf("%d", &a);

        if(res != 1) {
            puts("Некорректный ввод");
            for(int c; (c = getchar()) != '\n' && c != EOF;);
            continue;
        }

        if (a == 1) {
            system(CLEAR_SCREEN);
            LoadRun(arrayLibName, arrSize);
        }
        else if (a == 2) {
            system(CLEAR_SCREEN);
            LoadRun(matrixLibName, matrixSize);
        }
        else if (a == 3) {
            b = 0;
        }
        else {
            puts("Неверный выбор. Введите число от 1 до 3");
            while (getchar() != '\n');
        }
    }
    return 0;
}
