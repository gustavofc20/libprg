 #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

int bubble_sort(int* array, int tamanho) {

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

    for (int i = 0; i < tamanho; i++) {
        if (array[i-1] > array[i]) {
            for (int j=i-1; j >= 0; j--) {
                if (array[j]> array[i]) {

                    array[j+1] = array[j];
                    array[j] = array[i];

                }

            }
        }
    }

 return 0;
}

int selection_sort(int* array, int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i +1; j<tamanho; j++) {
            if (array[j] < array[menor]) {
                menor = j;
            }
        }
        if (menor!=i) {
            int aux = array[i];
            array[i] = array[menor];
            array[menor] = aux;
        }
    }

 return 0;
}