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
// phead : 헤드포인터
// p : 선행 노드(pre)
// new_node : 추가할 노드
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
	// 공백 리트스인 경우
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	// 첫 번째 노드로 추가하는 경우
	else if (p == NULL) {
		new_node->link = *phead; // 순서 매우 중요!! 새로운 노드 링크부터 설정
		*phead = new_node;
	}
	//주어진 위치에 추가하는 경우 p(pre) 다음에 new_node 추가
	else {
		new_node->link = p->link;
		p->link = new_node;
	}

}
// phead : 헤드포인터
// p : 선행 노드(pre)
// removed : 삭제할 노드
void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {

}
// pos 위치의 노드 포인터를 찾아서 리턴
ListNode *get_node_at(ListType *list, int pos) {
	ListNode *tmp_node = list->head;
	//방어 코드
	if (pos < 0)
		return NULL;
	
	for (int i = 0; i < pos; i++)
		tmp_node = tmp_node->link; // 검색, 출력 (자기 자신 참조하면서 링크 연결)

	return tmp_node;
}
// 연결리스트의 노드 개수를 리턴
int get_length(ListType *list) {
	return list->length;
}
// list 연결리시트의 position 위치에 data를 추가
void add(ListType *list, int position, int data) {
	ListNode *p; // previous
	// position 값의 유효성 검사
	if (position <= list->length && position >= 0) { //방어코드
		ListNode * node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL) {
			fprintf(stderr, "메모리 할당 실패\n");
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
// list 연결리시트의 position 위치에 있는 데이터 삭제
void delete(ListType *list, int position) {

}
//연결리스트가 비어있는지 확인
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
	printf("리스트 출력: ");
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
// pos위치의 노드 값을 읽어서 리턴
int get_entry(ListType *list, int pos) {

}
void main() {
	ListType *list;
	FILE *fp;
	init(&list);
	int temp;
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 오픈 실패");
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