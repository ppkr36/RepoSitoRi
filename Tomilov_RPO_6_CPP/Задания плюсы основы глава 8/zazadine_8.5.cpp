#include <iostream>
void myMult(int& num,const int& mult) {
	num *= mult;
}
int main() {
	system("chcp 1251");
	int num = 0;
	std::cout << "¬ведите значение: ";
	std::cin >> num;
	int mult = 0;
	std::cout <<"\n"<< "¬ведите множитель: ";
	std::cin >> mult;
	myMult(num, mult);
	std::cout << "\n" << "„исло после умножени€: " << num << "\n";
}
