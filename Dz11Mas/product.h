#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[100];     
    Date manufacture_Date;
    Date expiry_Date;     
    float price;         
    int series_Number;    
} Product;

void inputProduct(Product* p, int index);
void printProductResult(const Product* p);

#endif