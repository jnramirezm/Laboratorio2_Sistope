#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include "StructData.h"
#include "fworker.h"

#define READ 0
#define WRITE 1

int main(int argc, char *argv[]) {
    float priceConsole = atof(argv[1]);
    char buffer[500];
    int lineasWorker = 0;
    StructData structYear;
    while(1){
        read(STDIN_FILENO, buffer, sizeof(char)*500);
        if(strcmp(buffer, "Exit") == 0){
            break;
        }
        read(STDIN_FILENO, &structYear, sizeof(StructData));

        actualizarStruct(&structYear, buffer, priceConsole);
        lineasWorker++;
        
        write(STDOUT_FILENO, &structYear , sizeof(StructData));
    }
    // escribimos las lineas del worker
    write(STDOUT_FILENO, &lineasWorker, sizeof(int));
    
    return 0;
}