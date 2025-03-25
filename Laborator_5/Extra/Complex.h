#pragma 
#include <iostream>

class Complex
{
	int re, im;
public:

	Complex(int re, int mi);

	friend Complex operator+ (Complex a, Complex b);
	friend Complex operator+ (Complex a, int x);
	friend Complex operator+ (int x, Complex b);

	friend Complex operator- (Complex a, Complex b);
	friend Complex operator- (Complex a, int x);
	friend Complex operator- (int x, Complex b);

	friend Complex operator* (Complex a, Complex b);
	friend Complex operator* (Complex a, int x);
	friend Complex operator* (int x, Complex b);

	bool operator- (Complex& a);
	friend bool operator== (Complex a, Complex b);
	friend bool operator!= (Complex a, Complex b);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	Complex& operator++ ();
	Complex operator++ (int val);
	Complex& operator-- ();
	Complex operator-- (int val);
	void operator() ();
};