#include <iostream>
#include <string>
#include <vector>
#include "zazadine_5.1(Plate).hpp"

int main() {
	system("chcp 1251");
	std::string material, proiz;
	double price;
	int height, width, thickness, weight, index;
	std::vector<Plate> plitki;
	plitki.emplace_back();
	plitki.emplace_back("Картон","ООО Блошиный Рынок",5.0,260,100,1,20);
	plitki.emplace_back("Песок","Природа",0.0,99000000, 99000000, 4000, 324000000);
	int cho = 0;
	while (cho != 3) {
		for (int i = 0; i < plitki.size(); i++) {
			plitki.at(i).printPlitka();
		}
		std::cout << "\n1.Добавить плитку\n2.Убрать плитку\n>_: ";
		std::cin >> cho;
		if (cho == 1) {
			std::cin.ignore(1024, '\n');
			std::cout << "Введите материал: ";
			std::getline(std::cin, material);
			std::cout << "Введите производителя: ";
			std::getline(std::cin, proiz);
			std::cout << "Введите цену: ";
			std::cin >> price;
			std::cout << "Введите высоту: ";
			std::cin >> height;
			std::cout << "Введите ширину: ";
			std::cin >> width;
			std::cout << "Введите толщину: ";
			std::cin >> thickness;
			std::cout << "Введите вес: ";
			std::cin >> weight;
			plitki.emplace_back(material, proiz, price, height, width, thickness, weight);
			system("cls");
		}
		if (cho == 2) {
			std::cout << "Введите индекс плитки для удаления: ";
			std::cin >> index;
			plitki.erase(plitki.begin()+index);
			system("cls");
		}
	}
}