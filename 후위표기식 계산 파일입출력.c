/*
////////////////////////////////////////////////////////////////
//
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 04월 14일
// 프로그램명 : 후위표기식 계산 프로그램
// 프로그램설명 : 왼쪽에서 오른쪽으로 수식을 검사하며
//				연산자와 피연산자를 구분하며 계산한다.
//			    (파일 입출력 및 동적할당 이용)
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
int eval(char *in) { // 파일에서 받아온 수식 계산
	
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
	char *temp[MAX_TERM]; // 문자열을 저장할 배열 포인터
	char *ch; // 동적할당을 위한 포인터
	char buffer[MAX_TERM]; 
	int *index;
	if (fp == NULL) {
		fprintf(stderr, "File open error\n");
		exit(1);
	}
	int nCount = 0; // 문자열의 개수
	while (!feof(fp)) {
		fgets(temp,stdin,fp);	
		nCount++;
	}
	rewind(fp); // 파일포인터 원위치
	index = (int *)malloc(sizeof(int)*nCount); //파일의 개수만큼 인덱스 동적할당
	for (int i = 0; i < nCount; i++) {
		fgets(buffer, stdin, fp); 
		index[i] = (int)strlen(buffer); // 0번부터 nCount번까지 인덱스에 문자열 길이 저장
	}
	rewind(fp); // 파일포인터 원위치
	for (int i = 0; i < nCount; i++) {
		ch = (char *)malloc(sizeof(char)*index[i]); // 문자열 길이만큼 동적할당
		fscanf(fp, "%s", ch);
		temp[i] = ch; // 배열 포인터에 받아온 문자열 저장
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
	fclose(fp); // 파일 닫기
}*/
