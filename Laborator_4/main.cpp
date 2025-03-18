#include "Sort.h"


int main() {

	Sort s1(10, 45, 569);
	std::cout << "s1: ";
	s1.Print();
	std::cout<<"nr. elem s1:" << s1.GetElementsCount() << '\n';

	Sort s2({43, 56, 23, 13, 769, 854, 230});
	std::cout << "s2: ";
	s2.Print();

	int* arr = new int[10]{ 23, 45, 67, 89, 12, 34, 56, 78, 90, 11 };
	Sort s3(10, arr);
	std::cout << "s3: ";
	s3.Print();

	Sort s4(5, 23, 45, 67, 89, 12);
	std::cout << "s4: ";
	s4.Print();

	Sort s5("234,145,767,589,312,236923");
	std::cout << "s5: ";
	s5.Print();

	std::cout << '\n';

	s1.InsertSort(true);
	std::cout << "s1 after asc InsertSort: ";
	s1.Print();
	s1.InsertSort();
	std::cout << "s1 after dec InsertSort: ";
	s1.Print();
	std::cout << '\n';

	s2.QuickSort(true);
	std::cout << "s2 after asc QuickSort: ";
	s2.Print();
	s2.QuickSort();
	std::cout << "s2 after dec QuickSort: ";
	s2.Print();
	std::cout << '\n';

	s3.BubbleSort(true);
	std::cout << "s3 after asc BubbleSort: ";
	s3.Print();
	s3.BubbleSort();
	std::cout << "s3 after dec BubbleSort: ";
	s3.Print();
	std::cout << '\n';

	return 0;
}