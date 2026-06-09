#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

//--------PILHA--------//

typedef struct pilha pilha_t;

pilha_t* pilha_cria(int capacidade);
void pilha_libera(pilha_t* pilha);

int pilha_cheia(pilha_t *pilha);
int pilha_vazia(pilha_t *pilha);

int empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t *pilha);
int topo_pilha(pilha_t *pilha);
int tamanho_pilha(pilha_t *pilha);
int valor_indice_pilha(pilha_t *pilha, int indice);

//--------fila--------//

typedef struct fila fila_t;

fila_t* fila_cria(int capacidade);

int fila_vazia(fila_t* fila);
int fila_cheia(fila_t* fila);

int enfileira(fila_t* fila, int valor);
int desenfileira(fila_t* fila);
int fila_inicio(fila_t* fila);
int fila_fim(fila_t* fila);
int fila_busca(fila_t* fila, int posicao);
int fila_tamanho(fila_t* fila);
void fila_destruir(fila_t* fila);

//--------Lista_Linear--------//

typedef struct lista lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, int ordenada);

int lista_linear_cheia(lista_linear_t *lista);
int lista_linear_vazia(lista_linear_t *lista);
int buscar_lista_linear(lista_linear_t *lista, int elemento);
int inserir_lista_linear(lista_linear_t *lista, int elemento);
int remover_lista_linear(lista_linear_t *lista, int valor);

//--------Lista_Encadeada--------//

typedef struct no no_t;

no_t *criar_lista_encadeada(int valor);
void inserir_encadeada(no_t **inicio, int valor);
int remover_encadeada(no_t **inicio, int valor);
no_t *buscar_encadeada(no_t **inicio, int valor);
void destruir_encadeada(no_t **inicio);

//--------Lista_Encadeada_dupla--------//

typedef struct nod nod_t;

nod_t *criar_lista_encadeada_dupla(int valor);
void inserir_encadeada_dupla(nod_t **inicio, int valor);
nod_t *buscar_encadeada_dupla(nod_t **inicio, int valor);
int remover_encadeada_dupla(nod_t **inicio, int valor);
void destruir_encadeada_dupla(nod_t **inicio);

//--------TABELA DE DISPERSÃO--------//
typedef struct noh noh_t;
typedef struct dicionario dicionario_t;

dicionario_t *criar_dicionario(int m);
int inserir_hash(dicionario_t *dicionario, char *chave, int valor);

#endif