#ifndef RECURSION_H
#define RECURSION_H

#include "defines.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

extern void chessboard(int matrix[N][N], int length, int row, int column);

extern void chessboard_r(int matrix[N][N], int ro, int co, int length, int row, int column);

extern void matrix_multi_main(int n, int a[N][N], int b[N][N], int c[N][N], int d[N][N]);

extern void matrix_multi_nr(int n, int a[N][N], int b[N][N], int c[N][N]);

extern void matrix_add(int n, int a[N][N], int b[N][N], int c[N][N]);

extern void matrix_sub(int n, int a[N][N], int b[N][N], int c[N][N]);

extern void matrix_multi(int n, int a[N][N], int b[N][N], int c[N][N]);

extern void strassen(int n, int a[N][N], int b[N][N], int c[N][N]);

extern void move(int a, int b, int c, int num);

extern int multi(int n);

extern int fib(int n);

extern int int_divorce(int n, int m);

extern void half_search(int *array, int val, int start, int end);

extern void half_search_nr(int *array, int val, int start, int end);

extern void find_array_min(int *array, int n);

extern void find_array_min_max(int *array, int n);

extern void randomized_select(int *array, int k, int start, int end);

extern void full_sort(int *array, int start, int end);

extern int is_swap(const int *array, int i, int j);

extern void full_sort_nr(int *array, int start, int end);

extern void insert_sort(int *array, int length);

extern void merge(int *array, int p, int q, int r);

extern void merge_sort(int *array, int p, int q);

extern void quick_sort(int *array, int start, int end);

extern void quick_sort_1(int* array, int start, int end);

extern void quick_sort_2(int* array, int start, int end);

extern void quick_sort_3(int* array, int start, int end);

void stag_bitmap();
//#undef N
#endif
