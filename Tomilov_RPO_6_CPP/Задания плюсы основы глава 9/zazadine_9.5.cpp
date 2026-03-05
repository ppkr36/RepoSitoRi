#include <iostream>
int main() {
	system("chcp 1251 > nul");
	int size;
	std::cout << "Введите размер массива: " << "\n";
	std::cin >> size;
	int count = 0;
	int* arr = new int[size];
	int size2 = 0;
	std::cout << "Введите элементы массива";
	for (int i = 0; i < size; i++) {
		std::cout << "\n" "arr " << "[" << i << "]" << " = ";
		std::cin >> arr[i];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	int min = arr[0], max = arr[0];
	for (int i = 0; i < size; i++) {
		count = 0;
		if (max < arr[i])max = arr[i];
		if (min > arr[i])min = arr[i];
		for (int j = 0; j < size; j++) {
			if (arr[i] == arr[j] && i != j) {
				count++;
				std::cout << "Элемент " << arr[i] << " под индексом " << "[" << i << "]" << " Повторяется" << "\n";
			}
		}
		if (count == 0) {
			size2++;
		}
	}
	int* unique_arr = new int[size2];
	for (int i = 0; i < size; i++) {
		count = 0;
		for (int j = 0; j < size; j++) {
			if (arr[i] == arr[j] && i != j) {
				count++;
			}
		}
		if (count == 0) {
			for (int b = 0; b < size2; b++) {
				unique_arr[b] = arr[i];
				i++;
			}
		}	
	}
	std::cout << "arr" << "[" << size << "] ";
	for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
	std::cout << " --> unique_arr " << "[" << size2 << "] ";
	for (int i = 0; i < size2; i++) std::cout << unique_arr[i] << " ";
	std::cout << "\n" << "Минимальный элемент массива arr " << min;
	std::cout << "\n" << "Максимальный элемент массива arr " << max;

	

}