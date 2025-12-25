#include <iostream>
#include <vector>
int main(){
	system("chcp 1251");
	std::cout << "Введите кол-во элементов массива: ";
	int size;
	std::cin >> size;
	std::vector<int>vector(size);
	int sum = 0;
	for (int i = 0; i < size; i++) {
		std::cout << "Вводите: ";
		std::cin >> vector.at(i);
		sum += vector.at(i);
	}
	int min = vector.at(0), max = vector.at(0);
	for (int i = 0; i < size; i++) {
		if (vector.at(i) < min) min = vector.at(i);
		if (vector.at(i) > max) max = vector.at(i);
	}
	std::cout << "\nМаксимальный элемент " << max << "\nМинимальный элемент " << min << "\nСумма " << sum << std::endl;
}