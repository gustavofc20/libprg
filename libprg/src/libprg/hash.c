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
    dicionario->vetor = malloc(m * sizeof(noh_t*));
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
    // TODO tratar colisões
    no->proximo = NULL;

    dicionario->vetor[indice] = no;

    return 0;
}