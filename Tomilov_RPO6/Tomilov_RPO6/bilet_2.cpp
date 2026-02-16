#include <iostream>
int main() {
	int num = 0, mul = 1, count = 0, max = 0;
	while (num >= 0) {
		std::cin >> num;
		if (num >= 0) {
			mul *= num;
			count++;
			if (num > max) max = num;
		}
	}
	std::cout << mul << '\n';
	std::cout << count << '\n';
	std::cout << max << '\n';
}