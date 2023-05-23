/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef int StackObject;
typedef struct StackRec {
	StackObject item;
	struct StackRec *link;
}StackRec;

void init(StackRec **top) {
	*top = NULL;
}

int is_empty(StackRec **top) {
	return *top == NULL;
}

int is_full(StackRec **top) {
	return 0;
}

void push(StackRec **top, StackObject item) {
	StackRec *temp = (StackRec *)malloc(sizeof(StackRec));

	if (temp == NULL) {
		printf("fail to push\n");
	}
	else {
		temp->item = item;
		temp->link = *top;
		*top = temp;
	}
}

StackObject pop(StackRec **top) {
	if (is_empty(top)) {
		printf("Stack is empty\n");
	}
	else {
		StackRec *temp = *top;
		int item = temp->item;
		*top = (*top)->link;
		free(temp);
		return item;
	}

}

StackObject peek(StackRec **top) {
	if (is_empty(top)) {
		printf("Stack is empty\n");
	}
	else {
		return (*top)->item;
	}
}
int prec(char op) { // 연산자 우선순위 반환
	// 우선순위 0이 가장 낮고 2가 가장 높다.
	switch (op)
	{
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	}
	return -1;
}
void infix_to_postfix(char exp[], char *inpost) {
	StackRec *s;
	char ch, top_op;
	int len = strlen(exp);
	init(&s); // 스택 초기화 까먹지 말것!
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		//연산자인지 확인
		switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				inpost[cnt++] = pop(&s);
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			inpost[cnt++] = top_op;
			top_op = pop(&s);
			break;
		default: // 피연산자
			inpost[cnt++] = ch;
			break;
		} // end of switch

	} // end of for
	// 스택에 남은 연산자 처리
	while (!is_empty(&s))
		inpost[cnt++] = pop(&s);
}
int eval(char *in) {
	int op1, op2, n, value;
	n = strlen(in);
	char ch;
	StackRec *s;
	init(&s);
	for (int i = 0; i < n; i++) {
		ch = in[i];
		if (ch != '+' && ch != '*' && ch != '-' && ch != '/' && ch != '%') {
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
			case '%': push(&s, op1 % op2); break;
			}

		}
	}
	return pop(&s);
}

void main() {
	char buf[1024] = { 0 };
	char *postpix[100];
	FILE *fp;
	fp = fopen("postfix.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}
	int result = 0;
	int count = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s", buf);
		count++;
	}
	rewind(fp);
	char buffer[1024] = { 0 };
	int *index = (int *)malloc(sizeof(int));
	for (int i = 0; i < count; i++) {
		fscanf(fp, "%s", buf); // 파일에서 문자열 한줄씩 받아오기
		postpix[i] = buf;
		printf("중위 표기식 : %s\n", postpix[i]);
		infix_to_postfix(postpix[i], buffer);
		printf("후위 표기식 : %s\n", buffer);
		printf("계산 결과 : %d\n", eval(buffer));
	}
}*/