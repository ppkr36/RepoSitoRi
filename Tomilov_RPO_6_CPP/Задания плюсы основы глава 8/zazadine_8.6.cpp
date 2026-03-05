#include <iostream>
const int rows = 10;
const int columns = 10;
void myMassive(int arr[][columns]) {
	for (int i = 0; i < rows; i++) {
		std::cout << "\n";	
		for (int j = 0; j < columns; j++) {
			std::cout << arr[i][j] << " ";
		}
	}
}
int myMax(int arr[][columns]) {
	int max = arr[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (arr[i][j] > max) max = arr[i][j];
		}
	}return max;
}
int myMin(int arr[][columns]) {
	int min = arr[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (arr[i][j] < min) min = arr[i][j];
		}
	}return min;
}
int main() {
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	int arr[rows][columns];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = rand() % 10;
		}
	}
	myMassive(arr);
	std::cout << "\n" << "Максимальное значение массива через функцию: " << myMax(arr);
	std::cout << "\n" << "Минимальное значение массива через функцию: " << myMin(arr);
		
	
}