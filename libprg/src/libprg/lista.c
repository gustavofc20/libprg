#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct  lista {
    int* elementos;
    int topo;
    int capacidade;
}lista_t;