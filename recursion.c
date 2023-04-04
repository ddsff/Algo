#include "recursion.h"

#define N  64
static order = 0;

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
	}
	else {
		matrix[ro + s - 1][co + s - 1] = t;
		chessboard_r(matrix, ro, co, s, ro + s - 1, co + s - 1);
	}
	if (row < ro + s && column >= co + s) {
		chessboard_r(matrix, ro, co + s, s, row, column);
	}
	else {
		matrix[ro + s - 1][co + s] = t;
		chessboard_r(matrix, ro, co + s, s, ro + s - 1, co + s);
	}
	if (row >= ro + s && column < co + s) {
		chessboard_r(matrix, ro + s, co, s, row, column);
	}
	else {
		matrix[ro + s][co + s - 1] = t;
		chessboard_r(matrix, ro + s, co, s, ro + s, co + s - 1);
	}
	if (row >= ro + s && column >= co + s) {
		chessboard_r(matrix, ro + s, co + s, s, row, column);
	}
	else {
		matrix[ro + s][co + s] = t;
		chessboard_r(matrix, ro + s, co + s, s, ro + s, co + s);
	}
}
