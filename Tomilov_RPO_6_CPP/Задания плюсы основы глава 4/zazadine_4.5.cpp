#include <iostream>
int main() {
	system("chcp 1251");
	std::cout << "Введите Начало Диапазона: ";
	int nachalo = 0;
	std::cin >> nachalo;
	std::cout << "Введите Конец Диапазона: ";
	int konec = 0;
	std::cin >> konec;
	int sum = 0;
	for (int i = nachalo; ((nachalo > konec) ? i >= konec:i <= konec); ((nachalo > konec) ? i-- : i++)) {
		std::cout << i << " ";
		sum += i;

	}
	std::cout << "Сумма: " << sum;
}