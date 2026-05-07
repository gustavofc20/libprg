#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct nod {
    int dado;
    nod_t *anterior;
    nod_t *proximo;
} nod_t;

nod_t *criar_lista_encadeada_dupla(int valor) {
    nod_t *no = malloc(sizeof(nod_t));
    no->dado = valor;
    no->anterior = NULL;
    no->proximo = NULL;

    return no;
}

void inserir_encadeada_dupla(nod_t **inicio, int valor) {
    nod_t *novo_no = criar_lista_encadeada_dupla(valor);
    novo_no->proximo = *inicio;
    (*inicio)->anterior = novo_no;
    *inicio = novo_no;
}

nod_t *buscar_encadeada_dupla(nod_t **inicio, int valor) {
    nod_t *atual = *inicio;

    while (atual != NULL) {
        if (atual->dado == valor)
            return atual;

        atual = atual->proximo;
    }
    return NULL;
}

int remover_encadeada_dupla(nod_t **inicio, int valor) {
    nod_t *atual = buscar_encadeada_dupla(inicio, valor);

    if (atual != NULL) {
        if (atual->anterior != NULL) // Se não é o primeiro nó
            atual->anterior->proximo = atual->proximo;
        else
            *inicio = atual->proximo; // remove o primeiro

        if (atual->proximo != NULL) // Se não é o último nó
            atual->proximo->anterior = atual->anterior;

        free(atual);

        return 1;
    }
    return 0;
}

void destruir_encadeada_dupla(nod_t **inicio) {
    nod_t *atual = *inicio;

    while (atual != NULL) {
        nod_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}