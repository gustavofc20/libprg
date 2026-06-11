#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libprg/libprg.h"

typedef struct noh {
    char *chave;
    int valor;
    noh_t *proximo;
} noh_t;

typedef struct dicionario {
    int tamanho;
    noh_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m) {
    dicionario_t *dicionario;

    if (m < 1)
        return NULL;

    dicionario = malloc(sizeof(dicionario_t));
    dicionario->vetor = calloc(m, sizeof(noh_t*));
    dicionario->tamanho = m;

    return dicionario;
}

int hash(char *chave, int m) {
    int soma = 0;

    for (int i = 0; chave[i] != '\0'; i++)
        soma += (i + 1) * chave[i];

    return soma % m;
}

int inserir_hash(dicionario_t *dicionario, char *chave, int valor) {
    int indice = hash(chave, dicionario->tamanho);
    noh_t *no = malloc(sizeof(noh_t));

    if (no == NULL)
        return -1;

    no->chave = strdup(chave);

    if (no->chave == NULL) {
        free(no);
        return -1;
    }
    no->valor = valor;
    no->proximo = dicionario->vetor[indice];
    dicionario->vetor[indice] = no;

    return 0;
}

int buscar_hash(dicionario_t *dicionario, char *chave) {
    int indice = hash(chave, dicionario->tamanho);

    noh_t *atual = dicionario->vetor[indice];

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0)
            return atual->valor;

        atual = atual->proximo;
    }

    return -1;
}

int remover_hash(dicionario_t *dicionario, char *chave) {
    int indice = hash(chave, dicionario->tamanho);

    noh_t *atual = dicionario->vetor[indice];
    noh_t *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL)
                dicionario->vetor[indice] = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual->chave);
            free(atual);

            return 0;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return -1;
}

void imprimir_hash(dicionario_t *dicionario) {
    for (int i = 0; i < dicionario->tamanho; i++) {
        noh_t *atual = dicionario->vetor[i];

        while (atual != NULL) {
            printf("%s -> %d\n", atual->chave, atual->valor);
            atual = atual->proximo;
        }
    }
}

void destruir_hash(dicionario_t *dicionario) {
    if (dicionario == NULL)
        return;

    for (int i = 0; i < dicionario->tamanho; i++) {
        noh_t *atual = dicionario->vetor[i];

        while (atual != NULL) {
            noh_t *proximo = atual->proximo;

            free(atual->chave);
            free(atual);

            atual = proximo;
        }
    }
    free(dicionario->vetor);
    free(dicionario);
}