#include <iostream>
#include <string>
int main() {
	system("chcp 1251");

	//Метод Гаусса 1
	// 
	//double arr[3][3]{ {5,2,-1},{-4, 7, 3},{2, -2, 4} };
	//double b1 = 12, b2 = 24, b3 = 9,x3,x2,x1;
	//for (int i = 0; i < 3; i++) {
	//	std::cout << "\n";
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << arr[i][j] << '\t';
	//	}
	//}
	////шаг 1
	//std::cout << '\n';
	//std::cout << '\n';
	//arr[1][0] += arr[2][0]*2;
	//arr[1][1] += arr[2][1]*2;
	//arr[1][2] += arr[2][2]*2;
	//b2 = b2 + b3 * 2;
	//arr[2][0] -= arr[0][0]*2/5;
	//arr[2][1] -= arr[0][1]*2/5;
	//arr[2][2] -= arr[0][2]*2/5;
	//b3 = b3 - b1 * 2 / 5;
	//for (int i = 0; i < 3; i++) {
	//	std::cout << "\n";
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << arr[i][j] << '\t';
	//	}
	//}
	//std::cout << '\n';
	//std::cout << '\n';
	////шаг 2
	//arr[2][0] += arr[1][0] * 2.8 / 3;
	//arr[2][1] += arr[1][1] * 2.8 / 3;
	//arr[2][2] += arr[1][2] * 2.8 / 3;
	//arr[2][1] = 0;
	//b3 = b3 + b2 * 2.8 / 3;
	//for (int i = 0; i < 3; i++) {
	//	std::cout << "\n";
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << arr[i][j] << '\t';
	//	}
	//}
	//std::cout << '\n';
	//std::cout << '\n';
	////Решение
	//x3 = b3 / arr[2][2];
	//std::cout << "x3 = " << x3;
	//x2 = ((b2 - arr[1][2]*x3)/3);
	//std::cout << "\nx2 = " << x2;
	//x1 = (b1 - arr[0][2] * x3 - arr[0][1] * x2) / arr[0][0];
	//std::cout << "\nx1 = " << x1;

	//Метод Гаусса 2
	//double arr[3][3]{{3,-1,4},{1, 3, 1},{2, 1, -3}};
	//double b1 = 15, b2 = 18, b3 = 11, x1,x2,x3;
	//for (int i = 0; i < 3; i++) {
	//		std::cout << "\n";
	//		for (int j = 0; j < 3; j++) {
	//			std::cout << arr[i][j] << '\t';
	//		}
	//	}
	//std::cout << "Шаг 0		b1->" << b1 << "		b2->" << b2 << "		b3->" << b3;
	//std::cout << '\n';
	//std::cout << '\n';
	////шаг 1
	// 
	//arr[1][0] -= arr[2][0] / 2;
	//arr[1][1] -= arr[2][1] / 2;
	//arr[1][2] -= arr[2][2] / 2;
	//b2 -= b3 / 2;
	//arr[2][0] -= arr[0][0] * 2 / 3;
	//arr[2][1] -= arr[0][1] * 2 / 3;
	//arr[2][2] -= arr[0][2] * 2 / 3;
	//b3 -= b1 * 2 / 3;
	//for (int i = 0; i < 3; i++) {
	//	std::cout << "\n";
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << arr[i][j] << '\t';
	//	}
	//}
	//std::cout << "Шаг 1		b1->" << b1 << "		b2->" << b2 << "		b3->" << b3;
	//std::cout << '\n';
	//std::cout << '\n';
	//// шаг 2
	//arr[1][0] /= 2.5;
	//arr[1][1] /= 2.5;
	//arr[1][2] /= 2.5;
	//arr[2][0] -= arr[1][0] * 5 / 3;
	//arr[2][1] -= arr[1][1] * 5 / 3;
	//arr[2][2] -= arr[1][2] * 5 / 3;
	//b2 /= 2.5;
	//b3 -= b2 * 5 / 3;
	//arr[2][1] = 0;
	//for (int i = 0; i < 3; i++) {
	//	std::cout << "\n";
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << arr[i][j] << '\t';
	//	}
	//}
	//std::cout << "Шаг 2		b1->" << b1 << "		b2->" << b2 << "		b3->" << b3;
	//std::cout << '\n';
	//std::cout << '\n';
	//x3 = b3 / arr[2][2];
	//std::cout << "x3 = " << x3;
	//x2 = ((b2 - arr[1][2]*x3)/1);
	//std::cout << "\nx2 = " << x2;
	//x1 = (b1 - arr[0][2] * x3 - arr[0][1] * x2) / arr[0][0];
	//std::cout << "\nx1 = " << x1;

	//Метод Крамера
	double arr[3][3]{{1,2,4},{-2, 1, -3},{3, -2, -5}};
	double b1 = -5, b2 = 10, b3 = 3,x1,x2,x3;
	std::string d;
	for (int i = 0; i < 3; i++) {
			std::cout << "\n";
			for (int j = 0; j < 3; j++) {
				std::cout << arr[i][j] << '\t';
			}
		}
	std::cout << "Шаг 0		b1->" << b1 << "		b2->" << b2 << "		b3->" << b3;
	std::cout << '\n';
	std::cout << '\n';
	for (int i = 0; i < 3; i++) {
		std::cout << "\n";
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i][j] << '\t';
		}
	}
	std::cout << "Шаг 1.Определитель основной матрицы		b1->" << b1 << "		b2->" << b2 << "		b3->" << b3;
	std::cout << '\n';
	std::cout << '\n';
	d = "это чо то сложно реализовать на плусах";
}

