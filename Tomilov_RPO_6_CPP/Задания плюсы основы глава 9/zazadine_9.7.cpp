#include <iostream>
int main() {
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	int rows;
	std::cout << "Ведите кол-во строк: ";
	std::cin >> rows;
	int cols;
	std::cout << "Ведите кол-во столбцов: ";
	std::cin >> cols;
	int cho = 0;
	int** arr_x2 = new int* [rows];
	double sum = 0;
	double avg;
	int amount = rows * cols;
	std::cout << "Как заполнить? \n 1.С клавиатуры \n 2.Рандом полнейший \n Ввод: ";
	std::cin >> cho;
	for (int i = 0; i < rows; i++) {
		arr_x2[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			if (cho == 1) {
				std::cout << "\n" << "arr_x2 " << "[" << i << "]" << "[" << j << "]" << " = ";
				std::cin >> arr_x2[i][j];
			}
			if (cho == 2) {
				arr_x2[i][j] = rand() % 9 + 1;
			}
			sum += arr_x2[i][j];
		}
	}
	for (int i = 0; i < rows; i++) {
		std::cout << std::endl;
		for (int j = 0; j < cols; j++) {
			std::cout << arr_x2[i][j] << "\t";
		}
	}
	std::cout << "\n";
	avg = sum / amount;
	std::cout << "\n" << "Общее кол-во элементов -> " << amount << "\n" << "Среднее значение -> " << avg << "\n";
	for (int i = rows -1; i >= 0; i--) {
		std::cout << std::endl;
		for (int j = cols-1; j >= 0; j--) {
			std::cout << arr_x2[i][j] << "\t";
		}
	}
}