#include "Complex.h"

Complex::Complex(int _re, int _im) : re(_re), im(_im) {}

Complex operator+ (Complex A, Complex B) {
	return Complex(A.re + B.re, A.im + B.im);
}

Complex operator+ (Complex A, int x) {
	return Complex(A.re + x, A.im);
}

Complex operator+ (int x, Complex B) {
	return Complex(B.re + x, B.im);
}

Complex operator- (Complex A, Complex B) {
	return Complex(A.re - B.re, A.im - B.im);
}

Complex operator- (Complex A, int x) {
	return Complex(A.re - x, A.im);
}

Complex operator- (int x, Complex B) {
	return Complex(x - B.re, B.im);
}

Complex operator* (Complex A, Complex B) {
	return Complex(A.re * B.re - A.im * B.im, A.re * B.im + A.im * B.re);
}

Complex operator* (Complex a, int x) {
	return Complex(a.re * x, a.im * x);
}

Complex operator* (int x, Complex b) {
	return Complex(b.re * x, b.im * x);
}

bool Complex::operator- (Complex& A) {
	A.re *= -1;
	A.im *= -1;
	return true;
}

bool operator== (Complex a, Complex b) {
	return a.re == b.re && a.im == b.im;
}

bool operator!= (Complex a, Complex b) {
	return a.re != b.re || a.im != b.im;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << "(" << c.re << ", " << c.im << ")";
	return os;
}

Complex& Complex::operator++ () {
	re++;
	return *this;
}

Complex Complex::operator++ (int val) {
	Complex temp(re, im);
	++(*this);
	return temp;
}

Complex& Complex::operator-- () {
	re--;
	return *this;
}

Complex Complex::operator-- (int val) {
	Complex temp(re, im);
	--(*this);
	return temp;
}

void Complex::operator() () {
	std::cout << "Complex number: " << *this << "\n";
}