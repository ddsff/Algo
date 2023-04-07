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

void find_array_min(int *array, int n) {
    int min, idx;
    min = array[0];
    idx = 0;
    for (int i = 1; i < n; i++) {
        if (min > array[i]) {
            min = array[i];
            idx = i;
        }
    }
    printf("array min = %d idx =%d", array[idx], idx);
}

void find_array_min_max(int *array, int n) {

    int min, max, start;
    int min1, max1;

    if (n % 2 == 1) {
        min = array[0];
        max = array[0];
        start = 1;
    } else {
        if (array[0] > array[1]) {
            min = array[1];
            max = array[0];
        } else {
            min = array[0];
            max = array[1];
        }
        start = 2;
    }
    for (int i = start; i < n; i = i + 2) {
        if (array[i] > array[i + 1]) {
            min1 = array[i + 1];
            max1 = array[i];
        } else {
            min1 = array[i];
            max1 = array[i + 1];
        }
        if (min1 < min) min = min1;
        if (max1 > max) max = max1;
    }
    printf("array min = %d max = %d", min, max);
}

void randomized_select(int *array, int k, int start, int end) {

    int key = array[start];
    int i = start, j = end;
    while (i != j) {
        while (key < array[j]) {
            j--;
        }
        swap(array, i, j);
        while (key > array[i]) {
            i++;
        }
        swap(array, i, j);
    }
    if (i == k) printf("array[%d] = %d", k, array[i]);
    else if (i > k) randomized_select(array, k, start, i - 1);
    else if (i < k) randomized_select(array, k, i + 1, end);

}

void full_sort(int *array, int start, int end) {
    if (start == end) {
        printf("order %2d :", order++);
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            if (is_swap(array, i, end)) {
                swap(array, start, i);
                full_sort(array, start + 1, end);
                swap(array, start, i);
            }
        }
    }
}

int is_swap(const int *array, int i, int j) {
    for (; j > i; j--) {
        if (array[i] == array[j]) return 0;
    }
    return 1;
}

void full_sort_nr(int *array, int start, int end) {
    int next, count, order = 1;
    int replaced_idx, replace_idx;
    do {
        next = 0;
        // print array
        printf("order %2d :", order++);
        for (int i = start; i <= end; i++)
            printf("%d ", array[i]);
        printf("\n");
        // found next set
        for (int i = end; i > start; i--) {
            if (array[i - 1] < array[i]) {
                next = 1;
                replaced_idx = i - 1;
                break;
            }
        }
        for (int i = end; i > start; i--) {
            if (array[replaced_idx] < array[i]) {
                replace_idx = i;
                break;
            }
        }
        swap(array, replaced_idx, replace_idx);
        count = 0;
        for (int i = replaced_idx + 1; count < (end - replaced_idx) / 2; i++) {
            swap(array, i, end - i + replaced_idx + 1);
            count++;
        }
    } while (next);
}

void insert_sort(int *array, int length) {

    int key, i;

    for (int j = 1; j < length; j++) {
        i = j - 1;
        key = array[j];
        while (i >= 0 &&  key < array[i]) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}

void merge(int *array, int p, int q, int r) {

    int k = p;
    int j = q + 1;
    int r1[100], r2[100];
    int temp = 1000000, temp1, temp2;
    for (int i = p; i <= q; i++) {
        r1[i] = array[i];
    }
    r1[q + 1] = temp;
    for (int i = q + 1; i <= r; i++) {
        r2[i] = array[i];
    }
    r2[r + 1] = temp;
    for (int i = p; i <= r; i++) {
        if (r1[k] == temp) {
            array[i] = r2[j];
            j++;
        } else if (r2[j] == temp) {
            array[i] = r1[k];
            k++;
        } else {
            array[i] = r1[k] > r2[j] ? r2[j] : r1[k];
            if (r1[k] > r2[j]) {
                j++;
            } else {
                k++;
            }
        }
    }
}

void merge_sort(int *array, int p, int q) {

    int mid;
    mid = (p + q) / 2;
    if (p < q) {
        merge_sort(array, p, mid);
        merge_sort(array, mid + 1, q);
        merge(array, p, mid, q);
    }
}

int one_dimension_nearst_distance(int *array, int start, int end) {

    int left, right, min;
    int mid = (start + end) / 2;
    if (end == start) return 100000;
    else if ((end - start) == 1) return array[end] - array[start];
    left = one_dimension_nearst_distance(array, start, mid);
    right = one_dimension_nearst_distance(array, mid + 1, end);
    min = left > right ? right : left;
    min = ((array[mid + 1] - array[mid]) > min) ? min : array[mid + 1] - array[mid];
    return min;
}

void quick_sort(int *array, int start, int end) {
    if (start >= end) return;
    int key = array[start];
    int i = start, j = end;
    while (i < j) {
        while (key <= array[j] && i < j) {
            j--;
        }
        swap(array, i, j);
        while (key >= array[i] && i < j) {
            i++;
        }
        swap(array, i, j);
    }
    quick_sort(array, start, i - 1);
    quick_sort(array, i + 1, end);
}

void quick_sort_1(int* array, int start, int end) {

    int key = array[start];
    int i = start, j = end;
    if (start >= end) return;
    while(i < j) {
        while (i < j && key <= array[j])
            j--;
        while (i < j && key >= array[i])
            i++;
        swap(array, i, j);
    }
    swap(array, start, i);
    quick_sort_1(array, start, i - 1);
    quick_sort_1(array, i + 1, end);
}

void quick_sort_2(int* array, int start, int end) {

    int key = array[start];
    int key_idx = start;
    if (start >= end) return;
    int i = start, j = end;
    while (i < j) {
        while (i < j && key <= array[j])
            j--;
        array[key_idx] = array[j];
        key_idx = j;
        while (i < j && key >= array[i])
            i++;
        array[key_idx] = array[i];
        key_idx = i;
    }
    array[key_idx] = key;
    quick_sort_2(array, start, key_idx - 1);
    quick_sort_2(array, key_idx + 1, end);
}

void quick_sort_3(int* array, int start, int end) {
    
    int key = array[start];
    if (start >= end) return;
    int slow = start, fast = start;
    while(fast < end) {
        if (array[++fast] < key) {
            swap(array, ++slow, fast);
        }
    }
    swap(array, start, slow);
    quick_sort_3(array, start, slow - 1);
    quick_sort_3(array, slow + 1, end);
}

void stag_bitmap(int* stag, int * bitmap, int length) {

    int find = 0, i = 0, idx = 0, cnt = 0;
    int array[N];

    for (int j = 0; j < N; j++) {
        array[j] = 0;
    }
    while (i < length - 1) {
        if (stag[i] == stag[i + 1] && find == 0) {
            find = 1;
            array[idx++] = i;
        }
        if (stag[i] != stag[i + 1] && find == 1) {
            find = 0;
            array[idx] = i;
            cnt++;
        }
        i++;
    }
    for (size_t j = 0; j < cnt * 2; j++)
    {
        printf("%d ", array[j]);
    }
    stag_bitmap_sort(bitmap, array, cnt * 2);
}

void stag_bitmap_sort(int* bitmap, int* array, int cnt) {

    
    


}

