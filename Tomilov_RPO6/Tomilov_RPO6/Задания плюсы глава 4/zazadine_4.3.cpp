#include <iostream>
int main() {
	system("chcp 1251");
	int num1, num2, num3, num4, sum = 0;
	std::cout << "Ââåäèòå 4 ÷èñëà: ";
	std::cin >> num1 >> num2 >> num3 >> num4;
	sum += num1;
	sum += num2;
	sum += num3;
	sum += num4;
	std::cout << "Ñóììà: " << sum;
}