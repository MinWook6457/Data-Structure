/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 100
#pragma warning(disable:4996)
void print_menu();
typedef struct NODE {
	char title[SIZE];
	int year;
	struct NODE *link;
}NODE;
int main() {
	NODE *list = NULL;
	NODE *prev=NULL, *p ,*next;
	printf("���Ḯ��Ʈ�� �̿��� ��ȭ���� �޴�\n");
	while (1) {
		char buffer[SIZE];
		print_menu();
		int year;
		int menu;
		scanf("%d", &menu);
		if (menu == 1) {
			printf("��ȭ ������ �Է��Ͻÿ� : ");
			scanf("%s", buffer);

			p = (NODE *)malloc(sizeof(NODE));
			strcpy(p->title, buffer);

			printf("��ȭ�� ���� ������ �Է��Ͻÿ� : ");
			scanf("%d", &year);
			p->year = year;
			if (list == NULL)
				list = p;
			else
				prev->link = p;
			p->link = NULL;
			prev = p;
		}
		else if (menu == 2) {
			p = list;
			while (p != NULL) {
				printf("[%s,%d]\n", p->title, p->year);
				p = p->link;
			}
		}
		else if (menu == 3) {
			p = list;
			while (p != NULL) {
				next = p->link;
				free(p);
				p = next;
			}
			return 0;
		}
	}
}
void print_menu() {
	printf("-----------------------------\n");
	printf("1. ��ȭ ���� �߰�\n");
	printf("2. ��ȭ ���� ���\n");
	printf("3. ����\n");
	printf("-----------------------------\n");
}*/