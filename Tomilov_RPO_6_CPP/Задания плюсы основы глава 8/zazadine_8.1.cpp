#include <iostream>
int main() {
	system("chcp 1251");
	int* ptr = nullptr;
	std::cout << "ptr: " << ptr;
	int* ptr1 = nullptr;
	std::cout << "ptr1: " << ptr1;
	int* ptr2 = nullptr;
	int num;
	ptr2 = &num;
	std::cout << "ptr2: " << ptr2 << " " << "*ptr2: " << *ptr2;
	*ptr2 = 55;
	std::cout << "ptr2: " << ptr2 << " " << "*ptr2: " << *ptr2;
}