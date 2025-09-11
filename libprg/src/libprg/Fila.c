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

    if (fila_cheia(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;

    return 0;
}

// desenfileirar

    int desenfilerar(fila_t* fila)
{
    if (fila_vazia(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->tamanho--;
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    int valor = fila->elementos[fila->inicio];

    return valor;
}
// inicio
    int fila_inicio(fila_t* fila){

    return fila->elementos[fila->inicio];
}
// fim

    int fila_fim(fila_t* fila){

    return fila->elementos[fila->fim];
}
// tamanha
    int fila_tamanho(fila_t* fila){

    return fila->tamanho;
}
// vazia
    bool fila_vazia(fila_t* fila){

        return fila->tamanho<=0;
    }
// cheia

    bool fila_cheia(fila_t* fila) {

    return fila->tamanho>=fila->capacidade;
}
// destruir_fila

    int fila_destruir(pilha_t* fila){

    free(fila->elementos);
    free(fila);

    return 0;
}

// tamanha df
int fila_tamanho_df(fila_t* fila){

    int tamanho2;

    int in = fila->inicio;
    int fi = fila->fim;

    if (in<fi){

        tamanho2 = fi - in;

    }
    if (in>fi){

        tamanho2 = fila->capacidade-in+fi;

    }
    if (in==fi){

    }

    return tamanho2;
}