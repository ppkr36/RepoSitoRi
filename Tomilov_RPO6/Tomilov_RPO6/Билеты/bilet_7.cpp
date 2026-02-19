#include <iostream>
int main() {
	double arr[5];
	double max, count = 0, min, sum = 0;
	for (int i = 0; i < 5; i++) {
		std::cin >> arr[i];
		count++;
		sum += arr[i];
		
	}
	min = arr[0][0], max = arr[0][0];
	double avg = sum / count;
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << ' ' << '\n';
		max = std::max({ arr[i], max });
		min = std::min({ arr[i], min });
	}
		std::cout << avg << '\n';
		std::cout << min << '\n' << max;

}