#include <iostream>
int main() {
	system("chcp 1251");
	double num1, num2, num3, num4;
	std::cout << "1 число: "; std::cin >> num1; std::cout << "2 число: "; std::cin >> num2; std::cout << "3 число: "; std::cin >> num3; std::cout << "4 число: "; std::cin >> num4;
	std::cout << num3 << ", " << num2 << ", " << num4 << ", " << num1;
	return 0;
}