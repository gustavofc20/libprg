#include <stdio.h>
#include <stdlib.h>

typedef struct  pilha {
    int* elemnetos;
    int topo;
    int capacidade;
}pilha_t;

pilha_t* criar_pilha(int cap) {

    pilha_t* p = malloc(sizeof(pilha_t));

    p->elemnetos = malloc(cap*sizeof(int));
    p->topo = -1;
    p->capacidade= cap;

    return p;
}
//empilhar
//desempilhar
//tamanho
//vazia
//destruir