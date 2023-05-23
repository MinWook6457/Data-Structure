/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 5
typedef struct {
	int data[MAX_QUEUE];
	int front, rear;
}DequeType;

void init_queue(DequeType *q) {
	q->front = q->rear = 0;
}

int is_empty(DequeType *q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int is_full(DequeType *q) {
	if (q->front == (q->rear + 1) % MAX_QUEUE)
		return 1;
	else
		return 0;
}

void deque_print(DequeType *q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i!=q->front);
	}
	printf("\n");
}

void add_rear(DequeType *q,int item) {
	if (is_full(q)) {
		printf("큐가 포화상태 입니다.");
	}

	q->rear = (q->rear + 1) % MAX_QUEUE;
	q->data[q->rear] = item;
}

int delete_front(DequeType *q) {
	int item;

	if (is_empty(q)) {
		printf("큐가 공백상태 입니다.\n");
	}

	q->front = (q->front + 1) % MAX_QUEUE;
	item = q->data[q->front];
	return item;
}

void add_front(DequeType *q, int value) {
	if (is_full(q)) {
		printf("큐가 포화상태 입니다.\n");
	}
	q->data[q->front] = value;
	q->front = (q->front - 1 + MAX_QUEUE ) % MAX_QUEUE;
}

int delete_rear(DequeType *q) {
	int del = q->rear; // 인덱스 저장
	if (is_empty(q)) {
		printf("큐가 공백상태 입니다.\n");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE ) % MAX_QUEUE; // 인덱스 감소
	return q->data[del];
}

void main() {
	DequeType q;

	init_queue(&q);

	for (int i = 0; i < 3; i++) {
		add_front(&q, i);
		deque_print(&q);
	}

	for (int i = 0; i < 3; i++) {
		delete_rear(&q);
		deque_print(&q);
	}
}*/