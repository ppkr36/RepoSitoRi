#include <iostream>
int main() {
	system("chcp 1251");
	double num1, num2, modul_num1, modul_num2, modul_sum;
	std::cout << "Введите 2 числа: ";
	std::cin >> num1 >> num2;
	modul_sum = num1 + num2;

	if (num1 < 0) {
		modul_num1 = num1 * -1;
	}
	else modul_num1 = num1;

	if (num2 < 0) {
		modul_num2 = num2 * -1;
	}
	else modul_num2 = num2;

	if (modul_sum < 0) {
		modul_sum = modul_sum * -1;
	}

	std::cout << "\n" << "модуль 1 числа: " << modul_num1 << ',' << "\n" << "модуль 2 числа: " << modul_num2 << ',';
	std::cout << "\n" << "Сумма модулей: " << modul_num1 + modul_num2 << ',';
	std::cout << "\n" << "Модуль суммы: " << modul_sum << "\n";
	return 0;
}