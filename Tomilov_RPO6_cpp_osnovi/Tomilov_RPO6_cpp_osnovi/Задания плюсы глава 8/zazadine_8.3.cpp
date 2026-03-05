#include <iostream>
int main() {
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	const int lenght = 10;
	int arr[lenght];
	for (int i = 0; i < lenght; i++) {
		*(arr + i) = rand() % 10;
		std::cout << *(arr + i) << " ";
		int* ptr = &i;
	}
	int* ptr1 = new int;
	std::cout << "\n" << "Введите число для поиска: ";
	std::cin >> *ptr1;
	for (int i = 0; i < lenght; i++) {
		if (*(arr + i) != *ptr1) {
			std::cout << "\n" << "Найдено несоответсвие: " << "arr [" << i << "]" ;
		}
	}
	delete ptr1;



}