#define _CRT_SECURE_NO_WARNINGS
#include "product.h"

void inputProduct(Product* p, int index) {
    printf("\n--- Ввод товара %d ---\n", index + 1);

    printf("Наименование: ");
    scanf(" %[^\n]", p->name);

    printf("Дата производства (ДД.ММ.ГГГГ): ");
    scanf("%d.%d.%d", &p->manufactureDate.day, &p->manufactureDate.month, &p->manufactureDate.year);

    printf("Срок годности (годен до, ДД.ММ.ГГГГ): ");
    scanf("%d.%d.%d", &p->expiryDate.day, &p->expiryDate.month, &p->expiryDate.year);

    printf("Цена: ");
    scanf("%f", &p->price);

    printf("Номер серии: ");
    scanf("%d", &p->seriesNumber);
}

void printProductResult(const Product* p) {
    printf("Товар: %-20s | Годен до: %02d.%02d.%04d\n",
        p->name,
        p->expiryDate.day,
        p->expiryDate.month,
        p->expiryDate.year);
}