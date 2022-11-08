#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>


// Veridica si existe el año en el arreglo
int findAnio(int* tAios, int year);

//cuenta la cantidad de años que hay en el archivo
int contarTotalonly(FILE *file, int year);


