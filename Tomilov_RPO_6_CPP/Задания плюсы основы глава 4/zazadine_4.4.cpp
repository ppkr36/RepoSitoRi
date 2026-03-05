#include <iostream>
int main() {
	system("chcp 1251");
	std::cout << "Введите число, отрицательное чтобы остановить: ";
	int sum = 0, num = 1, count = 0;
	while (num >= 0) {
		std::cin >> num;
		if (num >= 0) {
			count++;
			sum += num;
		}
	}
	std::cout << "Кол-во: " << count << "\nСумма: " << sum;
}