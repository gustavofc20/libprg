#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct  lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    int ordenada;
}lista_linear_t;

void inserir_nao_ordenada(lista_linear_t* lista, int valor);
int lista_buscar_ordenada(lista_linear_t* lista, int valor);
void inserir_ordenada(lista_linear_t* lista, int valor);
int lista_buscar_nao_ordenada(lista_linear_t* lista, int valor);

// criar

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada) {

    lista_linear_t* lista = malloc(sizeof(lista_linear_t));

    lista->elementos = malloc(capacidade * sizeof(int));
    lista->tamanho = 0;
    lista->capacidade= capacidade;
    lista->ordenada = ordenada;

    return lista;
}

// inserir

int lista_inserir(lista_linear_t* lista, int valor) {

    if (lista_cheia(lista)) {
        exit(EXIT_FAILURE);
    }


    if (lista->ordenada) {
        inserir_ordenada(lista, valor);
    }
    else {
        inserir_nao_ordenada(lista, valor);
    }

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

    if (lista->ordenada) {

        int indicie = lista_buscar_ordenada(lista, valor);

        for (int i = indicie; i < lista->tamanho-1; i++) {

        lista->elementos[i]=lista->elementos[i+1];

        }
        lista->tamanho--;
    }
    else {

        lista->elementos[lista_buscar(lista, valor)] = lista->elementos[lista->tamanho-1];
        lista->tamanho--;
    }

    return 0;
}

// buscar
int lista_buscar(lista_linear_t* lista, int valor) {

    if (lista->ordenada) {
        return lista_buscar_nao_ordenada(lista, valor);
    }
    return lista_buscar_ordenada(lista, valor);
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

/*--- LISTA LINEAR ---*/

void inserir_nao_ordenada(lista_linear_t* lista, int valor) {

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;

}

int lista_buscar_nao_ordenada(lista_linear_t* lista, int valor) {

    int indice = 0;

    while (indice < lista->tamanho) {

        if (lista->elementos[indice] == valor) {
            return indice;
        }

        indice++;
    }

    return -1;
}

/*--- LISTA ORDENADA ---*/

void inserir_ordenada(lista_linear_t* lista, int valor) {

    for (int i = lista->tamanho - 1; i>+0; --i) {
        if (lista->elementos[i] < valor) {
            lista->elementos[i+1] = valor;
            break;
        }
        lista->elementos[i+1] = lista->elementos[i];
    }
    lista->tamanho++;
}

int lista_buscar_ordenada(lista_linear_t* lista, int valor) {

    int inicio = 0;
    int final = lista->tamanho-1;

    while (inicio<=final) {

        int meio = (inicio+final)/2;

        if (lista->elementos[meio] == valor) {
            return meio;
        }

        if (lista->elementos[meio] < valor) {

            inicio = meio +1;
        }

        if (lista->elementos[meio] > valor) {

            final = meio - 1;
        }
    }

    return -1;
}