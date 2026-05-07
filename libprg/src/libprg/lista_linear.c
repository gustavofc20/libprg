#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct lista {
    int *elementos;
    int capacidade;
    int tamanho;
    int ordenada;
} lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, int ordenada) {
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));

    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->ordenada = ordenada;

    return lista;
}

int lista_linear_cheia(lista_linear_t *lista) {
    if (lista->tamanho >= lista->capacidade) {
        return 1;
    }
    return 0;
}

int lista_linear_vazia(lista_linear_t *lista) {
    if (lista->tamanho <= 0) {
        return 1;
    }
    return 0;
}

int busca_linear(lista_linear_t *lista, int elemento) {
    for (int i=0; i<lista->tamanho; i++) {
        if (lista->elementos[i] == elemento)
            return i;
    }
    return -1;
}

int busca_binaria(lista_linear_t *lista, int elemento) {
    int inicio = 0;
    int final = lista->tamanho - 1;

    while (inicio <= final) {
        int meio = inicio + (final - inicio) / 2;

        if (elemento == lista->elementos[meio])
            return meio;

        if (elemento > lista->elementos[meio])
            inicio = meio + 1;

        else
            final = meio - 1;
    }
    return -1;
}

int buscar_lista_linear(lista_linear_t *lista, int elemento) {
    if (lista->ordenada == 1)
        return busca_binaria(lista, elemento);

    return busca_linear(lista, elemento);
}

int inserir_nao_ordenada(lista_linear_t *lista, int elemento) {
    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;

    return 0;
}

int inserir_ordenada(lista_linear_t *lista, int elemento) {
    int indice = lista->tamanho;

    for (int i=0; i<lista->tamanho; i++) {
        if (lista->elementos[i] > elemento) {
            indice = i;
            break;
        }
    }
    for (int i=lista->tamanho; i>indice; i--) {
        lista->elementos[i] = lista->elementos[i-1];
    }
    lista->elementos[indice] = elemento;
    lista->tamanho++;

    return 0;
}

int inserir_lista_linear(lista_linear_t *lista, int elemento) {
    if (lista_linear_cheia(lista) == 1)
        return -1;

    if (lista->ordenada == 0)
        return inserir_nao_ordenada(lista, elemento);

    return inserir_ordenada(lista, elemento);
}

int remover_ordenada(lista_linear_t *lista, int indice) {
    for (int i=indice; i<lista->tamanho-1; i++)
        lista->elementos[i] = lista->elementos[i+1];

    lista->tamanho--;
    return 0;
}

int remover_nao_ordenada(lista_linear_t *lista, int indice) {
    lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
    lista->tamanho--;

    return 0;
}

int remover_lista_linear(lista_linear_t *lista, int valor) {
    if (lista_linear_vazia(lista) == 1)
        return -1;

    int indice = buscar_lista_linear(lista, valor);

    if (indice == -1)
        return -2;

    if (lista->ordenada == 1)
        return remover_ordenada(lista, indice);

    return remover_nao_ordenada(lista, indice);
}

// alterar_lista_linear
// ordenar_lista_linear
// combinar_lista_linear
// destruir_lista_linear