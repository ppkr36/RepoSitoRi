#include <iostream>
int main() {
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	const int rows = 7, columns = 5;
	int arr[rows][columns];
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		std::cout << "\n";
		for (int j = 0; j < columns; j++) {
			arr[i][j] = rand() % 201 - 100;
			std::cout << arr[i][j] << "\t";
			sum += arr[i][j];
		}
	}
	std::cout << "\nНапишите координаты числа которое нужно умножить на 2: ";
	int i2, j2;
	std::cin >> i2 >> j2;
	int max = arr[0][0], min = arr[0][0];
	if ((i2 >= rows || i2 < 0) || (j2 >= columns || j2 < 0)) {
		std::cout << "Некорректный индекс";
	
	}
	else {
		arr[i2][j2] *= 2;
		for (int i = 0; i < rows; i++) {
			std::cout << "\n";
			for (int j = 0; j < columns; j++) {
				std::cout << arr[i][j] << "\t";
				if (min < arr[i][j]) min = arr[i][j];
				if (max > arr[i][j]) max = arr[i][j];
			}
		}
		std::cout << "\n" << "Минимальный элемент: " << min << "\n";
		std::cout << "Максимальный элемент: " << max;
	}
}