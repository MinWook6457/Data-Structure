/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#pragma warning(disable:4996)
typedef struct {
	char words[100];
}element;
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
		printf("%s->", p->data.words);
	printf("NULL\n");
}
void main() {
	Node *head = NULL;
	element data;
	FILE *fp;
	fp = fopen("ListWords.txt", "r");
	char buf[100];
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}
	while (!feof(fp)) {
		fgets(buf, sizeof(buf), fp);
	}
	rewind(fp);
	char *ptr = strtok(buf, " ");
	while (ptr != NULL) {
		strcpy(data.words, ptr);
		head = insert_first(head, data);
		print_List(head);
		ptr = strtok(NULL, " ");
	}


	fclose(fp);

}*/