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


//#undef N
#endif
