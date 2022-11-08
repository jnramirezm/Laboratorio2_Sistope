#include "fworker.h"

/*
* Actulizan el struct
* parametros: (struct) struct de 1 año en especifico, (arreglo de char) linea, (float) precio minimo
* retorna: VOID
*/
void actualizarStruct(StructData *structYear, char* buffer, float minimumPrice){
    char *token;
    int year;
    char nombre[100], auxname[100];
    float precio;
    char win[4],mac[4],lin[4];
    float freeGamesPrice = 0;
    token = strtok(buffer, ",");
    token = strtok(NULL, ",");strcpy(nombre,token);
    strcpy(auxname, nombre);
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");precio = atof(token);
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");year = atoi(token);
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");strcpy(win,token);
    token = strtok(NULL, ",");strcpy(mac,token);
    token = strtok(NULL, ",");strcpy(lin,token);
    strcpy(nombre, auxname);
    if(year == structYear->Anio){
        if(precio > minimumPrice){
            if(precio > structYear->priceExpensiveGame){
                structYear->priceExpensiveGame = precio;
                strcpy(structYear->expensiveGame, nombre);
            }
            if(precio < structYear->priceCheapGame && precio != freeGamesPrice){
                structYear->priceCheapGame = precio;
                strcpy(structYear->cheapGame, nombre);
                
            }
        }
        if(freeGamesPrice == precio){
            strcpy(structYear->freeGames[structYear->cantFreeGames], nombre);
            structYear->cantFreeGames++;
        }
        structYear->totalGames++;
        structYear->totalPrice += precio;
        if(strcmp(win, "Yes") == 0){
            structYear->win++;
        }
        if(strcmp(mac, "Yes") == 0){
            structYear->mac++;
        }
        if(strcmp(lin, "Yes") == 0){
            structYear->lin++;
        }
    }
}