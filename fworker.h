#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include "StructData.h"

// Actuliza el struct de un año en especifico
void actualizarStruct(StructData *structYear, char* buffer, float minimumPrice);