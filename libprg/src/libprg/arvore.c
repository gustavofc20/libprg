#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct noa {
    int dado;
    noa_t *esquerda;
    noa_t *direita;
} noa_t;

noa_t *criar_noa(int dado) {
    noa_t *no = malloc(sizeof(noa_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

noa_t *adicionar_noa(noa_t *raiz, int dado) {
    if (raiz == NULL)
        return criar_noa(dado);

    if (dado > raiz->dado)
        raiz->direita = adicionar_noa(raiz->direita, dado);

    if (dado < raiz->dado)
        raiz->esquerda = adicionar_noa(raiz->esquerda, dado);

    return raiz;
}

noa_t* remover_noa(noa_t *raiz, int dado) {
    if (raiz == NULL)
        return NULL;

    if (dado < raiz->dado)
        raiz->esquerda = remover_noa(raiz->esquerda, dado);
    else if (dado > raiz->dado)
        raiz->direita = remover_noa(raiz->direita, dado);
    else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            noa_t *temp = raiz->esquerda != NULL ? raiz->esquerda : raiz->direita; // testa se na esq. tem filho, se tiver, pega ele. Caso não, pega o da direita
            if (temp == NULL){
                free(raiz);
                return NULL;
            }
            free(raiz);
            return temp;
        }   // 2 filhos
        // Encontra o menor valor da subárvore da direita
        noa_t *temp = raiz->direita;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        raiz->dado = temp->dado;
        raiz->direita = remover_noa(raiz->direita, temp->dado);
    }
    return raiz;
}

void travessia_emordem(noa_t *raiz) {
    if (raiz != NULL) {
        travessia_emordem(raiz->esquerda);
        printf("%d ", raiz->dado);
        travessia_emordem(raiz->direita);
    }
}

void travessia_preordem(noa_t *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        travessia_preordem(raiz->esquerda);
        travessia_preordem(raiz->direita);
    }
}

void travessia_posordem(noa_t *raiz) {
    if (raiz != NULL) {
        travessia_preordem(raiz->esquerda);
        travessia_preordem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

// destruir