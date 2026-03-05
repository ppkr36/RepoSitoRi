#include <iostream>
int main() {
	system("chcp 1251");
	double num1, num2, num3, num4;
	std::cout << "¬ведите все елементы массива: ";
	std::cin >> num1 >> num2 >> num3 >> num4;
	double arr2x2[2][2] = { {num1, num2}, {num3, num4} };
	std::cout << arr2x2[0][0] << " " << arr2x2[0][1] << "\n" << arr2x2[1][0] << " " << arr2x2[1][1] << "\n";
	std::cout << arr2x2[3][3] << "\n";
	std::cout << arr2x2[-1][-1] << "\n";
	std::cout << arr2x2[0] << "\n";
	std::cout << arr2x2[1];
	


}