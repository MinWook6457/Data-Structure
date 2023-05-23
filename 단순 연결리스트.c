/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)
typedef struct ListNode{
	int data;
	struct Node *link;
}ListNode;
typedef struct {
	ListNode * head;
	int length;
}ListType;
void init(ListType *list) {
	list->head = NULL;
	list->length = 0;
}
// phead : ���������
// p : ���� ���(pre)
// new_node : �߰��� ���
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
	// ���� ��Ʈ���� ���
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	// ù ��° ���� �߰��ϴ� ���
	else if (p == NULL) {
		new_node->link = *phead; // ���� �ſ� �߿�!! ���ο� ��� ��ũ���� ����
		*phead = new_node;
	}
	//�־��� ��ġ�� �߰��ϴ� ��� p(pre) ������ new_node �߰�
	else {
		new_node->link = p->link;
		p->link = new_node;
	}

}
// phead : ���������
// p : ���� ���(pre)
// removed : ������ ���
void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {

}
// pos ��ġ�� ��� �����͸� ã�Ƽ� ����
ListNode *get_node_at(ListType *list, int pos) {
	ListNode *tmp_node = list->head;
	//��� �ڵ�
	if (pos < 0)
		return NULL;
	
	for (int i = 0; i < pos; i++)
		tmp_node = tmp_node->link; // �˻�, ��� (�ڱ� �ڽ� �����ϸ鼭 ��ũ ����)

	return tmp_node;
}
// ���Ḯ��Ʈ�� ��� ������ ����
int get_length(ListType *list) {
	return list->length;
}
// list ���Ḯ��Ʈ�� position ��ġ�� data�� �߰�
void add(ListType *list, int position, int data) {
	ListNode *p; // previous
	// position ���� ��ȿ�� �˻�
	if (position <= list->length && position >= 0) { //����ڵ�
		ListNode * node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL) {
			fprintf(stderr, "�޸� �Ҵ� ����\n");
			return;
		}
		node->data = data;
		p = get_node_at(list, position-1);

		insert_node(&(list->head), p, node);
		list->length++;
	}

}

void add_last(ListType *list, int data) {
	add(list, get_length(list), data);
}

void add_first(ListType *list, int data) {
	add(list, 0, data);
}
// list ���Ḯ��Ʈ�� position ��ġ�� �ִ� ������ ����
void delete(ListType *list, int position) {

}
//���Ḯ��Ʈ�� ����ִ��� Ȯ��
int is_empty(ListType *list) {
	if (list->head->link == NULL)
		return 0;
	else
		return 1;
}
// tmp_node = tmp_node->link;
void display(ListType *list) {
	ListNode *temp;
	temp = list->head->link;
	printf("����Ʈ ���: ");
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->link;
	}

}

void clear(ListType *list) {
	while (list->head!=NULL) {

	}
}

int is_in_list(ListType *list, int item) {

}
// pos��ġ�� ��� ���� �о ����
int get_entry(ListType *list, int pos) {

}
void main() {
	ListType *list;
	FILE *fp;
	init(&list);
	int temp;
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "���� ���� ����");
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		add_last(&list, temp);
	}

	fclose(fp);
	display(&list);
	clear(&list);

}*/