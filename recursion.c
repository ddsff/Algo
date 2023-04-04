#include "recursion.h"

static int order = 0;
static int move_cnt = 0;

void chessboard(int matrix[N][N], int length, int row, int column) {
    //matrix[row][column] = 0;
    chessboard_r(matrix, 0, 0, length, row, column);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void chessboard_r(int matrix[N][N], int ro, int co, int length, int row, int column) {
    int s = length / 2;
    if (length == 1) return;
    int t = ++order;
    if (row < ro + s && column < co + s) {
        chessboard_r(matrix, ro, co, s, row, column);
    } else {
        matrix[ro + s - 1][co + s - 1] = t;
        chessboard_r(matrix, ro, co, s, ro + s - 1, co + s - 1);
    }
    if (row < ro + s && column >= co + s) {
        chessboard_r(matrix, ro, co + s, s, row, column);
    } else {
        matrix[ro + s - 1][co + s] = t;
        chessboard_r(matrix, ro, co + s, s, ro + s - 1, co + s);
    }
    if (row >= ro + s && column < co + s) {
        chessboard_r(matrix, ro + s, co, s, row, column);
    } else {
        matrix[ro + s][co + s - 1] = t;
        chessboard_r(matrix, ro + s, co, s, ro + s, co + s - 1);
    }
    if (row >= ro + s && column >= co + s) {
        chessboard_r(matrix, ro + s, co + s, s, row, column);
    } else {
        matrix[ro + s][co + s] = t;
        chessboard_r(matrix, ro + s, co + s, s, ro + s, co + s);
    }
}

void matrix_multi_main(int n, int a[N][N], int b[N][N], int c[N][N], int d[N][N]) {

    srand((unsigned int) time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
        }
    }
    printf("matrix a:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("matrix b:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }
    matrix_multi_nr(n, a, b, c);
    printf("matrix c:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6d ", c[i][j]);
        }
        printf("\n");
    }
    strassen(n, a, b, d);
    printf("matrix d:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6d ", d[i][j]);
        }
        printf("\n");
    }
}

void matrix_multi_nr(int n, int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


void matrix_add(int n, int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_sub(int n, int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrix_multi(int n, int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void strassen(int n, int a[N][N], int b[N][N], int c[N][N]) {

    int a11[N][N], a12[N][N], a21[N][N], a22[N][N];
    int b11[N][N], b12[N][N], b21[N][N], b22[N][N];
    int c11[N][N], c12[N][N], c21[N][N], c22[N][N];
    int m1[N][N], m2[N][N], m3[N][N], m4[N][N], m5[N][N], m6[N][N], m7[N][N];
    int temp1[N][N], temp2[N][N], temp3[N][N];

    if (n == 2) {
        matrix_multi(2, a, b, c);
        return;
    }
    for (int i = 0; i < n / 2; i++) {
        for (size_t j = 0; j < n / 2; j++) {
            a11[i][j] = a[i][j];
            b11[i][j] = b[i][j];
            a12[i][j] = a[i][j + n / 2];
            b12[i][j] = b[i][j + n / 2];
            a21[i][j] = a[i + n / 2][j];
            b21[i][j] = b[i + n / 2][j];
            a22[i][j] = a[i + n / 2][j + n / 2];
            b22[i][j] = b[i + n / 2][j + n / 2];
        }
    }
    matrix_add(n / 2, a11, a22, temp1);
    matrix_add(n / 2, b11, b22, temp2);
    strassen(n / 2, temp1, temp2, m1);
    matrix_add(n / 2, a21, a22, temp1);
    strassen(n / 2, temp1, b11, m2);
    matrix_sub(n / 2, b12, b22, temp1);
    strassen(n / 2, a11, temp1, m3);
    matrix_sub(n / 2, b21, b11, temp1);
    strassen(n / 2, a22, temp1, m4);
    matrix_add(n / 2, a11, a12, temp1);
    strassen(n / 2, temp1, b22, m5);
    matrix_sub(n / 2, a21, a11, temp1);
    matrix_add(n / 2, b11, b12, temp2);
    strassen(n / 2, temp1, temp2, m6);
    matrix_sub(n / 2, a12, a22, temp1);
    matrix_add(n / 2, b21, b22, temp2);
    strassen(n / 2, temp1, temp2, m7);
    matrix_add(n / 2, m1, m4, temp1);
    matrix_sub(n / 2, temp1, m5, temp2);
    matrix_add(n / 2, temp2, m7, c11);
    matrix_add(n / 2, m3, m5, c12);
    matrix_add(n / 2, m2, m4, c21);
    matrix_sub(n / 2, m1, m2, temp1);
    matrix_add(n / 2, temp1, m3, temp2);
    matrix_add(n / 2, temp2, m6, c22);
    for (int i = 0; i < n / 2; i++) {
        for (size_t j = 0; j < n / 2; j++) {
            c[i][j] = c11[i][j];
            c[i][j + n / 2] = c12[i][j];
            c[i + n / 2][j] = c21[i][j];
            c[i + n / 2][j + n / 2] = c22[i][j];
        }
    }
}
void move(int a, int b, int c, int num) {
    if (num == 1) {
        printf("move cnt[%8d]: move %d to %d\n", ++move_cnt, a, c);
    } else {
        move(a, c, b, num - 1);
        printf("move cnt[%8d]: move %d to %d\n", ++move_cnt, a, c);
        move(b, a, c, num - 1);
    }
}

int multi(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * multi(n - 1);
    }
}

int fib(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int int_divorce(int n, int m) {
    if (n < 1 || m < 1) return 0;
    else if (n == 1 || m == 1) return 1;
    else if (n < m) return int_divorce(n, n);
    else if (n == m) return 1 + int_divorce(n, m - 1);
    else return int_divorce(n, m - 1) + int_divorce(n - m, m);
}

void half_search(int *array, int val, int start, int end) {
    int mid;
    mid = (start + end) / 2;
    if (array[mid] == val) {
        printf("array[%d] = %d\n", mid, val);
        return;
    } else {
        if (array[mid] < val) half_search(array, val, mid + 1, end);
        else half_search(array, val, start, mid - 1);
    }
}

void half_search_nr(int *array, int val, int start, int end) {
    int mid;
    while (1) {
        mid = (start + end) / 2;
        if (array[mid] == val) {
            printf("array[%d] = %d\n", mid, val);
            return;
        } else if (array[mid] < val) {
            start = mid + 1;
        } else if (array[mid] > val) {
            end = mid - 1;
        }
    }
}
