#include <iostream>
int main() {
	system("chcp 1251");
	int num1 = 0;
	int num2 = 0;
	int nachalo = 0;
	int konec = 0;

	std::cout << "Задание 1: ";
	for (int i = 0; i < 10; i++) {
		std::cout << i << " ";
	}
	std::cout << "\nЗадание 2: ";
	for (int i = -10; i < 10; i++) {
		std::cout << i << " ";
	}
	std::cout << "\nЗадание 3: ";
	for (int i = 15; i > -25; i--) {
		std::cout << i << " ";
	}
	std::cout << "\nЗадание 4: ";
	for (int i = 0; i < 100; i+=15) {
		std::cout << i << " ";
	}
	std::cout << "\nЗадание 5: ";
	std::cout << "Введите число больше 0: ";
	std::cin >> num1;
	for (int i = 0; i < num1 ; i++) {
		std::cout << i << " ";
	}
	std::cout << "\nЗадание 6: ";
	std::cout << "Введите число больше до 100: ";
	std::cin >> num2;
	for (int i = num2; i < 100; i++) {
		std::cout << i << " ";
	}
	std::cout << "\nЗадание 7: ";
	std::cout << "Введите начало диапазона: ";
	std::cin >> nachalo;
	std::cout << "Введите конец диапазона: ";
	std::cin >> konec;
	for (int i = nachalo; ((nachalo > konec) ? i > konec:i < konec);((nachalo > konec) ? i-- : i++)){
		std::cout << i << " ";
	}
	return 0;
}