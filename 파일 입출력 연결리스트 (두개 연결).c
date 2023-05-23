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
Node* concat_List(Node *head1, Node *head2) {
	if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	}
	else {
		Node *p;
		p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1; // 새로 연결된 리스트의 맨 앞 주소 반환
	}
	
}
void main() {
	Node *head1 = NULL;
	Node *head2 = NULL;
	element x1,x2;
	FILE *fp1, *fp2;
	fp1 = fopen("link1.txt", "r");
	if (fp1 == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}
	while (!feof(fp1)) {
		fscanf(fp1, "%d", &x1);
		head1 = insert_first(head1, x1);
	}

	fp2 = fopen("link2.txt", "r");
	if (fp2 == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}
	while (!feof(fp2)) {
		fscanf(fp2, "%d", &x2);
		head2 = insert_first(head2, x2);
	}
	Node *total = concat_List(head1, head2);
	print_List(total);

	fclose(fp1);
	fclose(fp2);
}*/