#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct pilha {

    int topo;
    int* elementos;
    int capacidade;

}Pilha_t;

Pilha_t* pilha_cria(int capacidade) {

    Pilha_t* pilha = malloc(sizeof(Pilha_t));

    pilha->elementos = (int*) malloc(capacidade * sizeof(int));
    pilha->capacidade = capacidade;
    pilha->topo = -1;

    return pilha;
}

void pilha_libera(Pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}

int empilhar(Pilha_t* pilha, int valor) {

    if (pilha->topo == pilha->capacidade - 1) {
        return -1;
    }

    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;

    return pilha->elementos[pilha->topo - 1];
}

void pilha_imprime(Pilha_t* pilha) {

}