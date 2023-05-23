/*
////////////////////////////////////////////////////////////////
//
// �ۼ��� : 20194024 ��ο�
// �ۼ��� : 2022�� 04�� 1��
// ���α׷��� : ��ȣ �˻� ���α׷�
// ���α׷����� : ���ڿ��� �޾� ��ȣ�� ���ǿ� �´ٸ� ������
//				���ǿ� ���� �ʴ´ٸ� ���и� ����ϴ� ���α׷�
//				���� ����°� �����Ҵ��� ����Ͽ���.
//
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TERMS 100
#pragma warning(disable:4996)
typedef struct { // ����ü ����
	char name[MAX_TERMS]; // ��ȣ�� �޾� ���ÿ� �Ҵ��ϴ� ����
	int top; // ������ ��ġ�� ǥ���ϴ� ����
}StackType;
void init(StackType *s) { // ���� �ʱ�ȭ
	s->top = -1;
	for (int i = 0; i < strlen(s->name); i++)
		s->name[i] = NULL;
}
int is_empty(StackType *s) { // ���� ���� ���� �˻�
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
int is_full(StackType *s) { // ���� ��ȭ ���� �˻�
	if (s->top > MAX_TERMS - 1) {
		return 1;
	}
	else
		return 0;
}
void push(StackType *s, char ch) { // ���� ���� �Լ�
	if (is_full(s)) {
		fprintf(stderr, "Push Error\n");
		exit(1);
	}
	else {
		s->top++;
		s->name[s->top] = ch;
	}
}
int pop(StackType *s) { // ���� ���� �Լ� 
	if (is_empty(s)) {
		fprintf(stderr, "pop Error\n");
		exit(1);
	}

	return s->top--;
}
int check_matching(const char *in) { // ��ȣ �˻� �Լ�
	StackType s;
	char ch, open_ch; // ch�� ���ÿ� ���� ���� , open_ch�� ���ÿ��� ���� ����(���� ��ȣ)
	init(&s);

	int n = strlen(in); // ���ڿ� ����(�ؽ�Ʈ ���Ͽ��� ���� ���ڿ��� ������ ���� �����ϰ� ��� NULL���ڸ� �����ϰ� �ִ�. ���� ���ڿ� ���� - 1�� ���־�� �˻簡 �����ϴ�.)

	for (int i = 0; i < n-1; i++) { // ���ڿ��� �ִ� ��ȣ�� ������ȣ���� ������ȣ���� �˻�
		ch = in[i];
		switch (ch)
		{
		case '(': case '[': case '{': // ������ȣ��� ���ÿ� �߰�
			push(&s, ch);
			break;
		case ')':  case ']': case '}': // ���C ��ȣ��� ���ÿ��� ������ ������ȣ�� �˻�
			if (is_empty(&s)) // ������ ����ִٸ� ����
				return  0;
			else {
				open_ch = pop(&s);
				if (ch != '(' && open_ch == ')' || ch != '[' && open_ch == ']' || ch != '{' && open_ch == '}') // ��ȣ�� ���� �̷��� �ʴ´ٸ�
					return 0;
			}
			break;
		}
	}
	if (!is_empty(&s)) // ������ ������� �ʴٸ� ����
		return 0;
	return 1;
}
int last_line_check_matching(const char *in) { // ��ȣ �˻� �Լ�
	StackType s;
	char ch, open_ch; // ch�� ���ÿ� ���� ���� , open_ch�� ���ÿ��� ���� ����(���� ��ȣ)
	init(&s);

	int n = strlen(in); // ���ڿ� ����

	for (int i = 0; i < n ; i++) { // ���ڿ��� �ִ� ��ȣ�� ������ȣ���� ������ȣ���� �˻�
		ch = in[i];
		switch (ch)
		{
		case '(': case '[': case '{': // ������ȣ��� ���ÿ� �߰�
			push(&s, ch);
			break;
		case ')':  case ']': case '}': // ���C ��ȣ��� ���ÿ��� ������ ������ȣ�� �˻�
			if (is_empty(&s)) // ������ ����ִٸ� ����
				return  0;
			else {
				open_ch = pop(&s);
				if (ch != '(' && open_ch == ')' || ch != '[' && open_ch == ']' || ch != '{' && open_ch == '}') // ��ȣ�� ���� �̷��� �ʴ´ٸ�
					return 0;
			}
			break;
		}
	}
	if (!is_empty(&s)) // ������ ������� �ʴٸ� ����
		return 0;
	return 1;
}
void main() {
	FILE *fp;
	fp = fopen("Gaul.txt", "r");
	char *temp[MAX_TERMS];
	char *ch;
	if (fp == NULL) {
		fprintf(stderr, "File open error\n");
		exit(1);
	}
	int nCount = 0;
	while (!feof(fp)) {
		fgets(temp, stdin, fp);
		nCount++;
	}
	rewind(fp);
	for (int i = 0; i < nCount; i++) {
		ch = (char *)malloc(sizeof(char)*MAX_TERMS);
		fgets(ch, MAX_TERMS, fp);
		temp[i] = ch;
		printf("%s", ch);
	}
	printf("\n");

	for (int i = 0; i < nCount; i++) {
		if (i == nCount - 1) {
			if (last_line_check_matching(temp[i])) {
				printf("Success : %s\n", temp[i]);
			}
			else
				printf("false : %s\n", temp[i]);
			break;
		}
		if (check_matching(temp[i])) {
			printf("Success : %s\n", temp[i]);
		}
		else
			printf("false : %s \n", temp[i]);
	}

	for (int i = 0; i < nCount; i++) //���� �޸� �Ҵ� ����
		free(temp[i]);
	fclose(fp); // ���� �ݱ�
}
*/