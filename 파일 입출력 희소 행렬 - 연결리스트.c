
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
void insert(Node** head, Node** p, int data, int row, int col) { // ��� ����Ʈ ���� �Լ� (�Ӹ����, ������, ������, ��, ��)
	Node* NewNode = (Node*)malloc(sizeof(Node)); // NewNode ����
	NewNode->link = NULL; // �ʱ�ȭ
	NewNode->data = data; // NewNode ������ �Է�
	NewNode->row = row; // NewNode �� �Է�
	NewNode->col = col; // NewNode �� �Է�
	if (*head == NULL) { // ù ��带 ����� ���
		*head = NewNode; // �Ӹ� ���� ù ��带 ����
		*p = NewNode; // ���� ��� �����Ͱ� NewNode�� ����Ŵ
	}
	else {
		(*p)->link = NewNode; // ���� ��尡 NewNode�� ����Ŵ
		*p = NewNode; // ���� ��� �����Ͱ� NewNode�� ����Ŵ
	}
}
void print_list(Node *head, int cnt) {
	Node *p = head;
	printf("��\t��\t������\n");
	for (int i = 0; i < cnt; i++) {
		printf("%d\t%d\t%d\n", p->row, p->col, p->data);
		p = p->link;
	}
}
void free_matrix(int **s) { // msize �Լ��� �̿��Ͽ� �����Ҵ��� �迭�� ũ�⸦ ���� �� ����!!
	int count = _msize((int**)s) / sizeof(int);
	for (int i = 0; i < count; i++) {
		free(s[i]);
	}
	printf("�޸� ���� �Ϸ�\n");
}
void main() {
	int **matrix = NULL;
	Node *head = NULL;
	Node *pre = NULL;
	int nTemp;
	char chTemp = '0';
	int nCount = 0; // �ళ�� ���ϱ�
	int nCol = 0; // ������ ���ϱ�
	FILE *fp = fopen("sparseMatrix.txt", "r");
	if (fp == NULL) {
		printf("������ ���� �� �����ϴ�.\n");
		exit(1);
	}

	//���� ������ ���Ѵ�.
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
	printf("���� ��� ���\n");
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < nCol; j++) {
			fscanf(fp, "%d", &matrix[i][j]);
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	int cnt = 0;
	for (int i = 0; i < nCount; i++) { // nCount = nRow : ��
		for (int j = 0; j < nCol; j++) { // ��
			if (matrix[i][j] != 0) { // 0�� �ƴ� ���� temp ����
				int temp = matrix[i][j]; 
				insert(&head,&pre,temp,i, j);
				cnt++; //  0�� �ƴ� ������ ����+
			}
		}
	}

	print_list(head,cnt);
	free_matrix(matrix);

}