#include <iostream>
int main() {
	system("chcp 1251");
	const int dlina = 7;
	double arr[dlina];
	int celoe = 0;

	std::cout << "Введите элементы массива: ";
	for (int i = 0; i < dlina; i++) {
		std::cin >> arr[i];
	}
	std::cout << "Отрицательные: ";
	for (int i = 0; i < dlina; i++) {
		if (arr[i] < 0) {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << "Нецелые: ";
		for (int i = 0; i < dlina; i++) {
			celoe = arr[i];
			if ((arr[i] - celoe) != 0) {
				std::cout << arr[i] << " ";
			}
		}
		std::cout << "Целые положительные: ";
		for (int i = 0; i < dlina; i++) {
			celoe = arr[i];
			if (((arr[i] - celoe) == 0)&& arr[i] > 0) {
				std::cout << arr[i] << " ";
			}
		}
	
}