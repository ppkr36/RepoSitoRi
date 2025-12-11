#include <iostream>
double myModul(double num) {
	if (num < 0) {
		num *= -1;
	}
	return num;
 }

int main() {
	system("chcp 1251");
	double num1, num2;
	std::cout << "Введите 2 числа: "; std::cin >> num1 >> num2;
	std::cout << "Модули этих чисел: " << myModul(num1) << " " << myModul(num2);
	std::cout << "\nСумма модулей: " << myModul(num1) + myModul(num2);
	std::cout << "\nМодуль суммы: " << myModul(num1 + num2);

}