#include <iostream>
template<typename T1, typename T2>
T1 findMax(T1 num1, T2 num2) {
	if (num1 > num2) return num1;
	if (num1 < num2) return num2;
}
template<typename T1, typename T2>
T1 findAvg(T1 num1, T2 num2) {
	T1 avg = (num1 + num2) / 2;
	return avg;
}
template<typename T1, typename T2>
T1 modulSum (T1 num1, T2 num2) {
	T1 mod_sum = num1 + num2;
	if (mod_sum < 0) {
		return mod_sum * -1;
	}
	else return mod_sum;
}
template<typename T1, typename T2>
T1 celoeSumNum(T1 num1, T2 num2) {
	T1 sum_num = num1 + num2;
	int int_num = 0;
	int_num = sum_num;
	return int_num;
}



int main() {
	system("chcp 1251");
	std::cout << "тип первой переменной\n1.int\n2.float\n3.double\n4.char\n>_ ";
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		int num1;
		std::cout << "Введите целое число: " << "\n";
		std::cin >> num1;
		std::cout << "тип второй переменной\n1.int\n2.float\n3.double\n4.char>_ ";
		std::cin >> choice;
		if (choice == 1) {
			int num2;
			std::cout << "Введите целое число: " << "\n";
			std::cin >> num2;
			std::cout << "Вот что можно сделать \n1. Поиск максимального\n2. Среднее арифметическое\n3. Модуль суммы\n4. Вывод целой части суммы чисел\n>_";
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "Максимальный элемент " << findMax(num1, num2);
			}
			if (choice == 2) {
				std::cout << "Среднее арифметическое " << findAvg(num1, num2);
			}
			if (choice == 3) {
				std::cout << "Модуль суммы " << modulSum(num1, num2);
			}
			if (choice == 4) {
				std::cout << "Вывод целой части суммы чисел " << celoeSumNum(num1, num2);
			}
		}
	}
	if (choice == 2) {
		float num1;
		std::cout << "Введите дробное число(float): " << "\n";
		std::cin >> num1;
		std::cout << "тип второй переменной\n1.int\n2.float\n3.double\n4.char>_ ";
		std::cin >> choice;
		if (choice == 2) {
			float num2;
			std::cout << "Введите дробное число(float): " << "\n";
			std::cin >> num2;
			std::cout << "Вот что можно сделать \n1. Поиск максимального\n2. Среднее арифметическое\n3. Модуль суммы\n4. Вывод целой части суммы чисел\n>_";
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "Максимальный элемент " << findMax(num1, num2);
			}
			if (choice == 2) {
				std::cout << "Среднее арифметическое " << findAvg(num1, num2);
			}
			if (choice == 3) {
				std::cout << "Модуль суммы " << modulSum(num1, num2);
			}
			if (choice == 4) {
				std::cout << "Вывод целой части суммы чисел " << celoeSumNum(num1, num2);
			}
		}
	}
	if (choice == 3) {
		double num1;
		std::cout << "Введите дробное число(double): " << "\n";
		std::cin >> num1;
		std::cout << "тип второй переменной\n1.int\n2.float\n3.double\n4.char>_ ";
		std::cin >> choice;
		if (choice == 3) {
			double num2;
			std::cout << "Введите дробное число(double): " << "\n";
			std::cin >> num2;
			std::cout << "Вот что можно сделать \n1. Поиск максимального\n2. Среднее арифметическое\n3. Модуль суммы\n4. Вывод целой части суммы чисел\n>_";
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "Максимальный элемент " << findMax(num1, num2);
			}
			if (choice == 2) {
				std::cout << "Среднее арифметическое " << findAvg(num1, num2);
			}
			if (choice == 3) {
				std::cout << "Модуль суммы " << modulSum(num1, num2);
			}
			if (choice == 4) {
				std::cout << "Вывод целой части суммы чисел " << celoeSumNum(num1, num2);
			}
		}
	}
	if (choice == 4) {
		char num1;
		std::cout << "Введите символ: " << "\n";
		std::cin >> num1;
		std::cout << "тип второй переменной\n1.int\n2.float\n3.double\n4.char>_ ";
		std::cin >> choice;
		if (choice == 4) {
			char num2;
			std::cout << "Введите символ: " << "\n";
			std::cin >> num2;
			std::cout << "Вот что можно сделать \n1. Поиск максимального\n2. Среднее арифметическое\n3. Модуль суммы\n4. Вывод целой части суммы чисел\n>_";
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "Максимальный элемент " << findMax(num1, num2);
			}
			if (choice == 2) {
				std::cout << "Среднее арифметическое " << findAvg(num1, num2);
			}
			if (choice == 3) {
				std::cout << "Модуль суммы " << modulSum(num1, num2);
			}
			if (choice == 4) {
				std::cout << "Вывод целой части суммы чисел " << celoeSumNum(num1, num2);
			}
		}
	}
	

}