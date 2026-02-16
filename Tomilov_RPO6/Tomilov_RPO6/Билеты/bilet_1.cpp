#include <iostream>
double myModul(double num) {
	if (num < 0) {
		num *= -1;
	}
	return num;
}
int main() {
	system("chcp 1251");
	double num1 =55.3, num2 = -32, num3 = 9.32;
	if (myModul(num1) > myModul(num2)|| myModul(num1) > myModul(num3)) {
		std::cout << "Наибольший модуль " << num1;
	}
	if (myModul(num2) > myModul(num1) || myModul(num2) > myModul(num3)) {
		std::cout << "Наибольший модуль " << num2;
	}
	if (myModul(num3) > myModul(num1) || myModul(num3) > myModul(num2)) {
		std::cout << "Наибольший модуль " << num3;
	}
	std::cout << "\nСумма модулей: " << myModul(num1) + myModul(num2) + myModul(num3);
	std::cout << "Модуль суммы: " << myModul(num1 + num2 + num3);
}