#include <iostream>
int main() {
	system("chcp 1251");
	int diff = 0;
	std::cout << "Введите кол-во чисел";
	int amount = 0;
	std::cin >> amount;
	int num = 0;
	int max = 0,min = 0;
	std::cout << "Вводите числа: ";
	std::cin >> num;
	max = num; min = num;
	for (int i = 0; i < amount-1; i++) {
		std::cin >> num;
		if (num < min) min = num;
		if (num > max) max = num;
	}
	std::cout << "Минимум: " << min << "\nМаксимум: " << max << "\nРазница" << max - min;
}