/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

SparseMatrix matrix_translate(SparseMatrix a) {
	SparseMatrix b;

	int bindex;
	b.cols = a.rows;
	b.rows = a.cols;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for(int i = 0 ; i < a.rows ; i++)
			for (int j = 0; j < a.terms; j++) {
				if (i == a.data[j].col) {
					b.data[bindex].col = a.data[j].row;
					b.data[bindex].row = a.data[j].col;
					b.data[bindex].value = a.data[j].value;
					bindex++;
				}
			}
	}
	return b;
}
void print_matrix(SparseMatrix p) {
	for (int i = 0; i < p.terms; i++)
		printf("%d %d %d \n", p.data[i].row, p.data[i].col, p.data[i].value);
}
void main() {
	SparseMatrix s = {
		{{0,3,7},{1,0,9},{1,5,8},{3,0,5},{3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		7
	};
	SparseMatrix result;
	result = matrix_translate(s);

	print_matrix(s);
	printf("=================\n");
	print_matrix(result);



}*/