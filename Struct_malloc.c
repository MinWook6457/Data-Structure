/*
////////////////////////////////////////////////////////////////
//
// �ۼ��� : 20194024 ��ο�
// �ۼ��� : 2022�� 04�� 10��
// ���α׷��� : ����ü �����Ҵ� ���α׷�
// ���α׷����� : ����ü�� �����Ҵ� �ϰ� �����޸� �ݳ�			
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