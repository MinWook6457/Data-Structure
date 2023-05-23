/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct DListNode {
	char name[100];
	int num;
	int scores[3];
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void addStudent(DListNode* head) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	printf("�߰��� �л� ��ȣ: ");
	scanf("%d", &newnode->num);
	printf("�̸�: ");
	scanf("%s", newnode->name);
	printf("���� ����: ");
	scanf("%d", &newnode->scores[0]);
	printf("���� ����: ");
	scanf("%d", &newnode->scores[1]);
	printf("���� ����: ");
	scanf("%d", &newnode->scores[2]);

	newnode->llink = head;
	newnode->rlink = head->rlink;
	head->rlink->llink = newnode;
	head->rlink = newnode;
}

void deleteStudent(DListNode* head) {
	int num;
	DListNode* p;
	printf("������ �л� ��ȣ: ");
	scanf("%d", &num);

	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->num == num) {
			p->llink->rlink = p->rlink;
			p->rlink->llink = p->llink;
			free(p);
			printf("���� �Ϸ�\n");
			return;
		}
	}
	printf("ã�� �л��� �����ϴ�.\n");
}

void findStudent(DListNode* head) {
	int num;
	DListNode* p;
	printf("�˻��� �л� ��ȣ: ");
	scanf("%d", &num);

	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->num == num) {
			printf("�л� ��ȣ : %d\n", p->num);
			printf("�л� �̸� : %s\n", p->name);
			printf("���� ���� : %d\n", p->scores[0]);
			printf("���� ���� : %d\n", p->scores[1]);
			printf("���� ���� : %d\n", p->scores[2]);

			return;
		}
	}
	printf("ã�� �л��� �����ϴ�.\n");
}

void printStudent(DListNode* head) {
	DListNode* p;
	printf("��ȣ\t�̸� ���� ���� ���� ������ -1�� ���� ���Է�\n");
	for (p = head->llink; p != head; p = p->llink) {
		printf("%d\t%s %d %d %d\n", p->num, p->name, p->scores[0], p->scores[1], p->scores[2]);
	}
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	int n, num, korean, english, math;

	char name[10];
	init(head);

	do {
		printf("���� ���� ���α׷� \n");
		printf("0:���� 1: �л� ������ �Է� 2: �л� ������ ���� 3: �л� �˻� 4: ��� ����\n");
		scanf("%d", &n);

		switch (n) {
		case 1:
			addStudent(head);
			break;
		case 2:
			deleteStudent(head);
			break;
		case 3:
			findStudent(head);
			break;
		case 4:
			printStudent(head);
			break;
		default:
			if (n != 0) {
				printf("��ɾ �߸��ƽ��ϴ�.\n");
			}
			break;
		}
	} while (n != 0);
	printf("���α׷� ����");
	free(head);
	return 0;
}*/