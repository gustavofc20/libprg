#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct no_b {
    int valor;
    struct  no_b* esquerda;
    struct  no_b* direita;
}no_b_t;

no_b_t *criar_no(int valor) {
    no_t *no = (no_t *) malloc(sizeof(no_t));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

no_b_t *destruir_valor(no_t *no) {
    if (no != NULL) {
        destruir_valor(no->esquerda);
        destruir_valor(no->direita);
        free(no);
    }
}

no_b_t *inserir_valor(no_t *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}
bool busca(no_t *raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);

}

no_b_t *remover_valor(no_t *raiz, int valor){
    if (raiz == NULL) return raiz;
    if (valor < raiz->valor) {
        raiz->esquerda =  remover_valor(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita =  remover_valor(raiz->direita, valor);
    } else {

        // IF nó folha ou nó com um filho
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
            }else if (raiz->esquerda == NULL) {
                raiz = raiz->direita;
                free(raiz->direita);
            }else {
                raiz = raiz->esquerda;
                free(raiz->esquerda);
            }


        }else {// ELSE nó com dois filhos

        }

    }
    return raiz;
}

