/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE]; // 스택의 크기 설정
int top = -1;// top을 전역변수로 선언
//공백 상태 검출 함수
int is_empty() {
	if (top == -1) // 공백이라면 -1 반환 (거짓)
		return 1;
	else
		return 0;
}
//포화 상태 검출 함수
int is_full() {
	if (top == (MAX_STACK_SIZE - 1))
		return 1;
	else
		return 0;
}
//삽입 함수
void push(int item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		top++;
		stack[top] = item;
	}
}
int pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else {
		return stack[top--];
	}
}
int peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return stack[top--];
}
void main() {
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}*/