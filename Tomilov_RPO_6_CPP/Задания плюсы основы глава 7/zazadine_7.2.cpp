#include <iostream>
int main() {
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	const int rows = 5, columns = 8;
	int arr5x8[rows][columns];
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		std::cout << "\n";
		for (int j = 0; j < columns; j++) {
			arr5x8[i][j] = rand() % 201 -100;
			std::cout << arr5x8[i][j] << "\t";
			sum += arr5x8[i][j];
		}
	}
	int max = arr5x8[0][0], min = arr5x8[0][0];
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < columns; j++) {
			if (min < arr5x8[i][j]) min = arr5x8[i][j];
			if (max > arr5x8[i][j]) max = arr5x8[i][j];
	}
	std::cout <<"\n" << "Сумма элементов: " << sum << "\n";
	std::cout << "Максимальный элемент: " << max << "\n";
	std::cout << "Минимальный элемент: " << min;
}