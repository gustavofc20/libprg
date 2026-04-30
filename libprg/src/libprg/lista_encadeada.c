#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int dado;
    no_t *proximo;
} no_t;

no_t *criar_lista_encadeada(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->dado = valor;
    no->proximo = NULL;

    return no;
}

void inserir_encadeada(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

// buscar

no_t* buscar_no_encadeada(no_t **inicio, int valor) {

    no_t *atual = *inicio;

    while(atual != NULL) {
        if(atual->dado == valor) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

// remover

int remover_encadeada(no_t **inicio, int valor) {

    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while(atual != NULL) {
        if(atual->dado == valor) {
            if (anterior == NULL) {
                *inicio = atual->proximo;
            }else {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            return 0;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return -1;
}


// destruir

void destruir_encadeada(no_t **inicio) {

    no_t *atual = *inicio;
    no_t *proximo = NULL;

    while(atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}
