#include <iostream>
#include <string>
int main() {
	system("chcp 1251");
	std::cout << "Введите строку: ";
	std::string stri;
	std::getline(std::cin, stri);
	int count_nums = 0, count_space = 0;
	for (int i = 0; i < stri.length(); i++) if (isdigit(stri.at(i))) count_nums++;
	for (int i = 0; i < stri.length(); i++) if (isspace(stri.at(i))) count_space++;
	std::cout << "Кол-во цифр: " << count_nums<<'\n' << "Кол-во пробелов: " << count_space << '\n' << "Первый символ строки: " << stri.front() << " Последний символ строки: " << stri.back();
}