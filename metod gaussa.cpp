#include <iostream>
int main() {
	double arr[3][3]{ {5,2,-1},{-4, 7, 3},{2, -2, 4} };
	double b1 = 12, b2 = 24, b3 = 9,x3,x2,x1;
	for (int i = 0; i < 3; i++) {
		std::cout << "\n";
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i][j] << '\t';
		}
	}
	//шаг 1
	std::cout << '\n';
	std::cout << '\n';
	arr[1][0] += arr[2][0]*2;
	arr[1][1] += arr[2][1]*2;
	arr[1][2] += arr[2][2]*2;
	b2 = b2 + b3 * 2;
	arr[2][0] -= arr[0][0]*2/5;
	arr[2][1] -= arr[0][1]*2/5;
	arr[2][2] -= arr[0][2]*2/5;
	b3 = b3 - b1 * 2 / 5;
	for (int i = 0; i < 3; i++) {
		std::cout << "\n";
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i][j] << '\t';
		}
	}
	std::cout << '\n';
	std::cout << '\n';
	//шаг 2
	arr[2][0] += arr[1][0] * 2.8 / 3;
	arr[2][1] += arr[1][1] * 2.8 / 3;
	arr[2][2] += arr[1][2] * 2.8 / 3;
	arr[2][1] = 0;
	b3 = b3 + b2 * 2.8 / 3;
	for (int i = 0; i < 3; i++) {
		std::cout << "\n";
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i][j] << '\t';
		}
	}
	std::cout << '\n';
	std::cout << '\n';
	//Решение
	x3 = b3 / arr[2][2];
	std::cout << "x3 = " << x3;
	x2 = ((b2 - arr[1][2]*x3)/3);
	std::cout << "\nx2 = " << x2;
	x1 = (b1 - arr[0][2] * x3 - arr[0][1] * x2) / arr[0][0];
	std::cout << "\nx1 = " << x1;
}

