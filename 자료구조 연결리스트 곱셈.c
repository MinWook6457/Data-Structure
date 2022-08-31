////////////////////////////////////////////////////////////////
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 05월 25일
// 프로그램명 : 파일입출력과 연결리스트를 이용한 데이터 곱셈
// 프로그램설명 : 텍스트파일에 있는 데이터를 입력받아 연결리스트로 구현하고
//				  리스트를 정렬한 후 연결리스트 끼리 곱셈을 한다.
//				  텍스트 파일에서 받아오는 알고리즘은 문자열을
//				  공백 기준으로 잘라서 정수형으로 변환해준다.
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
#define SIZE 10000
typedef struct ListNode { // 노드 생성
	int coef;
	int expon;
	struct ListNode *link;
}ListNode;
typedef struct ListType { // 헤더 노드 생성
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;
////////////////////////////////////////////////////////////////
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 05월 25일
// 함수명 : create()
// 함수설명 :연결리스트 헤더를 초기화하는 함수이다.
// 함수출력: 연결리스트 헤더를 동적할당 하여 헤더가 거리키는 노드들의
//			 값과 size(크기)를 초기화 시킨다.
////////////////////////////////////////////////////////////////
ListType* create() {
	ListType *plist = (ListType *)malloc(sizeof(ListType)); // 연결리스트 헤더 동적할당
	plist->size = 0; // 연결리스트의 크기를 0으로 지정
	plist->head = plist->tail = NULL; // 머리노드와 꼬리노드가 NULL을 가리키도록 지정
	return plist;
}
////////////////////////////////////////////////////////////////
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 05월 25일
// 함수명 : insert_first()
// 함수설명 : 연결리스트의 맨 앞 부분에 노드를 삽입하는 함수이다.
// 함수입력: 연결리스트 헤더와 필요한 연결리스트 노드를 입력한다.
// 함수출력: 입력된 노드의 link를 연결리스트 헤더가 가리키는 머리노드를
//			 가리키도록 하고 헤더의 머리노드는 입력된 노드를 가리킨다. 
////////////////////////////////////////////////////////////////
void insert_first(ListType*plist, ListNode* temp) {
	temp->link = plist->head; // 노드의 링크가 연결리스트 헤더의 머리노드의 값을 가리킴
	plist->head = temp; // 헤더의 머리노드가 입력된 연결 리스트 노드를 가리키도록함
}
////////////////////////////////////////////////////////////////
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 05월 25일
// 함수명 : insert_last()
// 함수설명 : 연결리스트의 맨 뒷 부분에 노드를 삽입하는 함수이다.
// 함수입력: 연결리스트 헤더와 필요한 연결리스트 노드를 입력한다.
// 함수출력: 연결리스트 헤더의 꼬리 노드의 링크가 입력된 노드를 가리키도록 하고
//			 가리키도록 하고 헤더의 머리노드는 입력된 노드를 가리킨다. 
////////////////////////////////////////////////////////////////
void insert_last(ListType*plist, ListNode*temp) {
	plist->tail->link = temp; // 연결리스트 꼬리노드의 링크가 입력된 노드를 가리키도록 한다. 
	plist->tail = temp; // 연결리스트 꼬리노드가 입력된 노드를 가리키도록 한다. 
}
////////////////////////////////////////////////////////////////
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 05월 25일
// 함수명 : sort_List()
// 함수설명 : 연결리스트를 정렬함과 동시에 입력하는 함수이다.
// 함수입력: 연결리스트의 헤더와 지수, 차수가 입력된다.
// 함수출력: 정렬된 연결리스트
////////////////////////////////////////////////////////////////
void sort_List(ListType *L, int coef, int expon) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드 생성
	 // 생성된 노드 초기화
	newNode->coef = coef;
	newNode->expon = expon;
	newNode->link = NULL;
	
	ListNode *cur, *next; // 값을 삽입하기 위해서는 두개의 노드가 필요함
	if (L->tail == NULL) { // 헤더 노드의 tail 값이 NULL인 것은 리스트에 값이 존재하지 않는 것임 
		L->head = L->tail = newNode;
	}
	else {
		if (newNode->expon > L->head->expon) { // 새로 생긴 노드의 차수가 헤더 노드가 가리키는 head노드의 차수보다 큰 경우
			insert_first(L, newNode); // 맨 앞에 추가
		}
		else if (newNode->expon < L->tail->expon) { // 새로 생긴 노드의 차수가 헤더 노드가 가리키는 tail노드의 차수보다 작은 경우
			insert_last(L, newNode); // 맨 마지막에 추가
		}
		else { // 중간에 삽입하는 경우
			// 반복문 설명 : cur 노드는 헤더의 머리 노드를 가리키고 next노드는 cur 노드의 link를 가리킴으로써 반복이 될 때마다 next노드가 cur노드를 따라간다.
			for (cur = L->head, next = cur->link; next != NULL; cur = cur->link, next = next->link) { // 노드를 옮겨가며 검사
				//cur 노드가 가리키는 차수가 새로 생긴 노드의 차수보다 크고 새로 생긴 노드의 차수가 cur 포인터를 따라가는 next 포인터가 가리키는 차수보다 크다면
				if (cur->expon > newNode->expon && newNode->expon > next->expon) { 
					newNode->link = next; // newNode의 링크가 next를 가리킴
					cur->link = newNode; // 현재 노드의 link가 newNode를 가리키도록 함
				}
			}
		}
	}
	L->size++; // 헤더 노드 사이즈 증가
}
////////////////////////////////////////////////////////////////
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 05월 25일
// 함수명 : print_List()
// 함수설명 : 연결리스트 출력 함수.
// 함수출력: 연결리스트 출력
////////////////////////////////////////////////////////////////
void print_List(ListType* plist) { // 출력하는 함수
	for (ListNode *p = plist->head; p != NULL; p = p->link) {
		if (p->link == NULL) // 맨 마지막 노드를 가리키는 경우
			printf("%dX^%d", p->coef, p->expon);
		else
			printf("%dX^%d + ", p->coef, p->expon);
	}
}
////////////////////////////////////////////////////////////////
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 05월 25일
// 함수명 : multy_poly()
// 함수설명 : 두 개의 연결리스트를 곱하는 함수.
// 함수입력: 다항식 곱셈에 사용될 2개의 연결리스트와 결과를 저장하는 연결리스트 한 개
// 함수출력: 연결리스트를 이용하여 다항식 곱셈 결과 출력
////////////////////////////////////////////////////////////////
void multy_poly(ListType *L1, ListType *L2, ListType *L3) { // 곱셈 연산 함수
	ListNode *p1 = NULL; // 헤더 노드1의 head부터 tail까지 지나가는 포인터
	ListNode *p2 = NULL; // 헤더 노드2의 head부터 tail까지 지나가는 포인터
	ListNode *p3 = NULL; // 두 연결리스트의 곱셈을 저장할 포인터
	p1 = L1->head; // 첫 번째 헤더 노드의 head가 가리키는 부분을 p1이 가리키게함
	int nCount = 0;
	int coef; // 지수의 곱을 저장할 변수
	int expon; // 차수의 곱을 저장할 변수
	while (p1 != NULL) { // ,p1의 값이 NULL이 아닐때 까지 
		for (p2 = L2->head; p2 != NULL; p2 = p2->link) {
			coef = p1->coef * p2->coef; // 지수끼리 곱한다
			expon = p1->expon + p2->expon; // 차수끼리 곱한다(차수의 곱은 더해짐)
			if (L3->tail == NULL) { // 꼬리 노드가 NULL인 경우는 연결리스트가 빈 경우이므로 데이터를 추가해준다.
				sort_List(L3, coef, expon);
			}
			else {
				for (p3 = L3->head, nCount = 0; p3 != NULL; p3 = p3->link, nCount++) { //p3를 이동하면서 검사 , nCount 증가
					if (p3->expon == expon) { // 계산된 차수와 입력된 연결리스트의 차수가 같다면
						p3->coef += coef; // p3의 지수에 계산된 지수를 더한다.
						break; // 반복문 탈출
					}
				}
				if (nCount == L3->size) // 끝까지 검색하여 차수가 같은 것이 없다면
					sort_List(L3, coef, expon); // L3 헤더에 정렬
			}
		}
		p1 = p1->link; // 포인터 이동
	}
}
////////////////////////////////////////////////////////////////
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 05월 25일
// 함수명 : free_List()
// 함수설명 : 동적 메모리 해제 함수
// 함수입력: 생성된 연결리스트
// 함수출력: 연결리스트에 사용된 메모리 해제
////////////////////////////////////////////////////////////////
void freeList(ListType *list) {
	ListNode *p;
	ListNode *temp;
	p = list->head;
	while (p!=NULL) {
		p = p->link;
		temp = p;
		free(temp);
	}
	free(list);
}
void main() {
	struct ListType **head; // 파일에 몇개의 다항식이 저장될 지 모르기 때문에 동적할당을 위한 이중포인터 선언
	FILE *fp; // 파일 포인터 선언
	fp = fopen("data.txt", "r"); // data.txt 파일을 읽기 모드로 열기
	char *temp[SIZE]; // 문자열을 저장할 배열 포인터
	char buffer[SIZE]; // 파일에서 받아온 문자열을 저장할 배열
	int *index; // 문자열 길이를 저장할 포인터
	if (fp == NULL) {
		fprintf(stderr, "File open error\n");
		exit(1);
	}
	int nCount = 0; // 문자열의 개수
	while (!feof(fp)) { // 파일안에 문자열이 몇 개 들어있는지 파악
		fgets(temp, stdin, fp);
		nCount++;
	}
	rewind(fp); // 파일포인터 원위치
	index = (int *)malloc(sizeof(int)*nCount); // 파일의 개수만큼 인덱스 동적할당
	if (index == NULL) {
		fprintf(stderr, "동적할당 실패\n");
		exit(1);
	}
	head = (ListType *)malloc(sizeof(ListType)*(nCount));
	if (head == NULL) {
		fprintf(stderr, "동적할당 실패\n");
		exit(1);
	}
	for (int i = 0; i < nCount; i++) {
		fgets(buffer, stdin, fp); // 파일에서 받아온 문자열을 한 줄씩 buffer에 저장
		index[i] = (int)strlen(buffer); // 0번부터 nCount번까지 인덱스에 문자열 길이 저장
	}
	rewind(fp); // 파일포인터 원위치
	char *ch;
	for (int i = 0; i < nCount; i++) {
		ch = (char *)malloc(sizeof(char)*index[i]); // 문자열 길이만큼 동적할당
		if (ch == NULL) {
			fprintf(stderr, "동적할당 실패\n");
			exit(1);
		}
		fgets(ch, SIZE, fp); // 파일에서 문자열 한줄씩 받아오기
		temp[i] = ch; // 배열 포인터에 받아온 문자열 저장
		if (i == nCount) // 동적 메모리 해제
			free(ch);
	}
	int data[4][SIZE]; // 문자열을 정수형으로 변환시킬 정수형 배열 선언
	char *New[SIZE]; // 잘린 문자열을 가리킬 포인터
	for (int i = 0; i <= nCount; i++) { // 생성된 ListType 초기화
		head[i] = create();
	}
	for (int i = 0; i < nCount; i++) {
		int count = 0; // 데이터의 개수 파악을 위한 변수 선언
		int k = 0; // 문자열 번호 지정을 위한 변수 선언
		char *ptr = strtok(temp[i], " ");		//  " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환			
		while (ptr != NULL)			 // 자른 문자열이 나오지 않을 때까지 반복
		{
			New[k] = ptr;// 자른 문자열을 포인터 배열에 저장
			k++; // 인덱스 증가
			ptr = strtok(NULL, " ");		// 다음 문자열을 잘라서 포인터를 반환
			count++;				// 데이터 개수 증가
		}
		for (int j = 1; j < count; j++) // 첫 번째 인덱스에는 poly~ 가 들어가있기 때문에 인덱스 1부터 시작
		{
			if (temp[i] != NULL)		// 문자열 포인터 배열의 요소가 NULL이 아닐 때만
				data[i][j] = atoi(New[j]);	//New 배열에 있는 문자열을 정수로 변환한 후 data 배열에 저장
		}
		for (int j = 1; j < count; j += 2) // 첫 번째 인덱스에는 poly~ 가 들어가있기 때문에 인덱스 1부터 시작
		{
			sort_List(head[i], data[i][j], data[i][j + 1]); // 데이터에는 지수와 차수가 들어있기 때문에 두개씩 저장);
		}
	};
	struct ListType *tmp[3]; // ListType 포인터 배열 선언
	for (int i = 0; i < 3; i++) {
		tmp[i] = create();
	}
	for (int i = 0; i < nCount ; i++) { 
		printf("%s : ", temp[i]);
		print_List(head[i]);
		printf("\n");
	}
	tmp[0] = head[0]; // 가장 첫 번째 다항식을 저장
	for (int i = 0; i < nCount;i++) {
		if (i + 1 == nCount) // 반복의 끝을 위한 조건
			break;
		tmp[1] = head[i+1]; // 곱셈할 다항식 저장
		multy_poly(tmp[0], tmp[1], tmp[2]); // 계산된 다항식과 곱셈할 다항식을 tmp[2]에 저장
		printf("multypoly :");
		print_List(tmp[2]);
		printf("\n");
		tmp[0] = tmp[2]; // 계산된 다항식 저장
	}

	for(int i = 0 ; i < nCount+1; i++) // 메모리 해제
			free(head[i]);
	free(index);
	fclose(fp); // 파일 닫기
}
