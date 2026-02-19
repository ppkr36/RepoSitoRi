#include <iostream>
#include <string>
#include <fstream>
int evclidFunc(int num, int num2) {
	if (num2 == 0) {
		return num;
	}
	else evclidFunc(num2, num % num2);
}
int main() {
	system("chcp 1251");
	int num1, num2;
	std::cout << "¬ведите 2 числа: ";
	std::cin >> num1 >> num2;
	int nod = evclidFunc(num1, num2);
	std::cout << " уда ввести?\n1.в файл\n2.в консоль\n>_";
	int cho = 0;
	std::cin >> cho;
	if (cho == 1) {
		std::string name;
		std::cout << "¬ведите им€ файла: ";
		std::cin >> name;
		std::ofstream file(name);
		file << nod;
		file.close();
	}
	if (cho == 2) {
		std::cout << nod;
	}
}