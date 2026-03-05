#include <iostream>
int main() {
	double num1, num2, num3, max;
	std::cin >> num1 >> num2 >> num3;
	max = std::max({ abs(num1), abs(num2), abs(num3) });
	std::cout << max << '\n';
	std::cout << abs(num1) + abs(num2) + abs(num3)<< '\n';
	std::cout << abs(num1 + num2 + num3) << '\n';
}