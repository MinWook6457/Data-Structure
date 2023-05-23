/*
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct DListNode {
	int data;
	struct DListNode *llink;
	struct DListNode *rlink;
}DListNode;

void init(DListNode *phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode *phead) {
	DListNode *p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
void print_dlist2(DListNode *phead) {
	DListNode *p;
	for (p = phead->llink; p != phead; p = p->llink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
void dinsert(DListNode *before, int data) {
	DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
	newNode->data = data;
	newNode->llink = before;
	newNode->rlink = before->rlink;
	before->rlink->llink = newNode;
	before->rlink = newNode;

}

void ddelete(DListNode *head, DListNode *removed) {
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
DListNode* search(DListNode *L, int data) {
	DListNode *p;
	for (p = L->rlink;p != L;p = p->rlink) {
		if (p->data == data)
			return p;
	}
	return NULL;
}
void main() {
	DListNode *head = (DListNode *)malloc(sizeof(DListNode));
	init(head);
	FILE *fp;
	fp = fopen("Link1.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "���� ���� ����\n");
	}
	int x;
	int count = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d", &x);
		dinsert(head, x);
		count++;
	}
	print_dlist(head);
	printf("\n");
	print_dlist2(head);
	DListNode *temp = (DListNode *)malloc(sizeof(DListNode));
	init(temp);
	temp = search(head, 30);
	printf("Ž���� �� : %d\n", temp->data);
	print_dlist(head);


	int nCount, value;
	printf("�������� ������ �Է��Ͻÿ� : ");
	scanf("%d", &nCount);
	printf("\n");
	for (int i = 0; i < nCount; i++) {
		printf("%d ��� �� ������ �Է�", i + 1);
		scanf("%d", &value);
		dinsert(head, value);
	}
	print_dlist(head);
	free(head);
}*/