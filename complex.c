/*
////////////////////////////////////////////////////////////////
//
// 작성자 : 20194024 김민욱
// 작성일 : 2022년 04월 10일
// 프로그램명 : 복소수 덧셈 프로그램
// 프로그램설명 : 복소수 구조체를 정의하고 각 복소수의 덧셈을 구한다.				
//
////////////////////////////////////////////////////////////////
#include <stdio.h>
typedef struct {
	float real;
	float imaginary;
}Complex;
Complex complex_add(Complex a, Complex b) {
	Complex c;
	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;

	return c;
}
int main() {
	Complex c1, c2, c3;
	c1.real = 5.0;
	c1.imaginary = 1.1;
	c2.real = 6.0;
	c2.imaginary = 1.1;
	c3 = complex_add(c1, c2);
	printf("%f %f", c3.real, c3.imaginary);

	return 0;
}
*/