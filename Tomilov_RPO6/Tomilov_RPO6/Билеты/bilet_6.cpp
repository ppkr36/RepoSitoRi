#include <iostream>
int main() {
	float arr[7];
	int celoe;
	for (int i = 0; i < 7; i++) {
		std::cin >> arr[i];
		if (arr[i] > 0) std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < 7; i++) {
		celoe = arr[i];
		if (celoe == arr[i]) std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < 7; i++) {
		celoe = arr[i];
		if (celoe != arr[i] && arr[i] < 0) std::cout << arr[i] << ' ';
	}
}