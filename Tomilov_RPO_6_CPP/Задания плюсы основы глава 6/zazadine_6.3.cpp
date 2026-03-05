#include <iostream>
int main() {
	system("chcp 1251");
	const int dlina = 5;
	int arr[dlina];
	int max = 0, min = 0;
	double avg = 0;
	double sum = 0;
	std::cout << "Заполните: ";
	for (int i = 0; i < dlina; i++) {
		std::cin >> arr[i];
		sum += arr[i];
		std::cout  << arr[i] << " ";
	}
	avg = (sum / dlina);
	std::cout << "\nСумма введённых чисел: " << sum << " Среднее значение: " << avg;
	
	min = arr[0]; max = arr[0];
	for (int i = 0; i < dlina; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	std::cout << "\nНаибольшее: " << max << " Наименьшее: " << min;
	

}	


