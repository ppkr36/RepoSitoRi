#include <iostream>


















int main() {
	system("chcp 1251");
	int size;
	srand(static_cast<int>(time(0)));
	std::cout << "Введите размер одномерного массива: ";
	std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 201-100;
		std::cout << arr[i] << " ";
	}
	int cho = 1;
	int index1;
	int index2;
	while (cho != 0) {
		std::cout << "\nЧто сделать? \n1.Замена 2х элементов по индексу \n2.Удалить элемент массива\n3.Сортировка по возростанию\n>_ ";
		std::cin >> cho;
		if (cho == 1) {
			std::cout << "Введите индексы 2х элементов: ";
			std::cin >> index1 >> index2;
			std::swap(arr[index1], arr[index2]);
			for (int i = 0; i < size; i++) { std::cout << arr[i] << ' '; }
			if (cho == 2) {
				std::cout << "какой по счету элемента для удаления: ";
				std::cin >> index1;
				for (int i = 0; i < size; i++) {
					if (arr[i] == arr[index1 - 1]) {
						std::cout << " ";
					}
					else std::cout << arr[i] << ' ';
				}
			}
			if (cho == 3) {
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size - 1; j++) {
						if (arr[j] > arr[j + 1]) {
							std::swap(arr[j], arr[j + 1]);
						}
					}
				}
				for (int i = 0; i < size; i++) std::cout << arr[i] << ' ';
			}
		}
	}
}