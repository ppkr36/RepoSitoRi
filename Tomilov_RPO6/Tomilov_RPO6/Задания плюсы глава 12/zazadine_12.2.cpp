#include <iostream>
int myFunc(char words[]) {
	int count = 0;
	while (words[count] != '\0') {
		words[0 + count];
		count++;
	}
	return count;
}
int main() {
	system("chcp 1251");
	char word[30];
	std::cout << "Введите строку максимум 30 элементов: ";
	std::cin >> word;
	std::cout << "\n";
	std::cout << "Размер строки = " << myFunc(word);
}