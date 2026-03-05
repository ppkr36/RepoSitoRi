#include <iostream>
int main() {
	int arr[3]{22, -16, 36};
	for (int i = 0; i < 3; i++) {
		std::cout << arr[i] << " ";
	}
	for (int i = 2; i > -1; i--) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n" << arr[-1];			
	std::cout << "\n" << arr[4];
}