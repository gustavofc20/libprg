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
int enfilerar(fila_t* fila, int valor);
int desenfilerar(fila_t* fila);
int fila_inicio(fila_t* fila);
int fila_fim(fila_t* fila);
int fila_tamanho(fila_t* fila);
bool fila_cheia(fila_t* fila);
bool fila_vazia(fila_t* fila);
int fila_destruir(pilha_t* p);

#endif
