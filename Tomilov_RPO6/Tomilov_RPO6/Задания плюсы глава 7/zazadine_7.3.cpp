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
	int cho;
	std::cout << "\n" << "Введите строку которую вывести: ";
	std::cin >> cho;
	std::cout << "Вот " << cho << " строка: ";
		for (int j = 0; j < columns; j++) {
			std::cout << arr[cho-1][j] << "\t";
		}
		std::cout << "\nКакое число найти во всём массиве? : ";
		int num;
		std::cin >> num;
		for (int i = 0; i < rows; i++) 
			for (int j = 0; j < columns; j++) {
				if (num == arr[i][j]) std::cout << "Число найдено по координатам " << "[" << i  << "] " << "[" << j << "]" << "\n";

			}
		
}