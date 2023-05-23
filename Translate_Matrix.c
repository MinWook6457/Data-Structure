/*
#include <stdio.h>
#define ROWS 3
#define COLS 3
void matrix_translate(int  A[ROWS][COLS], int B[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			B[j][i] = A[i][j];
}
void matrix_print(int A[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
}
void main() {
	int A[ROWS][COLS] = { {5,6,7},{9,8,3},{1,0,6} };
	int B[ROWS][COLS] = { 0 };

	matrix_translate(A, B);
	matrix_print(A);
	printf("=====================\n");
	matrix_print(B);

}*/