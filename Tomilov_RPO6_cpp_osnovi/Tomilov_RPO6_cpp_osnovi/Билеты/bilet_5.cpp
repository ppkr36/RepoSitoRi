#include <iostream>
double multFunc(double osn, int step) {
		double total = osn;
	for (int i = 0; i < step-1; i++) {
		osn *= total;
	}
	return osn;
}
int main() {
	double osn = 0;
	int step = 0;
	std::cin >> osn >> step;
	std::cout << multFunc(osn, step);
}