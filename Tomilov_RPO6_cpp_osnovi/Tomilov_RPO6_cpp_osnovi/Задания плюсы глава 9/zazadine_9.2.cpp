#include <iostream>
int main() {
	system("chcp 1251");
	srand(static_cast <int>(time(0)));
	char choice;
	int arr_size;
	std::cout << "Введите кол-во элементов: " << "\n";
	std::cin >> arr_size;
	double sum = 0;
	double avg;
	int* arr = new int[arr_size];
	std::cout << "Как заполнить? [К]лавиатура [С]лучайные числа" << '\n';
	std::cin >> choice;

	if (choice == 'К' || choice == 'K') {
		std::cout << "Введите все элементы: "<< "\n";
		for (int i = 0; i < arr_size; i++) {
			std::cin >> arr[i];
		}
	}
	if (choice == 'С' || choice == 'C') {
		for (int i = 0; i < arr_size; i++) {
			arr[i] = rand() % 100 + 1;
		}
	}
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < arr_size; i++) {
		std::cout << arr[i] << " ";
		sum += arr[i];
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];

	}

	avg = sum / arr_size;
	std::cout << "\n" << "Сумма элементов: " << sum << "\n";
	std::cout << "Среднее арифметическое: " << avg << "\n";
	std::cout << "Максимальный и минимальный элемент массива: " << max << " " << min;

}