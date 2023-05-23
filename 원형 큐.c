
/* <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_QUEUE 5
typedef int element;
typedef struct {
	int rear;
	int front;
	element data[MAX_QUEUE];
}QueueType;

void init_queue(QueueType *q) {
	q->front = 0;
	q->rear = 0;
}

int is_empty(QueueType *q) {
	return (q->rear == q->front);
}

int is_full(QueueType *q) {
	return ((q->rear+1) % MAX_QUEUE ==  q->front);
}

void queue_print(QueueType *q) {
	printf("!Queue(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE;
			printf("%d|", q->data[i]);
			if (i == q->rear)
				break;

		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType *q, int item) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태 입니다.\n");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE;
	q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
	if (is_empty(q)) {
		fprintf(stderr,"큐가 공백상태입니다\n");
		return;
	}

	q->front = (q->front + 1) % MAX_QUEUE;
	return q->data[q->front];
}

element peek(QueueType *q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 공백상태입니다\n");
	}
	return q->data[(q->front+1)%MAX_QUEUE];
}

void main() {
	QueueType q;
	int value;

	init_queue(&q);

	while (!is_full(&q)) {
		printf("정수를 입력하시오: ");
		scanf("%d", &value);
		enqueue(&q, value);
		queue_print(&q);
	}

	printf("===데이터 삭제단계===\n");


	while (!is_empty(&q)) {
		value = dequeue(&q);
		printf("꺼내진 정수 : %d", value);
		queue_print(&q);
	}

}
*/