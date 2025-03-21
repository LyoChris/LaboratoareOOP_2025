#include <iostream>
#include "NumberList.h"
using namespace std;

void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {
	numbers[count] = x;
	count++;
	return true;
}

void NumberList::Sort() {
	for (int i = 0; i < count - 1; i++) {
		for (int j = i; j < count; j++) {
			if (numbers[j] < numbers[i]) {
				swap(numbers[i], numbers[j]);
			}
		}
	}
}

void NumberList::Print() {
	for (int i = 0; i < count; i++) cout << numbers[i] << " ";
}



