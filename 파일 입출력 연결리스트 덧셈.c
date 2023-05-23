/*
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode *link;
}ListNode;
typedef struct ListType {
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;

ListType* create() {
	ListType* plist = (ListType *)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType *plist, int coef, int expon) {
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(ListType *A, ListType *B, ListType *C) {
	ListNode *a = A->head;
	ListNode *b = B->head;

	int sum = 0;
	while (a&&b) {
		if (a->expon == b->expon) {
			sum += a->coef + b->coef;
			if (sum != 0)
				insert_last(C, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_last(C, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(C, b->coef,b->expon);
			b = b->link;
		}
	}

	for (;a != NULL;a = a->link) {
		insert_last(C, a->coef, a->expon);
	}
	for (;b != NULL;b = b->link) {
		insert_last(C, b->coef, b->expon);
	}
}

void poly_print(ListType *plist) {
	ListNode *p = plist->head;
	while (p != NULL) {
		printf("%d^%d + ", p->coef, p->expon);
		p = p->link;
	}
	printf("\n");
}
void main() {
	ListType *A = NULL;
	ListType *B = NULL;
	ListType *C = NULL;

	A = create();
	B = create();
	C = create();

	FILE *fp;
	fp = fopen("polyAdd.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
	}

	int x, y;
	int c;
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y);
		insert_last(A, x, y);
		c = fgetc(fp);
		if (c == '\n')
			break;
	}

	poly_print(A);

	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y);
		insert_last(B, x, y);
		c = fgetc(fp);
		if (c == '\n')
			break;
	}

	poly_print(B);
	poly_add(A, B, C);
	poly_print(C);
}*/