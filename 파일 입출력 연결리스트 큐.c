/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)

typedef struct QueueNode {
	int data;
	struct QueueNode *link;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
}LinkedQueueType;

void init(LinkedQueueType *q) {
	q->front = q->rear = NULL;
}
int is_empty(LinkedQueueType *q) {
	if (q->front == NULL)
		return 1;
	else
		return 0;
}
void enqueue(LinkedQueueType *q, int data) {
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)==1) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

int dequeue(LinkedQueueType *q) {
	QueueNode *temp = q->front;

	int data;
	if (is_empty(q)) {
		fprintf(stderr, "큐가 공백상태 입니다.\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return data;
	}
}
void print_queue(LinkedQueueType *q) {
	
	for (QueueNode *p = q->front; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

void main() {
	LinkedQueueType q;
	init(&q);
	FILE *fp;

	fp = fopen("QueueLink.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);	
	}

	int data;
	int count = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
		enqueue(&q, data);
		count++;
	}
	print_queue(&q);

	for (int i = 0; i < count; i++) {
		printf("%d->", dequeue(&q));
	}
	fclose(fp);
}*/