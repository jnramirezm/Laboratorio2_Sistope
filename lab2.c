#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#define WRITE 1
#define READ 0

// ./lab2 -i datos_juegos_1000.csv -o salita.txt -d 2008 -p 0.0 -n 100
// ./lab2 -i datos_juegos_1000.csv -o salita.txt -d 2008 -p 0.0 -n 100 -b

// tomar en cuenta que para la ejecucion del programa
// el archivo .cvs debe estar sin fallas (funciona con las "," mal puestas pero no es la idea XD)
// estas fallas son las "," mal puestas.

int main(int argc, char *argv[]) {
  // Se definen las variables a utilizar
  int option;
  char *inputFile = NULL , *outputFile = NULL, *year = "0", *price = "0", *b = "0", *workers = "0";
  
  //PUNTO 1 --------------------------------------------------------------------
  while ((option = getopt(argc, argv, "i:o:d:p:n:b")) != -1) {
    switch (option) {
      case 'i':  // nombre del archivo de entrada
        inputFile = optarg;
        break;
      case 'o':  // nombre del archivo de salida
        outputFile = optarg;
        break;
      case 'd':  // año del juego
        year = optarg;
        break;
      case 'p':  // precio minimo del juego
        price = optarg;
        break;
      case 'n':  // bandera para imprimir en pantalla
        workers = optarg;
        break;
      case 'b':  // bandera | flag | opcional
        b = "1";
        break;
      case '?':
        exit(0);
      default:  // En caso que no se haya ingresado alguna flag obligatoria, se
                // aborta la ejecucion
        abort();
    }
  }
  
  // Validaciones / Lectura del archivo
  FILE *file = fopen(inputFile, "r");
  if (file == NULL) {
    printf("Error al abrir el archivo de entrada \n");return 0;}
  fclose(file);
  
  execl("broker", "broker", inputFile, outputFile, year, price, workers, b, NULL);
  return 0;
}