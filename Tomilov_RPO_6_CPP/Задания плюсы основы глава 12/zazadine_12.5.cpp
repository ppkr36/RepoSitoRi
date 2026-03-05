#include <iostream>
int myFunc(char string[], char cha) {
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == cha) {
			return i;
		}
		else {
			return -1;
		}
	}
}
int main() {
	system("chcp 1251");
	char string[99];
	char cha;
	int count = 0;
	std::cout << "Введите строку: ";
	std::cin >> string;
	std::cout << "Введите букву: ";
	std::cin >> cha;
	std::cin.clear();
//	for (int i = 0; i < strlen(string); i++) {
//		if (string[i] == cha) {
//			std::cout << "\n" << "Символ " << cha << " найден и он  " << i+1 << " по счету";
//			count++;
//		}
//	}
//	if (count == 0) std::cout << "Такой буквы нет";
	if (myFunc(string, cha) != 0) {
		std::cout << "\n" << "Символ " << cha << " найден и он  " << myFunc(string, cha) + 1 << " по счету";
	}
	else {
		std::cout << "Такой буквы нет";
	}
	
	
}