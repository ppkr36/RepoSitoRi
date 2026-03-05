#include <iostream>
#include <string>
#include <fstream>
int myEvclid(int num1, int num2) {
	if (num2 == 0) return num1;
	else myEvclid(num2, num1 % num2);
}
int main() {
	system("chcp 65001");
	int num1, num2, cho;
	std::cout << "Введите 2 числа: ";
	std::cin >> num1 >> num2;
	int nod = myEvclid(num1, num2);
	std::cout << "куда вывести 1.в файл 2.на экран: ";
	std::cin >> cho;
	if (cho == 1) {
	std::string name;
	std::cout << "Введите имя файла: ";
	std::cin >> name;
	std::ofstream file(name);
	file << nod;
	file.close();
	}
	if (cho == 2) {
		std::cout << '\n' << nod << '\n';
	}

}
	