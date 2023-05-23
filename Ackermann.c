/*
////////////////////////////////////////////////////////////////
//
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 04월 04일
// 프로그램명 : Akernmann 재귀함수
// 프로그램설명 : Akernmann 재귀함수를 나타낸 프로그램이다.			
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