#include <iostream>
int main() {
	system("chcp 1251");
	int arr_size;
	std::cout << "Введите размер массива: " << "\n";
	std::cin >> arr_size;
	int* arr = new int[arr_size];
	double sum = 0;
	double avg = 0;
	


	std::cout << "Введите элементы массива: " << "\n";
	for (int i = 0; i < arr_size; i++) {
		std::cin >> arr[i];
		sum += arr[i];

	}
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < arr_size; i++) {
		sum += arr[i];
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) min = arr[i];

	}
	avg = sum / arr_size;
	std::cout << "Сумма элементов: " << sum << "\n";
	std::cout << "Среднее арифметическое: " << avg << "\n";
	std::cout << "Максимальный и минимальный элемент массива: " << max << " " << min;
}