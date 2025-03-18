#include "Sort.h"
using namespace std;

Sort::Sort(int ne, int mini, int maxi)
{
	n = ne;
	for (int i = 0; i < ne; i++)
	{
		elements.push_back(rand() % (maxi - mini + 1) + mini);
	}
}

Sort::Sort(std::initializer_list<int> list) {
	n = list.size();
	for (auto it = list.begin(); it != list.end(); it++){
		elements.push_back(*it);
	}
}

Sort::Sort(int ne, int* elem) {
	n = ne;
	for (int i = 0; i < ne; i++){
		elements.push_back(elem[i]);
	}
}

Sort::Sort(int ne, ...) {
	n = ne;
	va_list args;
	va_start(args, ne);
	for (int i = 0; i < ne; i++){
		elements.push_back(va_arg(args, int));
	}
	va_end(args);
}

Sort::Sort(const char* element) {
	char* s = new char[strlen(element) + 1];
	strcpy(s, element);
	char* p = strtok(s, ",");
	while (p != NULL) {
		int nr = 0;
		for (int i = 0; i < strlen(p); i++) nr = nr * 10 + p[i] - '0';
		elements.push_back(nr);
		p = strtok(NULL, ",");
	}
	n = elements.size();
}

void Sort::InsertSort(bool ascendent) {
	int n = elements.size();
	for (int i = 1; i < n; i++) {
		int key = elements[i];
		int j = i - 1;
		while (j >= 0 && (ascendent ? elements[j] > key : elements[j] < key)) {
			elements[j + 1] = elements[j];
			j--;
		}
		elements[j + 1] = key;
	}
}

int Partition(vector<int>& elements, int low, int high, bool ascendent) {
	int pivot = elements[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (ascendent ? elements[j] < pivot : elements[j] > pivot) {
			i++;
			swap(elements[i], elements[j]);
		}
	}
	swap(elements[i + 1], elements[high]);
	return i + 1;
}

void TheRealQuickSort(vector<int>& elements, int low, int high, bool ascendent) {
	if (low < high) {
		int pi = Partition(elements, low, high, ascendent);
		TheRealQuickSort(elements, low, pi - 1, ascendent);
		TheRealQuickSort(elements, pi + 1, high, ascendent);
	}
}

void Sort::QuickSort(bool ascendent) {
	TheRealQuickSort(elements, 0, elements.size() - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
	int n = elements.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (ascendent ? elements[j] > elements[j + 1] : elements[j] < elements[j + 1]) {
				swap(elements[j], elements[j + 1]);
			}
		}
	}
}

void Sort::Print() {
	for (int i = 0; i < n; i++)
	{
		std::cout << elements[i] << " ";
	}
	std::cout << '\n';
}

int Sort::GetElementsCount() {
	return n;
}

int Sort::GetElementFromIndex(int index) {
	return elements[index];
}