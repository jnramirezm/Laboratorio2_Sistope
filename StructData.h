#ifndef STRUCTDATA_H
#define STRUCTDATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definicion del structdata
typedef struct 
{
    int Anio;
    char expensiveGame[60];
    float priceExpensiveGame;
    char cheapGame[60];
    float priceCheapGame;
    int totalGames;
    float totalPrice;
    char freeGames[100][60];
    int cantFreeGames;
    int win;
    int lin;
    int mac;
} StructData;

// constructor del struct
StructData *inicializarStructData();

// struct a string
char *struckToChar(StructData *structYear);
#endif