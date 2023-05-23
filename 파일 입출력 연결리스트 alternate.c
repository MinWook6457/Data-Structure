/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)

typedef struct ListNode {
	int data;
	struct ListNode *link;	
}ListNode;

ListNode* insert_first(ListNode *head, int item) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}
// 시간 복잡도는 연결리스트 A, B의 크기를 a, b라고 한다면 O(a + b) 가 된다.
ListNode* alternate(ListNode* A, ListNode* B) {
	ListNode* p = A, *q = B, *C = NULL;
	while (p != NULL || q != NULL) {
		if (p != NULL) {
			C = insert_first(C, p->data);
			p = p->link;
		}
		if (q != NULL) {
			C = insert_first(C, q->data);
			q = q->link;
		}
	}
	return C;
}

ListNode* merge(ListNode* A, ListNode* B) {
	ListNode* p = A, *q = B, *C = NULL;
	while (p != NULL || q != NULL) {
		if (p != NULL) {
			C = insert_first(C, p->data);
			p = p->link;
		}
		if (q != NULL) {
			C = insert_first(C, q->data);
			q = q->link;
		}
	}
	while (p != NULL) {
		C = insert_first(C, p->data);
		p = p->link;
	}
	while (q != NULL) {
		C = insert_first(C, q->data);
		q = q->link;
	}
	return C;
}
void split(ListNode *head, ListNode **A, ListNode **B) {
	ListNode *p = head;
	while (p != NULL) {
		*A = insert_first(*A, p->data);
		if (p->link == NULL) 
			break;
		p = p->link;
		if (p->link == NULL) 
			break;
		*B = insert_first(*B, p->data);
		p = p->link;
	}
}
void print_list(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
void main() {
	ListNode *head = NULL;
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	FILE *fp;
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}
	int x;
	while (!feof(fp)) {
		fscanf(fp, "%d", &x);
		head = insert_first(head, x);
		head1 = insert_first(head1, x);
	}
	
	print_list(head);
	head2 = alternate(head, head1);
	print_list(head2);

	ListNode *link = NULL;
	ListNode *link1 = NULL;
	ListNode *link2 = NULL;

	FILE *fp1;
	fp1 = fopen("link1.txt", "r");

	if (fp1 == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}
	int data;
	while (!feof(fp1)) {
		fscanf(fp1, "%d", &data);
		link1 = insert_first(link1, data);
	}
	print_list(link1);

	FILE *fp2;
	fp2 = fopen("link2.txt", "r");

	if (fp2 == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}
	int data2;
	while (!feof(fp2)) {
		fscanf(fp2, "%d", &data2);
		link2 = insert_first(link2, data2);
	}
	print_list(link2);
	link = merge(link1, link2);
	print_list(link);
	head = alternate(link1, link2);
	printf("alternate : ");
	print_list(head);
	ListNode *A = NULL;
	ListNode *B = NULL;
	split(head, &A, &B);
	print_list(A);
	print_list(B);
}*/