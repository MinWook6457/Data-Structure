/*
////////////////////////////////////////////////////////////////
//
// �ۼ��� : 20194024 ��ο�
// �ۼ��� : 2022�� 04�� 28��
// ���α׷��� : ����ü �����Ҵ�
// ���α׷����� : ����ü�� ����� �ڷ����� 
//				  �����Ҵ� �Ͽ� �޸� �Ҵ�
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void clearBuffer(void);
//å�� ������ �����ϴ� ����ü
typedef struct {
	char author[10];//����
	char name[30];//����
	int page;//������
}book;
int main(void) {
	book* b[3]; //����ü ������ �迭 ����
	printf("���� ���� �Է�\n");
	for (int i = 0; i < 3; i++){
		//heap������ ���� Ȯ��
	book* pbook = (book*)malloc(sizeof(book) * 1);
	puts("\n");//�ٹٲ�
	fputs("���� : ", stdout);
	fgets((*pbook).author, sizeof((*pbook).author), stdin);

	fputs("���� : ", stdout);
	fgets((*pbook).name, sizeof((*pbook).name), stdin);

	fputs("������ �� : ", stdout);
	scanf("%d", &((*pbook).page));

	clearBuffer(); //�Է� ���۸� ���� �Լ� ȣ��
	b[i] = pbook;
}



fputs("\n\n\n���� ���� ���\n", stdout);

for (int i = 0; i < 3; i++) {
	printf("\nbook %d \n", i + 1);

	printf("���� : %s", b[i]->author);
	printf("���� : %s", b[i]->name);
	printf("������ �� : %d \n", b[i]->page);
}
//heap������ �޸� ������ ������
for (int i = 0; i < 3; i++)
	free(b[i]);
return 0;
}
//�Է� ���۸� ���� �Լ�
void clearBuffer(void) {
	while (getchar() != '\n');
}
*/