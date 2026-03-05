#include <iostream>
int evclidFunc(int num1, int num2) {
	if (num2 == 0) return num1;
	evclidFunc(num2, num1%num2);
}
int main() {
	system("chcp 1251 > nul");
	int num1;
	int num2;
	std::cout << "Ведите первое число: ";
	std::cin >> num1;
	system("cls");
	std::cout << "Ведите второе число: ";
	std::cin >> num2;
	system("cls");
	std::cout << "НОД этих двух чисел равен: " << evclidFunc(num1, num2);
}