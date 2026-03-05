#include <iostream>
int main() {
	system("chcp 1251");
	std::cout << "¬ведите сколько раз: ";
	int hello = 0;
	std::cin >> hello;
	for (int i = 0; i <= hello; i++) std::cout << i << ". Hello underworld!\n";
}