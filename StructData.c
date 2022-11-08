#include "StructData.h"

/*
* Constructor del struct
* parametros: 
* retorna:
*/
StructData *inicializarStructData()
{
    StructData *data = malloc(sizeof(StructData));
    data->Anio = 0;
    data->priceExpensiveGame = 0;
    data->priceCheapGame = 9999;
    data->totalGames = 0;
    data->totalPrice = 0;
    data->cantFreeGames = 0;
    data->win = 0;
    data->lin = 0;
    data->mac = 0;
    return data;
}

/*
* Struct a string (arreglo de char)
* parametros: (struct) struct de 1 año en especifico
* retorna: (arreglo de char) string con la informacion del struct
*/
char *struckToChar(StructData *structYear){ 
    char *str = malloc(sizeof(char)*1000); 
    float prom = structYear->totalPrice/structYear->totalGames; 
    float porcWin = (structYear->win*100)/structYear->totalGames;
    float porcLin = (structYear->lin*100)/structYear->totalGames;
    float porcMac = (structYear->mac*100)/structYear->totalGames;

    char *freeGames = malloc(sizeof(char)*4000);
    if(structYear->cantFreeGames > 0){
        for(int i = 0; i < structYear->cantFreeGames; i++){
            strcat(freeGames, structYear->freeGames[i]);
            strcat(freeGames, "\n");
        }
    }else{
        strcpy(freeGames, "No free games\n");
    }

    sprintf(str, "Año %d:\nJuego mas caro: %s %.2f\nJuego mas barato: %s %.2f\nPromedio de precios: %.2f\nWindows: %.2f%% Linux: %.2f%% Mac: %.2f%%\nFree Games:\n%s\n", structYear->Anio, 
    structYear->expensiveGame, structYear->priceExpensiveGame, structYear->cheapGame, structYear->priceCheapGame, prom, porcWin, porcLin, porcMac, freeGames); 
    return str;
}