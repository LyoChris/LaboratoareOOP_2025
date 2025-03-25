#include "Number.h"
#include <iostream>
#include <cstring>

int strlen(char s[]){
	int i;
	for (i = 0; s[i]; i++);
	return i;
}

int cmp_str(char* a, char* b) {
	int lena = strlen(a), lenb = strlen(b);
	if (lena < lenb) return -1;
	if (lena > lenb) return 1;
	for (int i = 0;i < lena;i++) {
		if (a[i] < b[i]) return -1;
		if (a[i] > b[i]) return 1;
	}
	return 0;
}

int Convert(char ch)
{
	if (isdigit(ch))
		return ch - '0';
	return ch - 'A' + 10;
}

char Convert(int nr)
{
	if (0 <= nr and nr <= 9)
		return nr + '0';
	return 'A' + nr - 10;
}

Number::Number() {

}

Number::Number(const char* value, int baza)
{
	x = new char[strlen(value) + 1];
	for (int i = 0; i < strlen(value); i++)
	{
		x[i] = value[i];
	}
	x[strlen(value)] = '\0';
	base = baza;
}

Number::Number(int value, int baza) {
	int len = log10(value) + 1;
	x = new char[len + 1];
	char str[100];
	_itoa(value, str, 10);
	for (int i = 0;i < len;i++) {
		x[i] = str[i];
	}
	x[len] = '\0';
	base = baza;
}

Number::Number(const Number& other) {
	x = new char[strlen(other.x) + 1];
	for (int i = 0; i < strlen(other.x); i++) {
		x[i] = other.x[i];
	}
	x[strlen(other.x)] = '\0';
	base = other.base;
}

Number::Number(Number&& other) {
	x = other.x;
	base = other.base;
	other.x = nullptr;
}

Number::~Number() {
	base = -1;
	delete[] x;
}

Number operator+ (Number a, Number b) {
	int ok = (a.base > b.base) ? a.base : b.base;
	a.SwitchBase(10);
	b.SwitchBase(10);
	int nr1 = 0, nr2 = 0;
	for (int i = 0; a.x[i]; i++) {
		nr1 = nr1 * 10 + Convert(a.x[i]);
	}
	for (int i = 0; b.x[i]; i++) {
		nr2 = nr2 * 10 + Convert(b.x[i]);
	}
	nr1 = nr1 + nr2;
	int len = log10(nr1) + 1;
	char* str = new char[len];
	char str2[100];
	_itoa(nr1, str2, 10);
	for (int i = 0;i < strlen(str);i++) {
		str[i] = str2[i];
	}
	str[strlen(str)] = '\0';
	Number c(str, 10);
	c.SwitchBase(ok);
	return c;
}

Number operator- (Number a, Number b) {
	int ok = (a.base > b.base) ? a.base : b.base;
	a.SwitchBase(10);
	b.SwitchBase(10);
	int nr1 = 0, nr2 = 0;
	for (int i = 0;i < strlen(a.x);i++) {
		nr1 = nr1 * 10 + Convert(a.x[i]);
	}
	for (int i = 0;i < strlen(b.x);i++) {
		nr2 = nr2 * 10 + Convert(b.x[i]);
	}
	nr1 = nr1 - nr2;
	int len = log10(nr1) + 1;
	char* str = new char[len];
	char str2[100];
	_itoa(nr1, str2, 10);
	for (int i = 0;i < len;i++) {
		str[i] = str2[i];
	}
	str[len] = '\0';
	Number c(str, 10);
	c.SwitchBase(ok);
	return c;
}

char Number::operator[] (int index) {
	if (index < 0 || index >= strlen(x)) {
		std::cout << "Index out of bounds";
		return NULL;
	}
	return x[strlen(x) - index - 1];
}

bool operator== (Number a, Number b) {
	if (a.base != b.base) {
		a.SwitchBase(10);
		b.SwitchBase(10);
	}
	return cmp_str(a.x, b.x) == 0;
}

bool operator>= (Number a, Number b) {
	if (a.base != b.base) {
		a.SwitchBase(10);
		b.SwitchBase(10);
	}
	return cmp_str(a.x, b.x) >= 0;
}

bool operator<= (Number a, Number b) {
	if (a.base != b.base) {
		a.SwitchBase(10);
		b.SwitchBase(10);
	}
	return cmp_str(a.x, b.x) <= 0;
}

bool operator> (Number a, Number b) {
	if (a.base != b.base) {
		a.SwitchBase(10);
		b.SwitchBase(10);
	}
	return cmp_str(a.x, b.x) > 0;
}

bool operator< (Number a, Number b) {
	if (a.base != b.base) {
		a.SwitchBase(10);
		b.SwitchBase(10);
	}
	return cmp_str(a.x, b.x) < 0;
}

Number& Number::operator-- () {
	int i = 0;
	for (i = 1;i < strlen(x);i++) {
		x[i - 1] = x[i];
	}
	x[i - 1] = '\0';
	return(*this);
}

Number Number::operator-- (int) {
	Number temp(x, base);
	x[strlen(x) - 1] = '\0';
	return temp;
}

bool Number::operator= (int val) {
	int len = log10(val) + 1;
	x = new char[len + 1];
	char str[100];
	_itoa(val, str, 10);
	for (int i = 0;i < strlen(str);i++) {
		x[i] = str[i];
	}
	x[strlen(str)] = '\0';
	return true;
}

bool Number::operator= (const char* str) {
	x = new char[strlen(str) + 1];
	for (int i = 0;i < strlen(str);i++) {
		x[i] = str[i];
	}
	x[strlen(str)] = '\0';
	base = 10;
	return true;
}

bool Number::operator= (Number a) {
	delete[] x;
	x = new char[strlen(a.x) + 1];
	for (int i = 0;i < strlen(a.x);i++) {
		x[i] = a.x[i];
	}
	x[strlen(a.x)] = '\0';
	base = a.base;
	return true;
}

bool operator+= (Number& a, Number b) {
	a = a + b;
	return true;
}

void Number::SwitchBase(int newBase) {
	int nr = 0, p = 1;
	for (int i = strlen(x) - 1;i >= 0;i--) {
		nr += p * Convert(x[i]);
		p = p * base;
	}

	int left = -1;
	char str[100];
	for (int i = 0;i < 100;i++) str[i] = NULL;
	while (nr) {
		str[++left] = Convert(nr % newBase);
		nr = nr / newBase;
	}
	for (int i = 0, j = left; i <= j; i++, j--)
		swap(str[i], str[j]);
	x = new char[strlen(str) + 1];
	for (int i = 0;i < strlen(str);i++) {
		x[i] = str[i];
	}
	x[strlen(str)] = '\0';
	base = newBase;
}

void Number::Print() {
	cout << x << '\n';
}

int Number::GetDigitsCount() {
	return strlen(x);
}

int Number::GetBase() {
	return base;
}