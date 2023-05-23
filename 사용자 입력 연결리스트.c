/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct Node {
	int data;
	struct Node *link;
}Node;

Node* insert_first(Node *head, int item) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}

void print_list(Node *head) {
	for (Node *p = head;p != NULL;p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

void delete_list(Node *head) {
	Node *target = head;
	Node *temp = target;
	while (target != NULL) {
		temp = temp->link;
		free(target);
		target = temp;
	}

}
int get_length(Node *head) {
	int count = 0;
	for (Node *p = head;p != NULL;p = p->link)
		count++;
	return count;
}

int sum_list(Node *head) {
	int sum = 0;
	for (Node *p = head;p != NULL;p = p->link)
		sum += p->data;
	return sum;
}

int *search_list(Node *head,int value) {
	int nCount = 0;
	for (Node *p = head;p != NULL;p = p->link) {
		if (p->data == value) {
			nCount++;
			
		}
	}
	return nCount;
}
void remove_element_node(Node** head, int item) {
	Node* p = NULL, *removed = *head;
	while (removed->data != item) {
		p = removed;
		removed = removed->link;
	}
	if (p == NULL)
		*head = (*head)->link;
	else
		p->link = removed->link;

	free(removed);
	printf("�����Ϸ�\n");
	return;
}
void main() {
	Node *head;
	Node *p = NULL, *prev = NULL;
	head = NULL;
	int x;
	int temp;
	printf("����� ���� : ");
	scanf("%d", &x);
	int sum = 0;

	for (int i = 0; i < x; i++) {
		printf("��� %d ������ : ", i);
		scanf("%d", &temp);
		head = insert_first(head, temp);
	}
	printf("������ ���� ����Ʈ : ");
	print_list(head);

	printf("\n");
	printf("���� ����Ʈ ����� ���� : %d", get_length(head));
	printf("\n");

	printf("���� ����Ʈ�� �� : %d\n", sum_list(head));
	int search;
	printf("Ž���� ���� �Է��Ͻÿ� : ");
	scanf("%d", &search);
	if (search_list(head, search) == -1) {
		printf("Ž���ϰ��� �ϴ� ���� �����ϴ�.\n");
	}
	else {
	printf("%d��(��) ���� ����Ʈ %d�� ��Ÿ���ϴ�.", search, search_list(head, search));
	}
	remove_element_node(&head,search);



	delete_list(head);
}*/