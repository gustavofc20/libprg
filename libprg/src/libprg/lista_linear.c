#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista_linear{

    int tamanho;
    int* elementos;
    int capacidade;
    bool ordenado;

} lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, int ordenada) {
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));

    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->ordenado = ordenada;

    return lista;
}

int inserir_lista_linear(lista_linear_t* lista, int valor) {

    if (cheia_lista_linear(lista)) {
        lista->capacidade *= 2;
        lista->elementos = realloc(lista->elementos,lista->capacidade * sizeof(int));

    }

    if (lista->ordenado) {
        inserir_lista_linear_ordenado(lista, valor);
    }else {
        inserir_lista_linear_nao_ordenado(lista, valor);
    }

}

int inserir_lista_linear_ordenado(lista_linear_t* lista, int valor) {

    int i;

    for (i = lista->tamanho-1; i >= 0 && lista->elementos[i] > valor; --i) {

        lista->elementos[i+1] = lista->elementos[i];

    }

    lista->elementos[i+1] = valor;
    lista->tamanho++;

    return 0;
}

int inserir_lista_linear_nao_ordenado(lista_linear_t* lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;

    return 0;
}

bool lista_vazia(lista_linear_t* lista) {

    return lista->tamanho<=0;
}

bool cheia_lista_linear(lista_linear_t* lista) {

    return lista->tamanho>=lista->capacidade;
}

