#include <iostream>
#include "Functions.h"
using namespace std;

int compName(Student a, Student b) {
	if (strcmp(a.GetName(), b.GetName()) > 0) return 1;
	if (strcmp(a.GetName(), b.GetName()) < 0) return -1;
	if (strcmp(a.GetName(), b.GetName()) == 0) return 0;
}

int compMath(Student a, Student b) {
	float n1 = a.GetMath();
	float n2 = b.GetMath();
	if (n1 > n2) return 1;
	else {
		if (n1 < n2) return -1;
		else {
			return 0;
		}
	}
}
int compEng(Student a, Student b) {
	float n1 = a.GetEng();
	float n2 = b.GetEng();
	if (n1 > n2) return 1;
	else {
		if (n1 < n2) return -1;
		else {
			return 0;
		}
	}
}

int compHist(Student a, Student b) {
	float n1 = a.GetHist();
	float n2 = b.GetHist();
	if (n1 > n2) return 1;
	else {
		if (n1 < n2) return -1;
		else {
			return 0;
		}
	}
}

int compavg(Student a, Student b) {
	float n1 = a.Avg();
	float n2 = b.Avg();
	if (n1 > n2) return 1;
	else {
		if (n1 < n2) return -1;
		else {
			return 0;
		}
	}
}