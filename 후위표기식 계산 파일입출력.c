/*
////////////////////////////////////////////////////////////////
//
// �ۼ��� : 20194024 ��ο�
// �ۼ��� : 2022�� 04�� 14��
// ���α׷��� : ����ǥ��� ��� ���α׷�
// ���α׷����� : ���ʿ��� ���������� ������ �˻��ϸ�
//				�����ڿ� �ǿ����ڸ� �����ϸ� ����Ѵ�.
//			    (���� ����� �� �����Ҵ� �̿�)
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define MAX_TERM 100
typedef struct {
	char ch[MAX_TERM];
	int top;
}StackShape;
void init(StackShape *s) {
	s->top = -1;
	for (int i = 0; i < strlen(s->ch); i++)
		s->ch[i] = NULL;
}
void push(StackShape *s, char ch) {
	if (is_full(s)) {
		fprintf(stderr, "push error\n");
		exit(1);
	}
	else {
		s->top++;
		s->ch[s->top] = ch;
	}
}
char pop(StackShape *s) {
	if (is_empty(s)) {
		fprintf(stderr, "pop Error\n");
		exit(1);
	}
	return s->ch[s->top--];
}
int is_empty(StackShape *s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}
int is_full(StackShape *s) {
	if (s->top > MAX_TERM - 1)
		return 1;
	else
		return 0;
}
int eval(char *in) { // ���Ͽ��� �޾ƿ� ���� ���
	
	int op1, op2, n, value;
	char ch = in;
	n = strlen(in);
	StackShape s;
	init(&s);
	for (int i = 0; i < n; i++) {
		ch = in[i];
		if (ch != '+' && ch != '*' && ch != '-' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}

		}
	}

	return pop(&s);
}
void main() {
	FILE *fp;
	fp = fopen("check.txt", "r");
	char *temp[MAX_TERM]; // ���ڿ��� ������ �迭 ������
	char *ch; // �����Ҵ��� ���� ������
	char buffer[MAX_TERM]; 
	int *index;
	if (fp == NULL) {
		fprintf(stderr, "File open error\n");
		exit(1);
	}
	int nCount = 0; // ���ڿ��� ����
	while (!feof(fp)) {
		fgets(temp,stdin,fp);	
		nCount++;
	}
	rewind(fp); // ���������� ����ġ
	index = (int *)malloc(sizeof(int)*nCount); //������ ������ŭ �ε��� �����Ҵ�
	for (int i = 0; i < nCount; i++) {
		fgets(buffer, stdin, fp); 
		index[i] = (int)strlen(buffer); // 0������ nCount������ �ε����� ���ڿ� ���� ����
	}
	rewind(fp); // ���������� ����ġ
	for (int i = 0; i < nCount; i++) {
		ch = (char *)malloc(sizeof(char)*index[i]); // ���ڿ� ���̸�ŭ �����Ҵ�
		fscanf(fp, "%s", ch);
		temp[i] = ch; // �迭 �����Ϳ� �޾ƿ� ���ڿ� ����
		printf("%s\n" ,ch);
	}
	printf("\n");
	int result = 0;

	for (int i = 0; i < nCount; i++) {
		result = eval(temp[i]);
		if (eval(temp[i])) {
			printf("Success : %d\n", result);
			result = 0;
		}
		else
			printf("false\n");
	}
	free(index);
	fclose(fp); // ���� �ݱ�
}*/
