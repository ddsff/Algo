//
// Created by 28432 on 2023/4/5.
//

#include "chapter2.h"

void select_sort(int* array, int n) {

    int min, swap_idx;

    for(int i = 0; i < n -1; i++) {
        min = array[i];
        swap_idx = i;
        for(int j = i + 1; j <= n -1; j++) {
            if(min > array[j]) {
                swap_idx = j;
                min = array[j];
            }
        }
        swap(array, i, swap_idx);
    }
}
