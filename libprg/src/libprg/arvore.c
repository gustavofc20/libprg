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
        travessia_posordem(raiz->esquerda);
        travessia_posordem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

void destruir_noa(noa_t *raiz) {
    if (raiz != NULL) {
        destruir_noa(raiz->esquerda);
        destruir_noa(raiz->direita);
        free(raiz);
    }
}

int maior_valor_noa(noa_t *raiz) {
    noa_t *atual = raiz;

    while (atual->direita != NULL)
        atual = atual->direita;

    return atual->dado;
}

int menor_valor_noa(noa_t *raiz) {
    noa_t *atual = raiz;

    while (atual->esquerda != NULL)
        atual = atual->esquerda;

    return atual->dado;
}

int altura_noa(noa_t *raiz) {
    if (raiz == NULL)
        return -1;

    int altura_esquerda = altura_noa(raiz->esquerda);
    int altura_direita = altura_noa(raiz->direita);

    if (altura_esquerda > altura_direita)
        return 1 + altura_esquerda;

    return 1 + altura_direita;
}