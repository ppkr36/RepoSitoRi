#include <iostream>
int main() {
	system("chcp 1251");
	int cho = 0;
	std::cout << "Как вывести массив?\n1.Чётные\n2.Нечётные\n:>";
	std::cin >> cho;
	int arr[100];
	
	for (int i = 0; i < 100; i++) {
		arr[i] = i - 50;
		if (cho == 1 && i % 2 == 0) {
			std::cout << arr[i] << " ";
		}
		if (cho == 2 && i % 2 != 0) {
			std::cout << arr[i] << " ";
		}
	}
}


