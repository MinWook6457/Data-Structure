
// 기말에 무조건 출제!
/*
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_NAME 100 
#define MAX_SUBJECT 3 //과목 수
typedef struct Student {
	char name[MAX_NAME];
	int num; 
	int scores[MAX_SUBJECT];
	struct Student *next;
	struct Student *prev;
}Student;
const char *titles[MAX_SUBJECT] = { "국어","영어","수학" }; // 과목 설정
Student *head, *tail;
void init() // 초기화
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
	printf("성적 관리 프로그램 0:종료\n");
	printf("1: 학생 데이터 입력 2: 학생 데이터 삭제 3: 학생 검색 4: 목록 보기 \n");
	printf("메뉴 선택 : ");
	scanf("%d", &key);
	return key;
}
void AddStudent() // 학생 추가
{
	int num;
	printf("추가할 학생 번호: ");
	scanf("%d", &num);

	Student *student = (Student *)malloc(sizeof(Student));//학생 구조체 동적 메모리 할당   
	student->num = num;
	printf("이름: ");
	scanf("%s", student->name);

	for (int i  = 0;i < MAX_SUBJECT;i++) // 학생 성적 입력
	{
		printf("%s 성적:", titles[i]);
		scanf("%d", &student->scores[i]);

		if (CheckScore(student->scores[i]) == 0)//유효한 성적이 아닐 때
		{
			student->scores[i] = -1;
			printf("입력한 성적이 유효하지 않아서 %s 성적은 입력 처리하지 않았습니다.\n", titles[i]);
		}
	}
	student->next = tail;
	student->prev = tail->prev;
	tail->prev->next = student;
	tail->prev = student;
}
int CheckScore(int score) // 점수는 100점 이하 0점 이상
{
	if ((score >= 0) && (score <= 100))
		return 1;
	else
		return 0;
}
void RemoveStudent()
{
	int num;
	
	printf("삭제할 학생 번호: ");
	scanf("%d", &num);

	for (Student *p = head->next; p != tail; p = p->next)
	{
		if (p->num == num)
		{
			//연결리스트에서 링크 조절
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);//메모리 해제
			printf("삭제하였습니다.\n");
			return;
		}
	}
	printf("데이터가 없습니다.\n");

}
void ViewStudentData(Student *student) // 학생 데이터 출력
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
	printf("검색할 학생 번호: ");
	scanf("%d", &num);
	for (Student *p = head->next; p != tail; p = p->next)
	{
		if (p->num == num)
		{
			ViewStudentData(p);
			return;
		}
	}
	printf("데이터가 없습니다.\n");

}

void PrintListStudent()
{
	printf("번호     이름     ");
	for (int i = 0; i < MAX_SUBJECT;i++)
	{
		printf("%4s ", titles[i]);
	}
	printf("성적이 -1인 곳은 미입력\n");
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
		default: printf("잘못 선택하였습니다.\n"); break;
		}
	}
	printf("프로그램 종료\n");

	Exit();//종료하기 전에 할당한 메모리 해제
	return 0;
}

*/