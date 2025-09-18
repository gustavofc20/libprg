#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct  lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
}lista_linear_t;

// criar

lista_linear_t* criar_lista_linear(int capacidade) {

    lista_linear_t* lista = malloc(sizeof(lista_linear_t));

    lista->elementos = malloc(capacidade * sizeof(int));
    lista->tamanho = 0;
    lista->capacidade= capacidade;

    return lista;
}

// inserir

int lista_inserir(lista_linear_t* lista, int valor) {

    if (lista_cheia(lista)) {
        exit(EXIT_FAILURE);
    }

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;

    return 0;
}

// remover

int lista_remover(lista_linear_t* lista, int valor) {

    if (lista_vazia(lista)) {
        exit(EXIT_FAILURE);
    }

    if (lista_buscar(lista, valor)==-1) {
        return -1;
    }

    lista->elementos[lista_buscar(lista, valor)] = lista->elementos[lista->tamanho-1];
    lista->tamanho--;

    return 0;
}

// buscar
int lista_buscar(lista_linear_t* lista, int valor) {

    int indice = 0;

    while (indice < lista->tamanho) {

        if (lista->elementos[indice] == valor) {
            return indice;
        }

        indice++;
    }

    return -1;
}
// vazia

bool lista_vazia(lista_linear_t* lista) {

    return lista->tamanho<=0;
}
// cheia

bool lista_cheia(lista_linear_t* lista) {

    return lista->tamanho>=lista->capacidade;
}

// destruir

    int lista_destruir(lista_linear_t* lista){

    free(lista->elementos);
    free(lista);

    return 0;
}

//teste

    int lista_remover_imprimir(lista_linear_t* lista)
{
    if (lista_vazia(lista)) {
        exit(EXIT_FAILURE);
    }

    int valor = lista->elementos[lista->tamanho-1];
    lista->tamanho--;

    return valor;
}

//tamanho

int lista_tamanho(lista_linear_t* lista){

    return lista->tamanho;
}

//primeiro

int lista_primeiro_indicie(lista_linear_t* lista) {

    int valor = lista->elementos[0];

    return valor;
}
