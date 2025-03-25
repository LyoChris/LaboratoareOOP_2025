#pragma once
#include <iostream>
using namespace std;

class Number
{
private:
	int base;
	char* x;
public:
	Number();
	Number(const char* value, int baza);
	Number(int value, int baza = 10);
	Number(const Number& other);
	Number(Number&& other);
	~Number();
	
	friend Number operator+ (Number a, Number b);
	friend Number operator- (Number a, Number b);
	char operator[] (int index);
	friend bool operator== (Number a, Number b);
	friend bool operator>= (Number a, Number b);
	friend bool operator<= (Number a, Number b);
	friend bool operator> (Number a, Number b);
	friend bool operator< (Number a, Number b);
	Number& operator-- ();
	Number operator-- (int);
	bool operator= (int val);
	bool operator= (const char* str);
	bool operator= (Number a);
	friend bool operator+= (Number& a, Number b);
			
	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();
};

