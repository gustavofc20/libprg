#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct fila {

    int inicio;
    int fim;
    int tamanho;
    int* elementos;
    int capacidade;

} fila_t;


//criar

fila_t* fila_cria(int capacidade) {

    fila_t* fila = malloc(sizeof(fila_t));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->elementos = malloc(capacidade * sizeof(int));
    fila->capacidade = capacidade;

    return fila;
}

//vazia
int fila_vazio(fila_t* fila) {
    if (fila->fim == fila->tamanho) {
        return 1;
    }
    return 0;
}
//cheia
int fila_cheia(fila_t* fila) {
    if (fila->tamanho >= fila->capacidade) {
        return 1;
    }
    return 0;
}

//enfileirar


int enfileira(fila_t* fila, int valor) {

    if (fila_cheia(fila)) {
        return -1;
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;

    return 0;
}

//desenfileirar

int desenfileira(fila_t* fila) {
    if (fila_cheia(fila)) {
        return -1;
    }
    int elemento = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio+ 1) % fila->tamanho;
    fila->tamanho--;

    return elemento;
}
//inicio
int fila_inicio(fila_t* fila) {
    return fila->inicio;
}

//fim
int fila_fim(fila_t* fila) {
    return fila->fim;
}

//tamanho
int fila_tamanho(fila_t* fila) {
    return fila->tamanho;
}

//destruir
void fila_destruir(fila_t* fila) {

    free(fila->elementos);
    free(fila);
}


