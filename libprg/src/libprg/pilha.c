#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct pilha {

    int topo;
    int* elementos;
    int capacidade;

} pilha_t;

pilha_t* pilha_cria(int capacidade) {

    pilha_t* pilha = malloc(sizeof(pilha_t));

    pilha->elementos = malloc(capacidade * sizeof(int));
    pilha->capacidade = capacidade;
    pilha->topo = -1;

    return pilha;
}

void pilha_libera(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}

int empilhar(pilha_t* pilha, int valor) {

    if (pilha->topo == pilha->capacidade - 1) {
        return -1;
    }

    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;

    return pilha->elementos[pilha->topo - 1];
}

void desempilhar(pilha_t* pilha) {
    if (pilha->topo == -1) {
        return;
    }

    pilha->topo--;
}

void pilha_imprime(pilha_t* pilha) {

}