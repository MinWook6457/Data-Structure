/*
////////////////////////////////////////////////////////////////
//
// �ۼ��� : 20194024 ��ο�
// �ۼ��� : 2022�� 04�� 10��
// ���α׷��� : ������ ��ġ�� ������ ���� �� �����ϴ� �Լ�
// ���α׷����� : �迭�� ������ ��ġ�� ������ �����ϴ� �Լ��̴�.
//				  ������ ���ԵǸ� �� �ڿ� �ִ� �������� �� ĭ��
//				  �ڷ� �з��� �Ѵ�. ������ ��� �� �ڿ� �ִ� ����
//				  ���� �� ĭ�� ������ ��ܾ� �Ѵ�.
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