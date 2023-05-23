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
	Node* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL\n");
}
void remove_search_node(Node* head, element item) {
	Node* p = NULL, *removed = head;
	while (removed->data != item) { // �ݺ��� �����ٴ� �ǹ̴� ������ ���� ã�Ҵٴ� �ǹ��̴�.
		p = removed;
		removed = removed->link;
	}
	if (p == NULL) {// ���Ḯ��Ʈ�� ��尡 1�� ���̶��
		head = removed->link;
	}
	else {
		p->link = removed->link;
	}// �װ� �ƴ϶�� �̵�
	free(removed);
	
}
Node* search_List(Node *head, element value) {
	Node *p = head;
	while (p != NULL) {
		if (p->data == value)
			return p;
		p = p->link;
	}
	return NULL;
}
void main() {
	Node *head = NULL;
	element x;
	FILE *fp;
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &x);
		head = insert_first(head, x);
	}
	rewind(fp);
	print_List(head);
	remove_search_node(head, 123);
	print_List(head);
	fclose(fp);
}*/