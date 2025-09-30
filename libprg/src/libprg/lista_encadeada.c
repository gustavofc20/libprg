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

//adicinar

void adicionar(no_t** inicio, int valor) {

    no_t* novo_no = lista_encadeada_criar(valor);
    novo_no->proximo = *inicio;
    *inicio=novo_no;
}

//adicinar_circular
void adicionar_circular(no_t** inicio, int valor) {

    no_t* novo_no = lista_encadeada_criar(valor);
    novo_no->proximo=*inicio;

    no_t* ultimo = *inicio;

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

void remover(no_t** inicio, int valor) {

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

//destruir
int lista_encadeada_destruir(no_t** inicio){

    return 0;
}