#include <iostream>
int myDegree(int osn, int step) {
	int degree = 1;
	for (int i = 0; i < step; i++) {
			degree *= osn;
		}
return degree;
}

int main() {
	system("chcp 1251");
	int osn;
	std::cout << "¬ведите число: ";
	std::cin >> osn;
	int step;
	std::cout << "¬ведите степень: ";
	std::cin >> step;
	std::cout << "„исло в степени: " << myDegree(osn, step);

}