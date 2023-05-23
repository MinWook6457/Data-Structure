/*
////////////////////////////////////////////////////////////////
//
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 04월 04일
// 프로그램명 : 희소 행렬을 행,열,값만을 이용하여 구하기
// 프로그램설명 : 희소 행렬을 행,열,값만으로 이루어진 배열로 다시 초기화하는 프로그램
//				  (예제 3.5)
//
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disible:4996)
#define SIZE 100

typedef struct { // 행렬 요소들
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix{ // 희소 행렬 만들기
	element data[SIZE];
	int rows; // 행의 개수
	int cols; // 열의 개수
	int terms; //항의 개수
}SparseMatrix;


SparseMatrix matrix_transpose2(SparseMatrix a) {
	SparseMatrix b;

	int b_index; // 행렬 b에서 현재위치 저장
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	if (a.terms > 0) {
		b_index = 0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b.data[b_index].row = a.data[i].col;
					b.data[b_index].col = a.data[i].row;
					b.data[b_index].value = a.data[i].value;
					b_index++;
				}
			}
		}
	}
	return b;
}

void martix_print(SparseMatrix a) {
	printf("======================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("%d %d %d\n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("======================\n");
}
int main() {
	// sparse matrix of class 5x6 with 6 non-zero values
	SparseMatrix m = 
	{
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		6,
	};

	SparseMatrix result;

	result = matrix_transpose2(m);
	martix_print(result);
	
	return 0;

}
*/