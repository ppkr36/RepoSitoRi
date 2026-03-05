#include <iostream>
int main() {
	system("chcp 1251");
	int choice = 0;
	int arr[10];
	std::cout << "1.от 0 до 10\n2.от -10 до 10\n:>";
	std::cin >> choice;
	for (int i = 0; i < 10; i++) {
		if (choice == 1) {
			arr[i] = rand() % 11;
			std::cout << arr[i] << " ";
		}
		
		if (choice == 2) {
			arr[i] = rand() % 21 - 10;
			std::cout << arr[i] << " ";
		}
		if (choice != 1 && choice != 2) {
			std::cout << "Неверно...";
		}
	}
}