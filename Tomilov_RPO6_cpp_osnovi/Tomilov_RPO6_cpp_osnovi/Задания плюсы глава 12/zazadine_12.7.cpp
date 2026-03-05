#include <iostream>
#include <string>
int main() {
	system("chcp 1251");
	std::string username, password, password_2, login, password_login;
	std::cout << "Введите имя: ";
	std::cin >> username;
	std::cout << "Введите пароль: ";
	std::cin >> password;
	std::cout << "Введите пароль ещё раз: ";
	std::cin >> password_2;
	while (password != password_2) {
		std::cout << '\n' << "Повторите: ";
		std::cin >> password_2;
	}
	system("cls");
	if (password == password_2) {
		std::cin.ignore();
		std::cout << "Регистрация прошла успешно ";
		while ((password != password_2) or (username != login)) {
			system("cls");
			std::cout << "\nВведите логин : ";
			std::cin >> login;
			std::cout << "Введите пароль : ";
			std::cin >> password_login;
			if ((password == password_2) && (username == login)) {
				system("cls");
				std::cout << "Вы успешно вошли!";
			}
		}
	}
}