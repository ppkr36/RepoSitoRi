#include <iostream>

void myFunc(int& num) {
	std::cout << "Адрес переменной в функции: " << &num << "\n" << "Значение по этому адресу: " << num << "\n";
}

int main() {
	system("chcp 1251");
	int num = 151;
	int* ptr;
	int& link = num;
	ptr = new int(22222222);
	myFunc(num);
	myFunc(*ptr);
	myFunc(link);
}