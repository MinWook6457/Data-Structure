
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_SIZE 5
typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;
typedef struct QueueType {
	element data[MAX_SIZE];
	int front, rear;
}QueueType;
void init(QueueType *q) {
	q->rear = q->front = 0;
}
int is_empty(QueueType *q) {
	return q->front == q->rear;
}
int is_full(QueueType *q) {
	return (q->rear + 1) % MAX_SIZE == q->front;
}
void print(QueueType *q) {
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_SIZE;
			printf("%d", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
}
void enqueue(QueueType *q, element value) {
	if (is_full(q))
		printf("ť�� ��ȭ���� �Դϴ�.\n");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = value;
}
element dequeue(QueueType *q) {
	if (is_empty(q))
		printf("ť�� ������� �Դϴ�.\n");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}
void main() {
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;

	QueueType q;
	init(&q);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("���� �ð� : %d\n", clock);
		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&q, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. ���� ó���ð� = %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) {
			printf("�� %d�� ���� ó�����Դϴ�.\n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&q)) {
				element customer = dequeue(&q);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("��ü ��� �ð� = %d��\n", total_wait);
}