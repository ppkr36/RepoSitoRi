#include <iostream>
int main() {
	system("chcp 1251");
	int* ptr = new int;
	std::cout << ptr << " = " << *ptr;
	std::cout << "\n ¬ведите новое значение динамической переменной: ";
	std::cin >> *ptr;
	std::cout << ptr << " = " << *ptr << "\n";
	delete ptr;
	ptr = new int(100);
	std::cout << ptr << " = " << *ptr;
}