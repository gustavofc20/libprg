 #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

int bubble_sort(int* array, int tamanho) {
    int atual = array[0];

    for (int i = 0; i < tamanho-1; i++) {
        for (int j = 0; j < tamanho-i-1; j++) {
            if (array[j] > array[j + 1]) {

                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
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