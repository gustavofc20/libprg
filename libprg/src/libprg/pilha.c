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
pilha_t* empilhar(pilha_t* p, int valor) {

    p->topo++;
    p->elementos[p->topo] = valor;

    return 0;
}
//desempilhar
pilha_t* desempilhar(pilha_t* p) {

    p->elementos[p->topo];
    p->topo--;

    return 0;
}
//tamanho
pilha_t* tamanho(pilha_t* p) {

    p->topo++;

    return p;
}
//vazia
//destruir