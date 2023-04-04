#include "main.h"

extern void full_sort(int *array, int start, int end);


extern int is_swap(const int *array, int i, int j);

extern void full_sort_nr(int *array, int start, int end);

extern void insert_sort(int *array, int length);

extern void merge(int *array, int p, int q, int r);

extern void merge_sort(int *array, int p, int q);

extern void quick_sort(int *array, int start, int end);

extern void find_array_min(int *array, int n);

extern void find_array_min_max(int *array, int n);

extern void randomized_select(int *array, int k, int start, int end);

int order = 0;
int matrix[N][N];
int ma[N][N], mb[N][N], mc[N][N], md[N][N];

int main() {
    int a[] = {15, 18, 20, 25, 7, 3, 0, -3, 12, 0, 35};
    int b[] = {1, 1, 1};
    move(1, 2, 3, 16);
    //full_sort(a, 0, 5);
    //full_sort_nr(a, 0 , 5);
    //half_search(a, 3, 0, 7);
    //half_search_nr(a, 3, 0, 7);
    //printf("%d divorce = %d\n", 6, int_divorce(50, 50));
    //chessboard(matrix, 4, 0, 1);
    //matrix_multi_main(4, ma, mb, mc, md);
    //quick_sort(b, 0, 2);
    //quick_sort(a, 0, 10);
    //printf("minest distance = %d", one_dimension_nearst_distance(a, 0, 10));
    //for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    //    printf("%d ", a[i]);
    //find_array_min(a, 11);
    //find_array_min_max(a, 11);
    //randomized_select(a, 4, 0, 10);
    printf("Hello, World!\n");
    getchar();
    return 0;
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
        while (i >= 0 && array[i] < key) {
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






void quick_sort(int *array, int start, int end) {
    if (start >= end) return;
    int key = array[start];
    int i = start, j = end;
    while (i < j) {
        if (key <= array[j]) {
            j--;
        }
        swap(array, i, j);
        if (key >= array[i]) {
            i++;
        }
        swap(array, i, j);
    }
    quick_sort(array, start, i - 1);
    quick_sort(array, i + 1, end);
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




























































