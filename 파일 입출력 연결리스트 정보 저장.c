/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
	char name[100];
	int age;
	double heigh;
	struct Node *link;
}Node;
typedef struct ListType {
	Node *head;
	Node *tail;
}ListType;
ListType* create() {
	ListType *plist = (ListType*)malloc(sizeof(ListType));
	plist->head = plist->tail = NULL;
	return plist;
}
void insert_last(ListType* plist, char *name, int age, double heigh) { // ��� ����Ʈ ���� �Լ� (�Ӹ����, ������, ������, ��, ��)
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
	}

	temp->age = age;
	temp->heigh = heigh;
	strcpy(temp->name, name);
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
}
void print_list(ListType *plist) {
	Node *p = plist->head;
	for (;p != NULL;p = p->link)
		printf("%s\t%d\t%.1lf\n", p->name, p->age, p->heigh);
}
void main() {
	ListType *list = NULL;

	list = create();
	FILE *fp;
	fp = fopen("info.txt", "r");

	if (fp == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	char buffer[100];
	int age;
	double heigh;
	while (!feof(fp)) {
		fscanf(fp, "%s%d%lf", buffer, &age, &heigh);
		insert_last(list, buffer, age, heigh);
	}
	print_list(list);
}*/