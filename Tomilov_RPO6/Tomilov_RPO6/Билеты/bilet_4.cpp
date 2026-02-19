#include <iostream>
int main() {
	int num1, num2, num3, cho = 0;
	while (true) {
	std::cout << "1.min in 3\n 2.abs\n3.exit\n";
		std::cin >> cho;
		if (cho != 3) {
			std::cin >> num1 >> num2 >> num3;
			int min = std::min({ num1, num2, num3 });
			std::cout << min << '\n';
		}
		if (cho == 2) {
			std::cin >> num1;
			std::cout << abs(num1) << '\n';
		}
	}
}