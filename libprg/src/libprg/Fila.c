#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
}fila_t;


// criar_fila

fila_t* criar_fila(int capacidade) {

    fila_t* f = malloc(sizeof(fila_t));

    f->elementos = malloc(capacidade * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade= capacidade;

    return f;
}

// enfileirar

    int enfilerar(fila_t* fila, int valor) {

    if (cheia(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim++;
    fila->tamanho++;

    return 0;
}

// desenfileirar
// inicio
// fim
// tamanha
// vazia

// cheia

bool cheia(fila_t* fila) {

    return fila->tamanho>=fila->capacidade;
}
// destruir_fila