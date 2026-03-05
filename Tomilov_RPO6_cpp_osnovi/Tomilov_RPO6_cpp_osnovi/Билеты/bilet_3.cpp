#include <iostream>
int main() {
	int start, end, sum =0;
	std::cin >> start >> end;
	if (start < end) {
		for (start; start <= end; start++) {
			sum += start;
			std::cout << start << ' ';
		}
	}
	else {
		for (start; start >= end; start--) {
			sum += start;
			std::cout << start << ' ';
		}
	}
	std::cout << sum;
}