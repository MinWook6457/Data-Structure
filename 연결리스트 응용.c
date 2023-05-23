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
	printf("연결리스트를 이용한 영화관리 메뉴\n");
	while (1) {
		char buffer[SIZE];
		print_menu();
		int year;
		int menu;
		scanf("%d", &menu);
		if (menu == 1) {
			printf("영화 제목을 입력하시오 : ");
			scanf("%s", buffer);

			p = (NODE *)malloc(sizeof(NODE));
			strcpy(p->title, buffer);

			printf("영화의 개봉 연도를 입력하시오 : ");
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
	printf("1. 영화 정보 추가\n");
	printf("2. 영화 정보 출력\n");
	printf("3. 종료\n");
	printf("-----------------------------\n");
}*/