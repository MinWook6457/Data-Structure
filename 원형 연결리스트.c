/*
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct ListNode {
	int data;
	struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode *head, int data) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
	}
	return head;
}

ListNode* insert_last(ListNode *head, int data) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;

	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}
ListNode* search(ListNode *head, int data) {
	ListNode *p = head;
	for (ListNode *p = head; p != NULL; p = p->link) {
		if (p->data == data) {
			return p;
		}
	}
	return NULL;
}

void print_list(ListNode *head) {
	ListNode *p;
	if (head == NULL)
		return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->NULL", p->data);
}
int get_size(ListNode* head) {
	ListNode* p = head;
	int count = 0;
	do {
		count++;
		p = p->link;
	} while (p != head);
	return count;
}
void main() {
	ListNode *head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	head = insert_first(head, 11);
	head = insert_last(head, 60);
	print_list(head);
	ListNode *q = search(head, 20);
	printf("\n%d", q->data);

	int size = get_size(head);
	printf("\n%d", size);
}*/