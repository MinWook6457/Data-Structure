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

//���� ���� ���� �Լ�
int is_empty() {
	if (top == -1) // �����̶�� -1 ��ȯ (����)
		return 1;
	else
		return 0;
}
//��ȭ ���� ���� �Լ�
int is_full() {
	if (top == (MAX_STACK_SIZE - 1))
		return 1;
	else
		return 0;
}
//���� �Լ�
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		top++;
		stack[top] = item;
	}
}
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		return;
	}
	else {
		return stack[top--];
	}
}
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return stack[top];
}
void main() {
	element ie = {
		20194024,
		"��ο�",
		"����"
	};
	element oe;
	push(ie);
	oe = pop();

	printf("�й� %d\n", oe.student_no);
	printf("�̸� %s\n", oe.name);
	printf("�ּ� %s\n", oe.address);

}*/