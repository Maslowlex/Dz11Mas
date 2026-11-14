#define _CRT_SECURE_NO_WARNINGS
#include "product.h"

void inputProduct(Product* p, int index) {
    printf("\n--- Ввод товара %d ---\n", index + 1);

    printf("Наименование: ");
    scanf(" %[^\n]", p->name);

    printf("Дата производства (ДД.ММ.ГГГГ): ");
    scanf("%d.%d.%d", &p->manufacture_Date.day, &p->manufacture_Date.month, &p->manufacture_Date.year);

    printf("Срок годности (годен до, ДД.ММ.ГГГГ): ");
    scanf("%d.%d.%d", &p->expiry_Date.day, &p->expiry_Date.month, &p->expiry_Date.year);

    printf("Цена: ");
    scanf("%f", &p->price);

    printf("Номер серии: ");
    scanf("%d", &p->series_Number);
}

void printProductResult(const Product* p) {
    printf("Товар: %-20s | Годен до: %02d.%02d.%04d\n",
        p->name,
        p->expiry_Date.day,
        p->expiry_Date.month,
        p->expiry_Date.year);
}