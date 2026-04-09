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

int pilha_cheia(pilha_t *pilha) {
    if (pilha->topo >= pilha->capacidade - 1)
        return 1;
    return 0;
}

int pilha_vazia(pilha_t *pilha) {
    if (pilha->topo < 0)
        return 1;
    return 0;
}

void pilha_libera(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}

int empilhar(pilha_t* pilha, int valor) {
    if (pilha_cheia(pilha) == 1) {
        pilha->capacidade *= 2;
        pilha->elementos = realloc(pilha->elementos,pilha->capacidade * sizeof(int));

        if (pilha->elementos == NULL)
            return -1;
    }
    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;

    return 0;
}

int desempilhar(pilha_t *pilha) {
    if (pilha_vazia(pilha) == 1)
        return -1;

    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;

    return valor;
}

int topo_pilha(pilha_t *pilha) {
    return pilha->topo;
}

int tamanho_pilha(pilha_t *pilha) {
    return pilha->topo+1;
}

int valor_indice_pilha(pilha_t *pilha, int indice) {
    if (indice > pilha->topo)
        return -1;
    return pilha->elementos[indice];
}