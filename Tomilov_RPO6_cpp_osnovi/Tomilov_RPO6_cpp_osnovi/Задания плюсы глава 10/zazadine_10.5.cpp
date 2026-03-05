#include <iostream>
template <typename T>
T modulFunc(T num) {
	if (num < 0) {
		return num * -1;
	}
	else return num;
}
int main() {
	system("chcp 1251");
	int num1;
	double num2;
	std::cout << "Введите 2 числа 1-int 2-double: ";
	std::cin >> num1 >> num2;
	std::cout << "Модули: " << modulFunc(num1) << " " << modulFunc(num2) << "\n";
	std::cout << "Сумма модулей: " << modulFunc(num1) + modulFunc(num2) << "\n";
	std::cout << "Модуль суммы: " << modulFunc(num1 + num2);
}