#include <stdio.h>

extern void full_sort   (int* array, int start, int end);
extern void swap        (int* array, int i, int j);
extern int  is_swap     (const int* array, int i, int j);
extern void full_sort_nr(int* array, int start, int end);

int order = 1;
int main() {
    int a[] = {1, 2, 2,3, 3, 4};
    full_sort(a, 0, 5);
    full_sort_nr(a, 0 , 5);
    printf("Hello, World!\n");
    getchar();



    return 0;
}
void swap(int* array, int i, int j){
    if(i == j) return;
    else{
        array[i] = array[i] ^ array[j];
        array[j] = array[i] ^ array[j];
        array[i] = array[i] ^ array[j];
    }
}
void full_sort(int* array, int start, int end){
    if(start == end){
        printf("order %2d :",order++);
        for(int i = 0; i <= end; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
    }else {
        for(int i = start; i <= end; i++) {
            if(is_swap(array, i, end)) {
                swap(array, start, i);
                full_sort(array, start + 1, end);
                swap(array, start, i);
            }
        }
    }
}
int is_swap(const int *array, int i, int j){
    for(;j > i; j--){
        if(array[i] == array[j]) return 0;
    }
    return 1;
}
void full_sort_nr(int* array, int start, int end){
    int next, count, order = 1;
    int replaced_idx, replace_idx;
    do{
        next = 0;
        // print array
        printf("order %2d :",order++);
        for(int i = start; i <= end; i++)
            printf("%d ", array[i]);
        printf("\n");
        // found next set
        for(int i = end ; i > start; i--){
            if(array[i - 1] < array[i]){
                next = 1;
                replaced_idx = i - 1;
                break;
            }
        }
        for(int i = end ; i > start; i--){
            if(array[replaced_idx] < array[i]){
                replace_idx = i;
                break;
            }
        }
        swap(array, replaced_idx, replace_idx);
        count = 0;
        for (int i = replaced_idx + 1; count <  (end - replaced_idx)/2; i++) {
            swap(array, i,  end - i + replaced_idx + 1);
            count++;
        }
    }while(next);
}