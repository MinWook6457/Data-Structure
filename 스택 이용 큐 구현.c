/*
#include<stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct Stacktype {
	int stack[MAX_SIZE];
	int top;
}Stacktype;

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, int item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

int Stack_pop(Stacktype* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

typedef struct Queuetype {
	Stacktype s1, s2;
};

void Queue_init(Queuetype* q) {
	q->s1.top = -1;
	q->s2.top = -1;
}

void Queue_push(Queuetype* q, int item) {
	Stack_push(&(q->s1), item);
	return;
}

int Queue_pop(Queuetype* q) {
	if (is_empty(&(q->s2))) {
		while (!is_empty(&(q->s1))) {
			Stack_push(&(q->s2), Stack_pop(&(q->s1)));
		}
	}
	return 	Stack_pop(&(q->s2));;
}

int main(void) {
	Queuetype q;
	Queue_init(&q);
	Queue_push(&q, 5);
	Queue_push(&q, 4);
	Queue_push(&q, 3);
	printf("%d\n", Queue_pop(&q));
	printf("%d\n", Queue_pop(&q));
	printf("%d\n", Queue_pop(&q));
}*/