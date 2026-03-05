#include <iostream>
void recFunc(int num) {
		std::cout << num << " ";
		recFunc(num+1);

}
int main() {
	system("chcp 1251");
	int num = 1;
	recFunc(num);

}