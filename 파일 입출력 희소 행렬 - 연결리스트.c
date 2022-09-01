
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)

typedef struct Node {
	int row;
	int col;
	int data;
	struct Node *link;
}Node;
void insert(Node** head, Node** p, int data, int row, int col) { // 노드 리스트 생성 함수 (머리노드, 선행노드, 데이터, 행, 열)
	Node* NewNode = (Node*)malloc(sizeof(Node)); // NewNode 생성
	NewNode->link = NULL; // 초기화
	NewNode->data = data; // NewNode 데이터 입력
	NewNode->row = row; // NewNode 행 입력
	NewNode->col = col; // NewNode 열 입력
	if (*head == NULL) { // 첫 노드를 만드는 경우
		*head = NewNode; // 머리 노드와 첫 노드를 연결
		*p = NewNode; // 선행 노드 포인터가 NewNode를 가리킴
	}
	else {
		(*p)->link = NewNode; // 선행 노드가 NewNode를 가리킴
		*p = NewNode; // 선행 노드 포인터가 NewNode를 가리킴
	}
}
void print_list(Node *head, int cnt) {
	Node *p = head;
	printf("행\t열\t데이터\n");
	for (int i = 0; i < cnt; i++) {
		printf("%d\t%d\t%d\n", p->row, p->col, p->data);
		p = p->link;
	}
}
void free_matrix(int **s) { // msize 함수를 이용하여 동적할당한 배열의 크기를 구할 수 있음!!
	int count = _msize((int**)s) / sizeof(int);
	for (int i = 0; i < count; i++) {
		free(s[i]);
	}
	printf("메모리 해제 완료\n");
}
void main() {
	int **matrix = NULL;
	Node *head = NULL;
	Node *pre = NULL;
	int nTemp;
	char chTemp = '0';
	int nCount = 0; // 행개수 구하기
	int nCol = 0; // 열개수 구하기
	FILE *fp = fopen("sparseMatrix.txt", "r");
	if (fp == NULL) {
		printf("파일을 읽을 수 없습니다.\n");
		exit(1);
	}

	//행의 개수를 구한다.
	while (!feof(fp)) {
		if (chTemp == '\n')
			break;
		fscanf(fp, "%d%c", &nTemp, &chTemp);
		nCount++;
	}
	rewind(fp);
	matrix = (int **)malloc(sizeof(int *)*nCount);
	
	for (int i = 0; i < nCount; i++) {
		matrix[i] = (int*)malloc(sizeof(int)*nCount);
		nCol++;
	}
	printf("원본 행렬 출력\n");
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < nCol; j++) {
			fscanf(fp, "%d", &matrix[i][j]);
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	int cnt = 0;
	for (int i = 0; i < nCount; i++) { // nCount = nRow : 행
		for (int j = 0; j < nCol; j++) { // 열
			if (matrix[i][j] != 0) { // 0이 아닌 값을 temp 대입
				int temp = matrix[i][j]; 
				insert(&head,&pre,temp,i, j);
				cnt++; //  0이 아닌 값들의 개수+
			}
		}
	}

	print_list(head,cnt);
	free_matrix(matrix);

}