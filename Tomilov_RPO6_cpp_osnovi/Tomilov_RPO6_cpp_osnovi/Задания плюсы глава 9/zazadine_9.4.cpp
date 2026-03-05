#include <iostream>
int main() {
	system("chcp 1251");
	int size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;
	int* arr = new int[size];
	int cho = 0;
	std::cout << "Введите элементы массива";
	for (int i = 0; i < size; i++) {
		std::cout << "\n" << "arr" << "[" << i << "]" << " = ";
		std::cin >> arr[i];
	}
	std::cout << "Введите как делать " << "\n" << "1.По возростанию" << "\n" << "2.По убыванию" << "\n";
	std::cin >> cho;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (cho == 1) {
				if (arr[j] > arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
				}
			}
			if (cho == 2) {
				if (arr[j] < arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
}
