#include <iostream>
int main(){
	system("chcp 1251");
	double num1, num2, num3;
	std::cout << "Введите 3 вещественных числа: ";
	std::cin >> num1 >> num2 >> num3;

	if (num1 > num2 && num1 > num3) {
		std::cout << num1 << " Больше";
	};
	if (num2 > num1 && num2 > num3) {
		std::cout << num2 << " Больше";
	};
	if (num3 > num2 && num3 > num1) {
		std::cout << num3 << " Больше";
	};
	return 0;
}