/*
////////////////////////////////////////////////////////////////
//
// �ۼ��� : 20194024 ��ο�
// �ۼ��� : 2022�� 04�� 04��
// ���α׷��� : ��� ����� ��,��,������ �̿��Ͽ� ���ϱ�
// ���α׷����� : ��� ����� ��,��,�������� �̷���� �迭�� �ٽ� �ʱ�ȭ�ϴ� ���α׷�
//				  (���� 3.5)
//
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disible:4996)
#define SIZE 100

typedef struct { // ��� ��ҵ�
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix{ // ��� ��� �����
	element data[SIZE];
	int rows; // ���� ����
	int cols; // ���� ����
	int terms; //���� ����
}SparseMatrix;


SparseMatrix matrix_transpose2(SparseMatrix a) {
	SparseMatrix b;

	int b_index; // ��� b���� ������ġ ����
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