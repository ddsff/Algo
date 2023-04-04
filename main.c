#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void full_sort(int* array, int start, int end);

extern void swap(int* array, int i, int j);

extern int is_swap(const int* array, int i, int j);

extern void full_sort_nr(int* array, int start, int end);

extern void insert_sort(int* array, int length);

extern void merge(int* array, int p, int q, int r);

extern void merge_sort(int* array, int p, int q);

extern void move(int a, int b, int c, int num);

extern int multi(int n);

extern int fib(int n);

extern int int_divorce(int n, int m);

extern void half_search(int* array, int val, int start, int end);

extern void half_search_nr(int* array, int val, int start, int end);

extern void chessboard(int length, int row, int column);

extern void chessboard_r(int ro, int co, int length, int row, int column);

extern void matrix_multi_main(int n);

extern void ma_multi(int n);

extern void matrix_add(int n, int a[64][64], int b[64][64], int c[64][64]);

extern void matrix_sub(int n, int a[64][64], int b[64][64], int c[64][64]);

extern void matrix_multi(int n, int a[64][64], int b[64][64], int c[64][64]);

extern void strassen(int n, int a[64][64], int b[64][64], int c[64][64]);

extern void quick_sort(int* array, int start, int end);
extern void find_array_min(int* array, int n);
extern void find_array_min_max(int* array, int n);
extern void randomized_select(int* array, int k, int start, int end);

int order = 0;
int matrix[100][100];
int ma[64][64], mb[64][64], mc[64][64], md[64][64];

int main() {
	int a[] = { 15, 18, 20, 25, 7, 3, 0, -3, 12, 0, 35 };
	int b[] = { 1, 1, 1 };
	//full_sort(a, 0, 5);
	//full_sort_nr(a, 0 , 5);
	//half_search(a, 3, 0, 7);
	//half_search_nr(a, 3, 0, 7);
	//printf("%d divorce = %d\n", 6, int_divorce(50, 50));
	//chessboard(16, 5, 14);
	//matrix_multi_main(4);
	quick_sort(b, 0, 2);
	quick_sort(a, 0, 10);
	//printf("minest distance = %d", one_dimension_nearst_distance(a, 0, 10));
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	    printf("%d ", a[i]);
	//find_array_min(a, 11);
	//find_array_min_max(a, 11);
	//randomized_select(a, 4, 0, 10);
	printf("Hello, World!\n");
	getchar();
	return 0;
}

void swap(int* array, int i, int j) {
	if (i == j) return;
	else {
		array[i] = array[i] ^ array[j];
		array[j] = array[i] ^ array[j];
		array[i] = array[i] ^ array[j];
	}
}

void full_sort(int* array, int start, int end) {
	if (start == end) {
		printf("order %2d :", order++);
		for (int i = 0; i <= end; i++) {
			printf("%d ", array[i]);
		}
		printf("\n");
	}
	else {
		for (int i = start; i <= end; i++) {
			if (is_swap(array, i, end)) {
				swap(array, start, i);
				full_sort(array, start + 1, end);
				swap(array, start, i);
			}
		}
	}
}

int is_swap(const int* array, int i, int j) {
	for (; j > i; j--) {
		if (array[i] == array[j]) return 0;
	}
	return 1;
}

void full_sort_nr(int* array, int start, int end) {
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

void insert_sort(int* array, int length) {

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

void merge(int* array, int p, int q, int r) {

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
		}
		else if (r2[j] == temp) {
			array[i] = r1[k];
			k++;
		}
		else {
			array[i] = r1[k] > r2[j] ? r2[j] : r1[k];
			if (r1[k] > r2[j]) {
				j++;
			}
			else {
				k++;
			}
		}
	}
}

void merge_sort(int* array, int p, int q) {

	int mid;
	mid = (p + q) / 2;
	if (p < q) {
		merge_sort(array, p, mid);
		merge_sort(array, mid + 1, q);
		merge(array, p, mid, q);
	}
}

void move(int a, int b, int c, int num) {
	if (num == 1) {
		printf("move %d to %d\n", a, c);
	}
	else {
		move(a, c, b, num - 1);
		printf("move %d to %d\n", a, c);
		move(b, a, c, num - 1);
	}
}

