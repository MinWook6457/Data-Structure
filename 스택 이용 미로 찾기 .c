/*
#include<stdio.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	int r, c;
}element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

bool is_empty(StackType* s) {
	return s->top == -1;
}

element pop(StackType* s) {
	element t = s->stack[s->top];
	s->stack[s->top].r = 0;
	s->stack[s->top].c = 0;
	s->top--;
	return t;
}

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','0','0','1','1'},
	{'1','1','0','1','1','1'},
	{'1','1','0','1','1','1'},
	{'1','0','0','0','0','x'},
	{'1','1','1','1','1','1'},
};

void push(StackType* s, int row, int column) {
	if (row < 0 || row >= MAZE_SIZE || column < 0 || column >= MAZE_SIZE)
		return;
	if (maze[row][column] == '0' || maze[row][column] == 'x') {
		s->stack[++(s->top)].r = row;
		s->stack[(s->top)].c = column;
	}
	return;
}

int main(void) {
	StackType s;
	init_stack(&s);
	element road[MAX_STACK_SIZE];
	element here = { 1,0 };
	int i = 0, r, c;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.'; // �����±�
		road[i].r = r; // ��� ����
		road[i++].c = c;
		push(&s, r + 1, c);
		push(&s, r, c + 1);
		push(&s, r - 1, c);
		push(&s, r, c - 1);

		if (is_empty(&s)) {
			printf("����\n");
			return 0;
		}
		else
			here = pop(&s);

	}
	for (int k = 0; k < i; k++)
		printf("��� : %d %d \n", road[k].r, road[k].c);

	return 0;
}*/
