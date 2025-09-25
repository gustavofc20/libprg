#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>


/*--- PILHA ---*/

typedef struct  pilha {
    int* elementos;
    int topo;
    int capacidade;
}pilha_t;

pilha_t* criar_pilha(int cap);
int empilhar(pilha_t* p, int valor);
int desempilhar(pilha_t* p);
int tamanho(pilha_t* p);
int vazia(pilha_t* p);
int destruir(pilha_t* p);

/*--- FILA ---*/

typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
int enfileirar(fila_t* fila, int valor);
int desenfileirar(fila_t* fila);
int fila_inicio(fila_t* fila);
int fila_fim(fila_t* fila);
int fila_tamanho(fila_t* fila);
bool fila_cheia(fila_t* fila);
bool fila_vazia(fila_t* fila);
int fila_destruir(pilha_t* p);

/*--- LISTA LINEAR ---*/

typedef struct  lista_linear lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
int lista_inserir(lista_linear_t* lista, int valor);
int lista_remover(lista_linear_t* lista, int valor);
int lista_buscar(lista_linear_t* lista, int valor);
bool lista_vazia(lista_linear_t* lista);
bool lista_cheia(lista_linear_t* lista);
int lista_destruir(lista_linear_t* lista);
int lista_remover_imprimir(lista_linear_t* lista);
int lista_tamanho(lista_linear_t* lista);
int lista_primeiro_indicie(lista_linear_t* lista);
int lista_aponta_valor(lista_linear_t* lista, int indice);

#endif
