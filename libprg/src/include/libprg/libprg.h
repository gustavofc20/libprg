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
int buscar_hash(dicionario_t *dicionario, char *chave);
int remover_hash(dicionario_t *dicionario, char *chave);
void imprimir_hash(dicionario_t *dicionario);
void destruir_hash(dicionario_t *dicionario);


//-------- ALGORITMOS DE ORDENAÇÃO --------//

int *bubble_sort(int *vetor, int tamanho);
int *insertion_sort(int *vetor, int tamanho);
int *selection_sort(int *vetor, int tamanho);
int *merge_sort(int *vetor, int esquerda, int direita);
int *quick_sort(int *vetor, int inicio, int fim);

//-------- ÁRVORE --------//
typedef struct noa noa_t;

noa_t *criar_noa(int dado);
noa_t *adicionar_noa(noa_t *raiz, int dado);
noa_t* remover_noa(noa_t *raiz, int dado);
void travessia_emordem(noa_t *raiz);
void travessia_preordem(noa_t *raiz);
void travessia_posordem(noa_t *raiz);
void destruir_noa(noa_t *raiz);
int maior_valor_noa(noa_t *raiz);
int menor_valor_noa(noa_t *raiz);
int altura_noa(noa_t *raiz);


//-------- ÁRVORE AVL --------//
typedef struct noavl noavl_t;

noavl_t *criar_noavl(int dado);
int altura_avl(noavl_t *raiz);
int fator_balanceamento(noavl_t *raiz);
noavl_t *adicionar_noavl(noavl_t *raiz, int dado);
noavl_t* remover_noavl(noavl_t *raiz, int dado);
noavl_t* rotacao_esquerda(noavl_t* raiz);
noavl_t* rotacao_direita(noavl_t* raiz);
noavl_t* rotacao_dupla_direita(noavl_t *raiz);
noavl_t* rotacao_dupla_esquerda(noavl_t *raiz);
noavl_t* balancear_avl(noavl_t* raiz);
void travessia_emordem_avl(noavl_t* raiz);
void travessia_preordem_avl(noavl_t* raiz);
void travessia_posordem_avl(noavl_t* raiz);
void imprimir_nivel_avl(noavl_t *raiz, int nivel);
void travessia_largura_avl(noavl_t *raiz);
void destruir_noavl(noavl_t *raiz);


#endif