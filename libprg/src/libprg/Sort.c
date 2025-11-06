 #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

int bubble_sort(int* array, int tamanho) {
    int atual = array[0];
    int tamnaho_qua=tamanho*tamanho;

    for (int i = 1; i < tamnaho_qua; i++) {
        int proximo=array[i];

        if (atual<proximo) {
            atual = array[i];
            continue;
        }

        if (atual>proximo) {
            int aux = array[i];
            array[i] = array[i-1];
            array[i-1] = aux;
        }
    }

    return 0;
}

int insertion_sort(int* array, int tamanho) {



 return 0;
}

int selection_sort(int* array, int tamanho) {



 return 0;
}