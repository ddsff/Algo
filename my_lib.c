//
// Created by 28432 on 2023/4/4.
//

#include "my_lib.h"
void swap(int *array, int i, int j) {
    if (i == j) return;
    else {
        array[i] = array[i] ^ array[j];
        array[j] = array[i] ^ array[j];
        array[i] = array[i] ^ array[j];
    }
}




void printf_array(int* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

