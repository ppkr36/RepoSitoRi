#include <iostream>
int main() {
	int arr[3][3], sum = 0, max, min;
	for (int i = 0; i < 3; i++) {
		std::cout << "\n";
		for (int j = 0; j < 3; j++) {
			arr[i][j] = rand() % 10;
			sum += arr[i][j];
			std::cout << arr[i][j] << " ";
		}
	}
	std::cout <<'\n' << sum << '\n';
	max = arr[0][0], min = arr[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] < min) min = arr[i][j];
			if (arr[i][j] > max) max = arr[i][j];
		}
	}
	std::cout << max << '\n' << min;

}