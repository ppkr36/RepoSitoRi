#include <iostream>

void myMul(int num1, int num2) {
	int mul = num1 * num2;
	std::cout << "	" << mul;
	
	
}
void myMessage() {
	std::cout << "\nЗадание 2: ";
	std::cout << "\n	Окак";
	 
}
void myCycle() {
	std::cout << "\nЗадание 3: \n	";
	for (int i = -19; i < 24; i++) {
		std::cout << i << " ";
	}
	
}

int main() {
	system("chcp 1251");
	int cho1, cho2;
	std::cout << R"(Задание 1:
	Введите 2 числа: )";
	std::cin >> cho1 >> cho2;
	myMul(cho1, cho2);
	myMessage();
	myCycle();
	
	
}