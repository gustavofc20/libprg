#include <stdio.h>
#include <stdlib.h>

typedef struct  pilha {
    int* elementos;
    int topo;
    int capacidade;
}pilha_t;

pilha_t* criar_pilha(int cap) {

    pilha_t* p = malloc(sizeof(pilha_t));

    p->elementos = malloc(cap*sizeof(int));
    p->topo = -1;
    p->capacidade = cap;

    return p;
}
//empilhar
int empilhar(pilha_t* p, int valor) {

    p->topo++;
    p->elementos[p->topo] = valor;

    return 0;
}
//desempilhar
int desempilhar(pilha_t* p) {

    p->elementos[p->topo];
    p->topo--;

    return 0;
}
//tamanho
int tamanho(pilha_t* p) {
    return p->topo+1;
}
//vazia
int vazia(pilha_t* p) {
    p->topo = -1;

    return 0;
}
//destruir
int destruir(pilha_t* p) {
    free(p->elementos);
    free(p);

    return 0;
}