#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <time.h>

// Структура для хранения даты
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[100];      
    Date manufactureDate;
    Date expiryDate;     
    float price;         
    int seriesNumber;   
} Product;

Date getCurrentDate();
int compareDates(Date d1, Date d2);
int isValid(Date expiry, Date current);
void inputProduct(Product* p, int index);
void printProduct(const Product* p);
void runTask();

#endif