#include <iostream>

int myMaxArray(int* arr, int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) if (arr[i] > max) max = arr[i];
	return max;
}
int myMinArray(int* arr, int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++) if (arr[i] < min) min = arr[i];
	return min;
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 10;
	}
	std::cout << myMaxArray(arr, 10) << '\n';
	std::cout << myMinArray(arr, 10) << '\n';
}