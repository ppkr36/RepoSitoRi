#include <iostream>
int main() {
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	int size = rand() % 30 + 1;
	int* arr_x1 = new int[size];
	for (int i = 0; i < size; i++) {
		arr_x1[i] = rand() % 201 - 100;
		std::cout << arr_x1[i] << " ";
	}
	std::cout << "\n";std::cout << "\n";
	int rows = rand() % 9 + 1;				
	int cols = rand() % 9 + 1;
	int** arr_x2 = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr_x2[i] = new int[cols];
		std::cout << std::endl;
		for (int j = 0; j < cols; j++) {
			arr_x2[i][j] = rand() % 100 + 100;
			std::cout << arr_x2[i][j] << "\t";
		}
	}
	std::cout << "\n";std::cout << "\n";
	int pages;
	std::cout <<"Введите кол-во страниц: " << "\n";
	std::cin >> pages;
	std::cout << "Введите кол-во строк: " << "\n";
	std::cin >> rows;
	std::cout << "Введите кол-во столбцов: " << "\n";
	std::cin >> cols;

	int*** arr_x3 = new int** [pages];
	for (int i = 0;i < pages; i++) {
		arr_x3[i] = new int* [rows];
		std::cout << "НОВАЯ СТРАНИЦА" << "\n";
		for (int j = 0; j < rows; j++) {
			arr_x3[i][j] = new int[cols];
			for (int k = 0; k < cols; k++) {
				arr_x3[i][j][k] = rand() % 10;
				std::cout << arr_x3[i][j][k] << "\t";
			}
			std::cout << "\n";
			
		}
	}
	
	
	
	
	
	

}