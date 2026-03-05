#include <iostream>
int mySum(int num) {
	int sum = 0;
	for (int i = 0; ((num < 0) ? i >= num:i <= num); ((num < 0) ? i-- : i++)) {
		sum += i;
	}
	return sum;
}
int main() {
	system("chcp 1251");
	int num = 0;
	std::cout << "Введите число: ";
	std::cin >> num;
	std::cout << "Ответ: " << mySum(num);
	
}