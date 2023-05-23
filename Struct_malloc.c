/*
////////////////////////////////////////////////////////////////
//
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 04월 10일
// 프로그램명 : 구조체 동적할당 프로그램
// 프로그램설명 : 구조체를 동적할당 하고 동적메모리 반납			
//
////////////////////////////////////////////////////////////////
#include <stdio.h>
typedef struct {
	int n;
	char string[20];
}Malloc;
int main() {
	Malloc *input;
	input = (Malloc*)malloc(sizeof(Malloc));

	input->n = 100;
	strcpy(input->string, "just testing");

	printf("%d %s ", input->n, input->string);

	free(input);
}
*/