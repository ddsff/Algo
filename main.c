#include "main.h"

int matrix[N][N];
int ma[N][N], mb[N][N], mc[N][N], md[N][N];

int main() {
    int a[] = {15, 18, 15, 25, 7, 15, 0, -3, 12, 0, 7};
    int b[] = {3, 2, 1};
    int c[] = { 4, 1, 6, 5, 7, 2, 3 };
    int d[] = {5, 4, 7, 5, 3, 2};
    int stag[] = { 100, 98, 96, 96, 96, 102, 104, 107 };
    int bitmap[] = { 0, 0, 1,  0, 0, 0, 0, 0 };
    //move(1, 2, 3, 16);
    //full_sort(a, 0, 5);
    //full_sort_nr(a, 0 , 5);
    //half_search(a, 3, 0, 7);
    //half_search_nr(a, 3, 0, 7);
    //printf("%d divorce = %d\n", 6, int_divorce(50, 50));
    //chessboard(matrix, 4, 0, 1);
    //matrix_multi_main(4, ma, mb, mc, md);
    //quick_sort(b, 0, 2);
    //quick_sort_3(c, 0, 6);
    //quick_sort_3(a, 0, 10);
    //printf("minest distance = %d", one_dimension_nearst_distance(a, 0, 10));
     //printf_array(c, 7);
    //find_array_min(a, 11);
    //find_array_min_max(a, 11);
    //randomized_select(a, 4, 0, 10);
    //full_sort(d, 0, 5);
    //full_sort_nr(d, 0, 5);
    //nextPermutation(d, 6);
    //insert_sort(a, 11);
    //select_sort(a, 11);
    //printf_array(a, 11);
    stag_bitmap(stag, bitmap, 8);
    printf("Hello, World!\n");
    getchar();
    return 0;
}

