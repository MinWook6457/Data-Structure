/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode *link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;

ListType* create() {
	ListType *plist = (ListType*)malloc(sizeof(ListType));
	plist->head = plist->tail = NULL;
	plist->size = 0;
	return plist;
}

void insert_last(ListType *plist, int coef, int expon) {
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));

	if (temp == NULL) {
		fprintf(stderr, "동적 할당 오류\n");
		exit(1);
	}

	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}
void insert_first(ListType*plist, ListNode* temp) {
	temp->link = plist->head; // 노드의 링크가 연결리스트 헤더의 머리노드의 값을 가리킴
	plist->head = temp; // 헤더의 머리노드가 입력된 연결 리스트 노드를 가리키도록함
}
void sorted_List(ListType *L, int coef, int expon) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드 생성
	 // 생성된 노드 초기화
	newNode->coef = coef;
	newNode->expon = expon;
	newNode->link = NULL;

	ListNode *cur, *next; // 값을 삽입하기 위해서는 두개의 노드가 필요함
	if (L->tail == NULL) { // 헤더 노드의 tail 값이 NULL인 것은 리스트에 값이 존재하지 않는 것임 
		L->head = L->tail = newNode;
	}
	else {
		if (newNode->expon < L->head->expon) { 
			insert_first(L, newNode); 
		}
		else if (newNode->expon > L->tail->expon) { 
			insert_last(L, coef, expon);
		}
		else { // 중간에 삽입하는 경우
			// 반복문 설명 : cur 노드는 헤더의 머리 노드를 가리키고 next노드는 cur 노드의 link를 가리킴으로써 반복이 될 때마다 next노드가 cur노드를 따라간다.
			for (cur = L->head, next = cur->link; next != NULL; cur = cur->link, next = next->link) { // 노드를 옮겨가며 검사
				//cur 노드가 가리키는 차수가 새로 생긴 노드의 차수보다 크고 새로 생긴 노드의 차수가 cur 포인터를 따라가는 next 포인터가 가리키는 차수보다 크다면
				if (cur->expon > newNode->expon && newNode->expon > next->expon) {
					newNode->link = next; // newNode의 링크가 next를 가리킴
					cur->link = newNode; // 현재 노드의 link가 newNode를 가리키도록 함
				}
			}
		}
	}
	L->size++; // 헤더 노드 사이즈 증가
}
void poly_add(ListType *plist1, ListType *plist2, ListType *plist3) {
	ListNode *a = plist1->head;
	ListNode *b = plist2->head;
	int sum = 0;
	while (a&&b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) {
				insert_last(plist3, sum, a->expon);
				a = a->link;
				b = b->link;
				}
			}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	for (; a != NULL ; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL ; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType *plist) {
	ListNode *p = plist->head;
	for (;p;p = p->link) {
		printf("%dx^%d + ", p->coef, p->expon);
	}
	printf("\n");
}
void poly_eval(ListType *plist, int x) {
	
	ListNode *p = plist->head;
	int result = 0;
	int sum = 1;
	while (p != NULL) {
		if (p->expon > 1) {
			sum = (int)pow(x,p->expon);
			if (p->expon != 1)
				sum *= p->coef;
		}
		else if (p->expon == 1)
			sum = x * (p->coef);
		else if(p->expon == 0)
			sum = p->coef;
		result += sum;
		sum = 1;
		p = p->link;
	}
	printf("%d\n", result);
}
void main() {
	ListType *head1;
	ListType *head2;
	ListType *head3;
	ListType *head4;
	head1 = create();
	head2 = create();
	head3 = create();
	head4 = create();
	FILE *fp;
	fp = fopen("polyAdd.txt", "r");

	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}

	int x, y;
	int ch;
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y);
		insert_last(head1, x, y);
		ch = fgetc(fp);
		if (ch == '\n')
			break;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y);
		insert_last(head2, x, y);
		ch = fgetc(fp);
		if (ch == '\n')
			break;
	}
	rewind(fp);
	poly_print(head1);
	poly_print(head2);
	poly_add(head1, head2, head3);
	poly_print(head3);
	poly_eval(head1, 2);
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y);
		sorted_List(head4, x, y);
		ch = fgetc(fp);
		if (ch == '\n')
			break;
	}
	printf("오름 차순 : ");
	poly_print(head4);
	free(head1); free(head2); free(head3);
}*/