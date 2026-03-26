#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct fila {

    int inicio;
    int fim;
    int tamanho;
    int* elementos;
    int capacidade;

} fila_t;


//vazia
int fila_vazio(fila_t* fila) {
    if (fila->fim == fila->tamanho) {
        return 1;
    }
    return 0;
}
//cheia
int fila_cheia(fila_t* fila) {
    if (fila->capacidade == fila->tamanho) {
        return 1;
    }
    return 0;
}

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

//enfileirar


void enfileira(fila_t* fila, int valor) {

    if (fila_cheia(fila)) {
        return;
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->tamanho;
    fila->tamanho++;
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


//fim

//destruir
