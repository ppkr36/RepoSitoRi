#include <iostream>
#include <string>
#include <vector>
#include "bed.hpp"
int main() {
	system("chcp 1251");
	std::cout << "Введите кол-во кроватей: ";
	int amount, choice;
	std::cin >> amount;
	std::vector<Bed> beds(amount);
	std::cout << "1.Заполнить самому\n2.По умолчанию\n>_";
	std::cin >> choice;
	for (int i = 0; i < amount; i++) {
		if (choice == 1) {
			beds.at(i).redact();
		}
	}

	for (int i = 0; i < amount; i++) {
		beds.at(i).output();
	}
	
}