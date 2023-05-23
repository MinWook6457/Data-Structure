
// �⸻�� ������ ����!
/*
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_NAME 100 
#define MAX_SUBJECT 3 //���� ��
typedef struct Student {
	char name[MAX_NAME];
	int num; 
	int scores[MAX_SUBJECT];
	struct Student *next;
	struct Student *prev;
}Student;
const char *titles[MAX_SUBJECT] = { "����","����","����" }; // ���� ����
Student *head, *tail;
void init() // �ʱ�ȭ
{
	head = (Student *)malloc(sizeof(Student));
	tail = (Student *)malloc(sizeof(Student));
	head->next = tail;
	tail->prev = head;
	head->prev = tail->next = NULL;
}
int SelectMenu()
{
	int key;
	printf("���� ���� ���α׷� 0:����\n");
	printf("1: �л� ������ �Է� 2: �л� ������ ���� 3: �л� �˻� 4: ��� ���� \n");
	printf("�޴� ���� : ");
	scanf("%d", &key);
	return key;
}
void AddStudent() // �л� �߰�
{
	int num;
	printf("�߰��� �л� ��ȣ: ");
	scanf("%d", &num);

	Student *student = (Student *)malloc(sizeof(Student));//�л� ����ü ���� �޸� �Ҵ�   
	student->num = num;
	printf("�̸�: ");
	scanf("%s", student->name);

	for (int i  = 0;i < MAX_SUBJECT;i++) // �л� ���� �Է�
	{
		printf("%s ����:", titles[i]);
		scanf("%d", &student->scores[i]);

		if (CheckScore(student->scores[i]) == 0)//��ȿ�� ������ �ƴ� ��
		{
			student->scores[i] = -1;
			printf("�Է��� ������ ��ȿ���� �ʾƼ� %s ������ �Է� ó������ �ʾҽ��ϴ�.\n", titles[i]);
		}
	}
	student->next = tail;
	student->prev = tail->prev;
	tail->prev->next = student;
	tail->prev = student;
}
int CheckScore(int score) // ������ 100�� ���� 0�� �̻�
{
	if ((score >= 0) && (score <= 100))
		return 1;
	else
		return 0;
}
void RemoveStudent()
{
	int num;
	
	printf("������ �л� ��ȣ: ");
	scanf("%d", &num);

	for (Student *p = head->next; p != tail; p = p->next)
	{
		if (p->num == num)
		{
			//���Ḯ��Ʈ���� ��ũ ����
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);//�޸� ����
			printf("�����Ͽ����ϴ�.\n");
			return;
		}
	}
	printf("�����Ͱ� �����ϴ�.\n");

}
void ViewStudentData(Student *student) // �л� ������ ���
{
	printf("%4d %5s ", student->num, student->name);
	for (int i = 0; i < MAX_SUBJECT;i++)
	{
		printf("%4d ", student->scores[i]);
	}
	printf("\n");
}
void SearchStudent()
{
	int num = 0;
	printf("�˻��� �л� ��ȣ: ");
	scanf("%d", &num);
	for (Student *p = head->next; p != tail; p = p->next)
	{
		if (p->num == num)
		{
			ViewStudentData(p);
			return;
		}
	}
	printf("�����Ͱ� �����ϴ�.\n");

}

void PrintListStudent()
{
	printf("��ȣ     �̸�     ");
	for (int i = 0; i < MAX_SUBJECT;i++)
	{
		printf("%4s ", titles[i]);
	}
	printf("������ -1�� ���� ���Է�\n");
	for (Student *p = head->next; p != tail; p = p->next)
	{
		ViewStudentData(p);
	}
}
void Exit()
{
	Student *p = head;
	while (p->next)
	{
		p = p->next;
		free(p->prev);
	}
	free(p);
}
int main()
{
	init();
	int key = 0;
	while ((key = SelectMenu()) != 0)
	{
		switch (key)
		{
		case 1: AddStudent(); break;
		case 2: RemoveStudent(); break;
		case 3: SearchStudent(); break;
		case 4: PrintListStudent(); break;
		default: printf("�߸� �����Ͽ����ϴ�.\n"); break;
		}
	}
	printf("���α׷� ����\n");

	Exit();//�����ϱ� ���� �Ҵ��� �޸� ����
	return 0;
}

*/