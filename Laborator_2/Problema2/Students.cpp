#include <iostream>
#include <string>
#include "Students.h"
using namespace std;


void Student::InitName(char _name[]) {
	strcpy_s(name, _name);
}

char* Student::GetName() {
	return name;
}

void Student::addEng(float _eng) {
	if(_eng>=1 && _eng <=10)
	english = _eng;
}

void Student::addMath(float _math) {
	if (_math >= 1 && _math <= 10)
	math = _math;
}

void Student::addHist(float _history) {
	if (_history >= 1 && _history <= 10)
	history = _history;
}
float Student::Avg() {
	avg = (math + english + history) / 3;
	return avg;
}

float Student::GetEng() {
	return english;
}
float Student::GetMath() {
	return math;
}
float Student::GetHist() {
	return history;
}