/*
////////////////////////////////////////////////////////////////
//
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 04월 10일
// 프로그램명 : 임의의 위치에 정수를 삽입 및 삭제하는 함수
// 프로그램설명 : 배열의 임의의 위치에 정수를 삽입하는 함수이다.
//				  정수가 삽입되면 그 뒤에 있는 정수들은 한 칸씩
//				  뒤로 밀려야 한다. 삭제의 경우 그 뒤에 있는 정수
//				  들은 한 칸씩 앞으로 당겨야 한다.
////////////////////////////////////////////////////////////////
#include <stdio.h>
#define SIZE 100
void insert(int *arr, int location, int value) {
	int items = 5;
	for (int i = items - 1; i >= location; i--) {
		arr[i + 1] = arr[i];
	}
	arr[location] = value;
	items++;

	for (int j = 0; j < 5; j++)
		printf("%d ", arr[j]);
}
int delete(int *arr, int location) {
	int items = 5;
	int temp = arr[location];
	for (int i = location; i < items - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[items - 1] = 0;
	items--;
	return temp;
}
int main() {
	int array[SIZE] = { 0 };
	for (int i = 0; i < 5; i++) {
		array[i] = i;
		printf("%d ", array[i]);
	}
	printf("\n");
	insert(array, 2, 8);


	return 0;
}
*/