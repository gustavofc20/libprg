#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

#define max(a, b) (a > b ? a : b)

typedef struct noavl {
    int dado;
    noavl_t *esquerda;
    noavl_t *direita;
    int altura;
} noavl_t;

noavl_t *criar_noavl(int dado) {
    noavl_t *no = malloc(sizeof(noavl_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1;

    return no;
}

int altura_avl(noavl_t *raiz) {
    if (raiz == NULL)
        return 0;
    return raiz->altura;
}

int fator_balanceamento(noavl_t *raiz) {
    if (raiz == NULL)
        return 0;
    return altura_avl(raiz->esquerda) - altura_avl(raiz->direita);
}

noavl_t *adicionar_noavl(noavl_t *raiz, int dado) {
    if (raiz == NULL)
        return criar_noavl(dado);

    if (dado > raiz->dado)
        raiz->direita = adicionar_noavl(raiz->direita, dado);

    if (dado < raiz->dado)
        raiz->esquerda = adicionar_noavl(raiz->esquerda, dado);

    raiz->altura = 1 + max(altura_avl(raiz->esquerda), altura_avl(raiz->direita));
    raiz = balancear_avl(raiz);

    return raiz;
}

noavl_t* remover_noavl(noavl_t *raiz, int dado) {
    if (raiz == NULL)
        return NULL;

    if (dado < raiz->dado)
        raiz->esquerda = remover_noavl(raiz->esquerda, dado);
    else if (dado > raiz->dado)
        raiz->direita = remover_noavl(raiz->direita, dado);
    else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            noavl_t *temp = raiz->esquerda != NULL ? raiz->esquerda : raiz->direita; // testa se na esq. tem filho, se tiver, pega ele. Caso não, pega o da direita
            if (temp == NULL){
                free(raiz);
                return NULL;
            }
            free(raiz);
            return temp;
        }   // 2 filhos
        // Encontra o menor valor da subárvore da direita
        noavl_t *temp = raiz->direita;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        raiz->dado = temp->dado;
        raiz->direita = remover_noavl(raiz->direita, temp->dado);
    }
    if (raiz != NULL) {
        raiz->altura = 1 + max(altura_avl(raiz->esquerda), altura_avl(raiz->direita));
        raiz = balancear_avl(raiz);
    }
    return raiz;
}

noavl_t* rotacao_esquerda(noavl_t* raiz) {
    noavl_t* filho_direita = raiz->direita;
    noavl_t* neto_esquerda = filho_direita->esquerda;

    // rotaciona
    filho_direita->esquerda = raiz;
    raiz->direita = neto_esquerda;

    // atualiza alturas
    raiz->altura = 1 + max(altura_avl(raiz->esquerda), altura_avl(raiz->direita));
    filho_direita->altura = 1 + max(altura_avl(filho_direita->esquerda), altura_avl(filho_direita->direita));

    // retorna nova raiz
    return filho_direita;
}

noavl_t* rotacao_direita(noavl_t* raiz) {
    noavl_t* filho_direita = raiz->esquerda;
    noavl_t* neto_esquerda = filho_direita->direita;

    // rotaciona
    filho_direita->direita = raiz;
    raiz->esquerda = neto_esquerda;

    // atualiza alturas
    raiz->altura = 1 + max(altura_avl(raiz->esquerda), altura_avl(raiz->direita));
    filho_direita->altura = 1 + max(altura_avl(filho_direita->esquerda), altura_avl(filho_direita->direita));

    // retorna nova raiz
    return filho_direita;
}

noavl_t* rotacao_dupla_direita(noavl_t *raiz) {
    // rotação simples à esquerda no filho esquerdo da raiz
    raiz->esquerda = rotacao_esquerda(raiz->esquerda);

    // rotação simples à direita da raiz
    return rotacao_direita(raiz);
}

noavl_t* rotacao_dupla_esquerda(noavl_t *raiz) {
    raiz->direita = rotacao_direita(raiz->direita);

    return rotacao_esquerda(raiz);
}

noavl_t* balancear_avl(noavl_t* raiz) {
    int fb = fator_balanceamento(raiz);

    if (fb > 1) {
        if (fator_balanceamento(raiz->esquerda) > 0)
            return rotacao_direita(raiz);

        return rotacao_dupla_direita(raiz);
    }
    if (fb < -1) {
        if (fator_balanceamento(raiz->direita) < 0)
            return rotacao_esquerda(raiz);

        return rotacao_dupla_esquerda(raiz);
    }
    return raiz;
}

void travessia_emordem_avl(noavl_t* raiz) {
    if (raiz != NULL) {
        travessia_emordem_avl(raiz->esquerda);
        printf("%d ", raiz->dado);
        travessia_emordem_avl(raiz->direita);
    }
}

void travessia_preordem_avl(noavl_t* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        travessia_preordem_avl(raiz->esquerda);
        travessia_preordem_avl(raiz->direita);
    }
}

void travessia_posordem_avl(noavl_t* raiz) {
    if (raiz != NULL) {
        travessia_posordem_avl(raiz->esquerda);
        travessia_posordem_avl(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

void imprimir_nivel_avl(noavl_t *raiz, int nivel) {
    if (raiz == NULL)
        return;

    if (nivel == 0) {
        printf("%d ", raiz->dado);
        return;
    }

    imprimir_nivel_avl(raiz->esquerda, nivel - 1);
    imprimir_nivel_avl(raiz->direita, nivel - 1);
}

void travessia_largura_avl(noavl_t *raiz) {
    int altura = altura_avl(raiz);

    for (int i = 0; i <= altura; i++)
        imprimir_nivel_avl(raiz, i);
}

void destruir_noavl(noavl_t *raiz) {
    if (raiz != NULL) {
        destruir_noavl(raiz->esquerda);
        destruir_noavl(raiz->direita);
        free(raiz);
    }
}