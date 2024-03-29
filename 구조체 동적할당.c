/*
////////////////////////////////////////////////////////////////
//
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 04월 28일
// 프로그램명 : 구조체 동적할당
// 프로그램설명 : 구조체로 선언된 자료형을 
//				  동적할당 하여 메모리 할당
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void clearBuffer(void);
//책의 정보를 저장하는 구조체
typedef struct {
	char author[10];//저자
	char name[30];//제목
	int page;//페이지
}book;
int main(void) {
	book* b[3]; //구조체 포인터 배열 선언
	printf("도서 정보 입력\n");
	for (int i = 0; i < 3; i++){
		//heap영역에 공간 확보
	book* pbook = (book*)malloc(sizeof(book) * 1);
	puts("\n");//줄바꿈
	fputs("저자 : ", stdout);
	fgets((*pbook).author, sizeof((*pbook).author), stdin);

	fputs("제목 : ", stdout);
	fgets((*pbook).name, sizeof((*pbook).name), stdin);

	fputs("페이지 수 : ", stdout);
	scanf("%d", &((*pbook).page));

	clearBuffer(); //입력 버퍼를 비우는 함수 호출
	b[i] = pbook;
}



fputs("\n\n\n도서 정보 출력\n", stdout);

for (int i = 0; i < 3; i++) {
	printf("\nbook %d \n", i + 1);

	printf("저자 : %s", b[i]->author);
	printf("제목 : %s", b[i]->name);
	printf("페이지 수 : %d \n", b[i]->page);
}
//heap영역의 메모리 공간을 정리함
for (int i = 0; i < 3; i++)
	free(b[i]);
return 0;
}
//입력 버퍼를 비우는 함수
void clearBuffer(void) {
	while (getchar() != '\n');
}
*/