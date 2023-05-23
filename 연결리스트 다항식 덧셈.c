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
		fprintf(stderr, "���� �Ҵ� ����\n");
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
	temp->link = plist->head; // ����� ��ũ�� ���Ḯ��Ʈ ����� �Ӹ������ ���� ����Ŵ
	plist->head = temp; // ����� �Ӹ���尡 �Էµ� ���� ����Ʈ ��带 ����Ű������
}
void sorted_List(ListType *L, int coef, int expon) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode)); // ���ο� ��� ����
	 // ������ ��� �ʱ�ȭ
	newNode->coef = coef;
	newNode->expon = expon;
	newNode->link = NULL;

	ListNode *cur, *next; // ���� �����ϱ� ���ؼ��� �ΰ��� ��尡 �ʿ���
	if (L->tail == NULL) { // ��� ����� tail ���� NULL�� ���� ����Ʈ�� ���� �������� �ʴ� ���� 
		L->head = L->tail = newNode;
	}
	else {
		if (newNode->expon < L->head->expon) { 
			insert_first(L, newNode); 
		}
		else if (newNode->expon > L->tail->expon) { 
			insert_last(L, coef, expon);
		}
		else { // �߰��� �����ϴ� ���
			// �ݺ��� ���� : cur ���� ����� �Ӹ� ��带 ����Ű�� next���� cur ����� link�� ����Ŵ���ν� �ݺ��� �� ������ next��尡 cur��带 ���󰣴�.
			for (cur = L->head, next = cur->link; next != NULL; cur = cur->link, next = next->link) { // ��带 �Űܰ��� �˻�
				//cur ��尡 ����Ű�� ������ ���� ���� ����� �������� ũ�� ���� ���� ����� ������ cur �����͸� ���󰡴� next �����Ͱ� ����Ű�� �������� ũ�ٸ�
				if (cur->expon > newNode->expon && newNode->expon > next->expon) {
					newNode->link = next; // newNode�� ��ũ�� next�� ����Ŵ
					cur->link = newNode; // ���� ����� link�� newNode�� ����Ű���� ��
				}
			}
		}
	}
	L->size++; // ��� ��� ������ ����
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
		fprintf(stderr, "���� ���� ����\n");
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
	printf("���� ���� : ");
	poly_print(head4);
	free(head1); free(head2); free(head3);
}*/