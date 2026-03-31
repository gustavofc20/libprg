#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

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

//--------fila--------//

typedef struct fila fila_t;

fila_t* fila_cria(int capacidade);

int fila_vazio(fila_t* fila);
int fila_cheia(fila_t* fila);

void enfileira(fila_t* fila, int valor);
int desenfileira(fila_t* fila);
int fila_inicio(fila_t* fila);
int fila_fim(fila_t* fila);
int fila_tamanho(fila_t* fila);
void fila_destruir(fila_t* fila);

#endif
