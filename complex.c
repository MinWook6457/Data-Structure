/*
////////////////////////////////////////////////////////////////
//
// �ۼ��� : 20194024 ��ο�
// �ۼ��� : 2022�� 04�� 10��
// ���α׷��� : ���Ҽ� ���� ���α׷�
// ���α׷����� : ���Ҽ� ����ü�� �����ϰ� �� ���Ҽ��� ������ ���Ѵ�.				
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