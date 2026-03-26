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

#endif
