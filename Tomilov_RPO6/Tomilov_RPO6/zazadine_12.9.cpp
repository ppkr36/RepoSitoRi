#include <iostream>
#include <string>
int main() {
	system("chcp 1251");
	std::string str;
	std::cout << "Введите строку: ";
	std::getline(std::cin, str);
	double kirill = 0, latin = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i)>='А' && str.at(i) <= 'я' || str.at(i) == 'ё' || str.at(i) == 'Ё') {
			kirill++;
			std::cout << str.at(i) << " ";
		}
	}
	std::cout << "\n" << kirill;
	std::cout << '\n';
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) >= 'A' && str.at(i) <= 'Z' || str.at(i) >= 'a' && str.at(i) <= 'z') {
			latin++;
			std::cout << str.at(i) << " ";
		}
	}
	double sum = kirill + latin;
	double procent_kirila = kirill / sum * 100;
	double procent_latini = latin / sum * 100;
	std::cout << "Процент кирилицы " << procent_kirila << "%";
	std::cout << "\n" << "Процент латиницы " << procent_latini << "%";
	

}