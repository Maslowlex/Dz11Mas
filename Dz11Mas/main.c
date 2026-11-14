#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "product.h"
#include "stdlib.h"
int main() {
    setlocale(LC_ALL, "RUS");
    system("chcp 1251 > nul");
    int choice;
    int repeat = 1;

    do {
        printf("\n==============================\n");
        printf("   ДЗ: Структуры данных (Вар. 13)\n");
        printf("==============================\n");
        printf("1 - Запустить программу (Ввод 3 товаров)\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Завершение.\n");
            break;
        }

        switch (choice) {
        case 1:
            runTask();
            break;
        case 0:
            printf("Выход.\n");
            repeat = 0;
            break;
        default:
            printf("Неверный выбор.\n");
        }
    } while (repeat != 0);

    return 0;
}