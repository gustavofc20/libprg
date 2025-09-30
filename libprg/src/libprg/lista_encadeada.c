#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int valor;
    struct no* proximo;
} no_t;

//criar

no_t* criar_lista_encadeada(int valor) {

    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

//adicinar

no_t* adicionar(no_t* inicio, int valor) {

    no_t* novo_no = criar_lista_encadeada(valor);
    novo_no->proximo=inicio;
    inicio=novo_no;

    return inicio;
}
//remover
//buscar
//destruir