int multi(int n) {
	if (n == 0) {
		return 1;
	}
	else {
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

void half_search(int* array, int val, int start, int end) {
	int mid;
	mid = (start + end) / 2;
	if (array[mid] == val) {
		printf("array[%d] = %d\n", mid, val);
		return;
	}
	else {
		if (array[mid] < val) half_search(array, val, mid + 1, end);
		else half_search(array, val, start, mid - 1);
	}
}

void half_search_nr(int* array, int val, int start, int end) {
	int mid;
	while (1) {
		mid = (start + end) / 2;
		if (array[mid] == val) {
			printf("array[%d] = %d\n", mid, val);
			return;
		}
		else if (array[mid] < val) {
			start = mid + 1;
		}
		else if (array[mid] > val) {
			end = mid - 1;
		}
	}
}

void chessboard(int length, int row, int column) {
	//matrix[row][column] = 0;
	chessboard_r(0, 0, length, row, column);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void chessboard_r(int ro, int co, int length, int row, int column) {
	int s = length / 2;
	if (length == 1) return;
	int t = ++order;
	if (row < ro + s && column < co + s) {
		chessboard_r(ro, co, s, row, column);
	}
	else {
		matrix[ro + s - 1][co + s - 1] = t;
		chessboard_r(ro, co, s, ro + s - 1, co + s - 1);
	}
	if (row < ro + s && column >= co + s) {
		chessboard_r(ro, co + s, s, row, column);
	}
	else {
		matrix[ro + s - 1][co + s] = t;
		chessboard_r(ro, co + s, s, ro + s - 1, co + s);
	}
	if (row >= ro + s && column < co + s) {
		chessboard_r(ro + s, co, s, row, column);
	}
	else {
		matrix[ro + s][co + s - 1] = t;
		chessboard_r(ro + s, co, s, ro + s, co + s - 1);
	}
	if (row >= ro + s && column >= co + s) {
		chessboard_r(ro + s, co + s, s, row, column);
	}
	else {
		matrix[ro + s][co + s] = t;
		chessboard_r(ro + s, co + s, s, ro + s, co + s);
	}
}

void matrix_multi_main(int n) {

	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ma[i][j] = rand() % 100;
			mb[i][j] = rand() % 100;
		}
	}
	printf("matrix a:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", ma[i][j]);
		}
		printf("\n");
	}
	printf("matrix b:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", mb[i][j]);
		}
		printf("\n");
	}
	ma_multi(n);
	printf("matrix c:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%6d ", mc[i][j]);
		}
		printf("\n");
	}
	strassen(n, ma, mb, md);
	printf("matrix d:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%6d ", md[i][j]);
		}
		printf("\n");
	}
}

void ma_multi(int n) {
	int sum;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0;
			for (int k = 0; k < n; k++) {
				sum += ma[i][k] * mb[k][j];
			}
			mc[i][j] = sum;
		}
	}
}

void matrix_add(int n, int a[64][64], int b[64][64], int c[64][64]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void matrix_sub(int n, int a[64][64], int b[64][64], int c[64][64]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}

void matrix_multi(int n, int a[64][64], int b[64][64], int c[64][64]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = 0;
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void strassen(int n, int a[64][64], int b[64][64], int c[64][64]) {

	int a11[64][64], a12[64][64], a21[64][64], a22[64][64];
	int b11[64][64], b12[64][64], b21[64][64], b22[64][64];
	int c11[64][64], c12[64][64], c21[64][64], c22[64][64];
	int m1[64][64], m2[64][64], m3[64][64], m4[64][64], m5[64][64], m6[64][64], m7[64][64];
	int temp1[64][64], temp2[64][64], temp3[64][64];

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

void quick_sort(int* array, int start, int end) {
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

void find_array_min(int* array, int n) {
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

void find_array_min_max(int* array, int n) {

	int min, max, start;
	int min1, max1;

	if (n % 2 == 1) {
		min = array[0];
		max = array[0];
		start = 1;
	}
	else {
		if (array[0] > array[1]) {
			min = array[1];
			max = array[0];
		}
		else {
			min = array[0];
			max = array[1];
		}
		start = 2;
	}
	for (int i = start; i < n; i = i + 2) {
		if (array[i] > array[i + 1]) {
			min1 = array[i + 1];
			max1 = array[i];
		}
		else {
			min1 = array[i];
			max1 = array[i + 1];
		}
		if (min1 < min) min = min1;
		if (max1 > max) max = max1;
	}
	printf("array min = %d max = %d", min, max);
}

void randomized_select(int* array, int k, int start, int end) {

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

int one_dimension_nearst_distance(int* array, int start, int end) {
	
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




























































