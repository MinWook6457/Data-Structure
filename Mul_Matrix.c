/*
////////////////////////////////////////////////////////////////
//
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 04월 04일
// 프로그램명 : 행렬 곱셈 프로그램
// 프로그램설명 : 주어진 두 행렬을 더하는 프로그램이다.
//				
//
////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
int main() {

	int A_matrix[3][2] = { {1,2},{2,1},{5,1} };
	int B_matrix[2][3] = { {2,2,5},{5,6,4} };
	int C_matrix[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) 
			C_matrix[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				C_matrix[i][j] = C_matrix[i][j] + (A_matrix[i][k] * B_matrix[k][j]);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t", C_matrix[i][j]);
		}
		printf("\n");
	}

	return 0;

}
*/