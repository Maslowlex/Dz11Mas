#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "product.h"

int main() {
    setlocale(LC_ALL, "RUS");
    system("chcp 1251 > nul"); 

    Product products[3];

    printf("=== Программа учета товаров (Вариант 13) ===\n");
    printf("===        Маслов А.Е. бИЦТ-262          ===\n");

    for (int i = 0; i < 3; i++) {
        inputProduct(&products[i], i);
    }

    printf("\n=== Результат ===\n");
    for (int i = 0; i < 3; i++) {
        printProductResult(&products[i]);
    }

    return 0;
}