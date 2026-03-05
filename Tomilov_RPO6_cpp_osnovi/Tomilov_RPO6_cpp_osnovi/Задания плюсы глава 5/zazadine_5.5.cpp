#include <iostream>
int main() {
	system("chcp 1251");
	int num;
	std::cout << "¬ведите число: ";
	std::cin >> num;
	if (num < 0) num * -1;
	if (num >= 100000 && num <= 999999) {
		std::cout << "¬ведЄнное число - шестизначное";
	}
	else std::cout << "¬ведЄнное число - не шестизначное";

}