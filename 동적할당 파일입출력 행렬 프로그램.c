/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define COLS 3
int main() {
	FILE *fp;
	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf(stderr, "File Open Error\n");
		exit(1);
	}

	int **matrix;
	matrix = (int **)malloc(sizeof(int*)*COLS);
	int op1, op2, op3;
	int nCount = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d%d%d", &op1, &op2, &op3);
		nCount++;
	}

	rewind(fp);

	for (int i = 0; i < nCount; i++)
	{
		matrix[i] = (int *)malloc(sizeof(int)*COLS);
	}

	for (int i = 0; i < nCount; i++)
	{
		for (int j = 0; j < COLS; j++) {
			fscanf(fp, "%d", &matrix[i][j]);
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	free(fp);
	return 0;
}*/