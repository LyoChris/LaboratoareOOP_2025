#pragma once

#include <iostream>
#include <vector>
#include <cstdarg>
#include <cstring>

class Sort
{
private:
	std::vector<int> elements;
	int n;

public:
	Sort(int ne, int mini, int maxi); 
	Sort(std::initializer_list<int> list);
	Sort(int ne, int* elem);
	Sort(int ne, ...);
	Sort(const char* element);

	void InsertSort(bool ascendent=false);
	void QuickSort(bool ascendent=false);
	void BubbleSort(bool ascendent=false);
	void Print();

	int GetElementsCount();
	int GetElementFromIndex(int index);
};

