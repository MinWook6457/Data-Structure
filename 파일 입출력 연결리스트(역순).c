/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)
typedef int element;
typedef struct Node {
	element data;
	struct Node *link;
}Node;
Node* insert_first(Node *head, element value) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
void print_List(Node *head) {
	for (Node *p = head; p != NULL;p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}
Node* reverse(Node *head) {
	Node *p, *q, *r;
	p = head; // 역순으로 만들 리스트
	q = NULL; // 역순으로 만들 노드

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}
void main() {
	Node *head = NULL;
	Node *reverseList = NULL;
	element x;
	FILE *fp;
	fp = fopen("link1.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &x);
		head = insert_first(head, x);
	}
	print_List(head);
	reverseList = reverse(head);
	print_List(reverseList);

	fclose(fp);

}*/