/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE]; // ������ ũ�� ����
int top = -1;// top�� ���������� ����
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
void push(int item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		top++;
		stack[top] = item;
	}
}
int pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		return;
	}
	else {
		return stack[top--];
	}
}
int peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
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