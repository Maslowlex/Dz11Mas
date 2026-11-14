#define _CRT_SECURE_NO_WARNINGS
#include "product.h"
#include <string.h>

Date getCurrentDate() {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    Date current;
    current.day = tm->tm_mday;
    current.month = tm->tm_mon + 1;
    current.year = tm->tm_year + 1900;
    return current;
}

int compareDates(Date d1, Date d2) {
    if (d1.year > d2.year) return 1;
    if (d1.year < d2.year) return -1;

    if (d1.month > d2.month) return 1;
    if (d1.month < d2.month) return -1;

    if (d1.day > d2.day) return 1;
    if (d1.day < d2.day) return -1;

    return 0;
}

int isValid(Date expiry, Date current) {
    return compareDates(expiry, current) >= 0;
}

void inputProduct(Product* p, int index) {
    printf("\n--- Ввод товара %d ---\n", index + 1);
    printf("Наименование: ");

    if (scanf(" %[^\n]", p->name) != 1) {
        p->name[0] = '\0';
    }

    printf("Дата производства (ДД.ММ.ГГГГ): ");
    if (scanf("%d.%d.%d", &p->manufactureDate.day, &p->manufactureDate.month, &p->manufactureDate.year) != 3) {
        printf("Ошибка ввода даты!\n");
    }

    printf("Срок годности (дата 'годен до', ДД.ММ.ГГГГ): ");
    if (scanf("%d.%d.%d", &p->expiryDate.day, &p->expiryDate.month, &p->expiryDate.year) != 3) {
        printf("Ошибка ввода даты!\n");
    }

    printf("Цена: ");
    if (scanf("%f", &p->price) != 1) {
        printf("Ошибка ввода цены!\n");
    }

    printf("Номер серии: ");
    if (scanf("%d", &p->seriesNumber) != 1) {
        printf("Ошибка ввода серии!\n");
    }
}

void printProduct(const Product* p) {
    printf("| %-20s | %02d.%02d.%04d | %02d.%02d.%04d | %8.2f | %6d |\n",
        p->name,
        p->manufactureDate.day, p->manufactureDate.month, p->manufactureDate.year,
        p->expiryDate.day, p->expiryDate.month, p->expiryDate.year,
        p->price,
        p->seriesNumber);
}

void runTask() {
#define COUNT 3
    Product products[COUNT];
    Date today = getCurrentDate();

    printf("Текущая дата (системная): %02d.%02d.%04d\n", today.day, today.month, today.year);

    for (int i = 0; i < COUNT; i++) {
        inputProduct(&products[i], i);
    }

    printf("\n==========================================================================================\n");
    printf("| %-20s | %-10s | %-10s | %-8s | %-6s |\n", "Наименование", "Произв.", "Годен до", "Цена", "Серия");
    printf("==========================================================================================\n");
    for (int i = 0; i < COUNT; i++) {
        printProduct(&products[i]);
    }
    printf("==========================================================================================\n");

    printf("\n--- Результат обработки (Товары, годные на текущую дату) ---\n");
    int found = 0;
    for (int i = 0; i < COUNT; i++) {
        if (isValid(products[i].expiryDate, today)) {
            printf("Товар: %-20s | Годен до: %02d.%02d.%04d\n",
                products[i].name,
                products[i].expiryDate.day,
                products[i].expiryDate.month,
                products[i].expiryDate.year);
            found = 1;
        }
    }

    if (!found) {
        printf("Нет товаров с действительным сроком годности.\n");
    }
}