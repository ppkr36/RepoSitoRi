#include <iostream>
int main() {
	system("chcp 1251");
	char username[30],password[30],password_2[30],login[30],password_login[30];
	std::cout << "Введите имя: ";
	std::cin >> username;
	std::cout << "Введите пароль: ";
	std::cin >> password;
	std::cout << "Введите пароль ещё раз: ";
	std::cin >> password_2;
	while (strcmp(password, password_2) != 0) {
		std::cout << '\n' << "Повторите: ";
		std::cin >> password_2;
	}
	system("cls");
	if (strcmp(password, password_2) == 0) {
		std::cout << "Регистрация прошла успешно ";

		while ((strcmp(password, password_login) != 0) || (strcmp(username, login) != 0)) {
			system("cls");
			std::cout << "\nВведите логин : ";
			std::cin >> login;
			std::cout << "Введите пароль : ";
			std::cin >> password_login;
			if((strcmp(password, password_login) == 0) && (strcmp(username, login) == 0)) {
				system("cls");
				std::cout << "Вы успешно вошли!";
			}
		}
	}
}