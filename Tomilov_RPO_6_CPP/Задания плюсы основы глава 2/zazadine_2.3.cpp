#include <iostream>
int main() {
	system("chcp 1251");
	int x, t, g, k;
	std::cout << "¬ведите значение переменных";
	std::cin >> x >> t >> g;
	k = (x / 2 + (t + t + t) - (g + g) - t * t);
	std::cout << "—умма чисел: " << k;
	return 0;
}