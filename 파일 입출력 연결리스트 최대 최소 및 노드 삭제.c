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

int max_list(ListNode *head) {
	ListNode *p = head;
	int max;
	max = p->data;
	while (p != NULL) {
		if (max < p->data)
			max = p->data;
		p = p->link;
	}

	return max;
}

int min_list(ListNode *head) {
	ListNode *p = head;
	int min;
	min = p->data;
	while (p != NULL) {
		if (min > p->data)
			min = p->data;
		p = p->link;
	}

	return min;
}
void print_list(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
void remove_odd_list(ListNode** head) {
	*head = (*head)->link;
	ListNode* p = NULL, *removed = *head;
	while (removed->link != NULL) {
		p = removed;
		removed = removed->link;
		p->link = removed->link;
		if (removed->link != NULL)
			removed = removed->link;
		else
			break;
	}
	return;
}
void main() {
	ListNode *head = NULL;

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
	}
	printf("최대값 : %d 최소값 %d\n", max_list(head), min_list(head));
	print_list(head);
	remove_odd_list(&head);
	print_list(head);
}*/