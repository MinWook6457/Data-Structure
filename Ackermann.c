/*
////////////////////////////////////////////////////////////////
//
// �ۼ��� : 20194024 ��ο�
// �ۼ��� : 2022�� 04�� 04��
// ���α׷��� : Akernmann ����Լ�
// ���α׷����� : Akernmann ����Լ��� ��Ÿ�� ���α׷��̴�.			
//
////////////////////////////////////////////////////////////////
#include <stdio.h>
int Ackermmann(int m, int n) {
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return Ackermmann(m - 1, 1);
	else
		return Ackermmann(m - 1, Ackermmann(m, n - 1));

}
int main() {
	printf("%d ", Ackermmann(3, 2));
}
*/