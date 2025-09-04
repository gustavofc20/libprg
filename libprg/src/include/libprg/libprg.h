#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

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

#endif
