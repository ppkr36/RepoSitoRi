#include <iostream>
#include <fstream>
int main() {
	srand(static_cast<int>(time(0)));
	system("chcp 1251");
	int rows, cols;
	double min, max, sum = 0, avg = 0;
	std::cout << "Введите кол-во строк: ";
	std::cin >> rows;
	std::cout << "Введите кол-во столбцов: ";
	std::cin >> cols;
	double** arr = new double* [rows];
	int count = 0;
	for (int i = 0; i < rows; i++) {
		arr[i] = new double[cols];
		for (int j = 0; j < cols; j++) {
			arr[i][j] = (rand() % 1001) / 10.0;
			count++;
		}
	}
	max = arr[0][0];
	min = arr[0][0];
	std::fstream file("numbers.txt");
	file << "Матрица: ";
	for (int i = 0; i < rows; i++) {
		file << '\n';
		for (int j = 0; j < cols; j++) {
			sum += arr[i][j];
			if (arr[i][j] > max) max = arr[i][j];
			if (arr[i][j] < min) min = arr[i][j];
			file << arr[i][j] << "\t";
		}
	}
	avg = sum / count;
	file << "\nМинимум: " << min;
	file << "\nМаксимум: " << max;
	file << "\nСумма: " << sum;
	file << "\nСреднее: " << avg;
	file.close();
}