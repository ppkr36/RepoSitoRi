#include <iostream>
const int size = 10;
void megaFunc(int num) {
	for (int i = 0; i < num; i++) {
		std::cout << "Hello, World!" << "\n";
	}
}
void megaFunc(int num, int num2) {
		std::cout << "Диапазон чисел между нимi: ";
	for (int i = num+1; i < num2; i++) {
		std::cout << i << " ";
	}
}
double megaFunc(double num) {
	int intnum = num;
	double pocle = num - intnum;
	while (num > intnum) {
		num *= 10;
		pocle *= 10;
		intnum = num;
	}
	return pocle;
}
double megaFunc(double num, double num2) {
	if (num > num2) return num;
	if (num2 > num) return num2;
}
int megaFunc(int arr[size]) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (min > arr[i])min = arr[i];
	}
	return min;
}

int main() {
	system("chcp 1251");
	int arr[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90,100};
	megaFunc(5);
	megaFunc(50, 100); std::cout << "\n";
	std::cout << megaFunc(555.555, 1000.1) << "\n";
	std::cout << megaFunc(51216771.652556) << "\n";
	std::cout << megaFunc(arr);
	std::cout << megaFunc(1.6);
}