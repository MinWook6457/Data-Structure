/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100
typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

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
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		top++;
		stack[top] = item;
	}
}
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else {
		return stack[top--];
	}
}
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return stack[top];
}
void main() {
	element ie = {
		20194024,
		"김민욱",
		"수원"
	};
	element oe;
	push(ie);
	oe = pop();

	printf("학번 %d\n", oe.student_no);
	printf("이름 %s\n", oe.name);
	printf("주소 %s\n", oe.address);

}*/