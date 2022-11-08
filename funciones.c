#include "funciones.h"

/*
* Verifica si el año existe en el arreglo de años
* parametros: (int) año, (int*) arreglo de años
* retorna: 0 si no existe, 1 si existe
*/
int findAnio(int* tAios, int year){
  int i = 0;
  while(i < 100){
    if(tAios[i] == year){
      return 1;
    }
    i++;
  }
  return 0;
}

/*
* cuenta la cantidad de años que hay en el archivo
* parametros: file archivo, int año
* retorna: int cantidad de años
*/
int contarTotalonly(FILE *file, int year){
  char linea[1000];
  int tAnios[100];
  char *token;
  int i=0;
  while(fgets(linea, 1000, file) != NULL){
    token = strtok(linea, ",");
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    if(atoi(token) >= year && findAnio(tAnios, atoi(token)) == 0){
      tAnios[i] = atoi(token);
      i++;
    }
  }return i-1;}

