#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int valor;
    struct no* proximo;
} no_t;

//criar

no_t* lista_encadeada_criar(int valor) {

    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

//criar

no_t* lista_encadeada_circular_criar(int valor) {

    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = no;

    return no;
}

//adicinar

void adicionar_no(no_t** inicio, int valor) {
    no_t* novo_no = lista_encadeada_criar(valor);

    if (*inicio == NULL) {
        *inicio = novo_no;
    } else {
        no_t* atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
}

//adicinar_circular
void adicionar_circular(no_t** inicio, int valor) {
    no_t* novo_no = lista_encadeada_criar(valor);
    if (*inicio == NULL) {
        novo_no->proximo = novo_no;
        *inicio = novo_no;
    } else {
        no_t* atual = *inicio;
        while (atual->proximo != *inicio) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
        novo_no->proximo = *inicio;
    }
}

//buscar

no_t* lista_encadeada_buscar(no_t** inicio, int valor) {

    no_t* atual = *inicio;

    while (atual) {

        if (atual->valor==valor) {
            return *inicio;
        }

        atual = atual->proximo;

    }


    return NULL;
}
//remover

void lista_encadeada_remover(no_t** inicio, int valor) {

    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual) {
        if (atual->valor == valor) {
            if (anterior) {
                anterior->proximo=atual->proximo;
            }
            else {
                *inicio = atual->proximo;
            }
            free(atual);
            break;
        }

        anterior = atual;
        atual = atual->proximo;
    }
}



//tamanho
int lista_encadeada_tamanho(no_t* inicio) {
    int tamanho = 0;
    no_t* atual = inicio;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

//apontar

int apontar_elemento_lista_encadeada(no_t** inicio, int indice) {
    no_t* atual = *inicio;

    for (int i = 0; i < indice && atual != NULL; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return -1; // índice fora da lista
    }

    return atual->valor;
}

// Destruir lista
int lista_encadeada_destruir(no_t** inicio) {
    no_t* atual = *inicio;
    while (atual != NULL) {
        no_t* prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
    return 0;
}

// Destruir lista circular
int lista_encadeada_circular_destruir(no_t** inicio) {
    if (*inicio == NULL) return 0;

    no_t* atual = (*inicio)->proximo;
    while (atual != *inicio) {
        no_t* prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    free(*inicio);
    *inicio = NULL;
    return 0;
}