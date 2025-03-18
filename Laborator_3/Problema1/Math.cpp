#include "Math.h"
#include <iostream>
#include <cstdarg>
using namespace std;

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return a + b;
}

int Math::Add(double a, double b, double c){
	return a + b + c;
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a + b + c;
}

int Math::Mul(double a, double b) {
	return a + b;
}

int Math::Mul(double a, double b, double c) {
	return a + b + c;
}

int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);
	int sum = 0;
	for (int i = 0; i < count; ++i) {
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* s1, const char* s2) {
	if (!s1 || !s2) {
		return nullptr;
	}

	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char* result = new char[len1 + len2 + 1];

	strcpy(result, s1);
	strcat(result, s2);

	return result;
}
