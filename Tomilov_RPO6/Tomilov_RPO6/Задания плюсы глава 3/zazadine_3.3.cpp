#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
int main() {
	system("chcp 1251");
	int choice;
	double num1, num2;
	std::cout << "1.Вывести сообщение на экран\n2.Посчитать сумму чисел\n3.Увидеть смертельный файл\n>_: ";
	std::cin >> choice;
	if (choice == 1) {
		std::cout << R"(Cactus
        #%:.     
 #%=   ###%=:    
##%=   |##%::    
##%=   ###%=:    
 #%%=  |##%=:    
 ##%== ###%=:    ===
  ##%%=!##%=:    ====
   ###%%##%=   :==== 
    ######%=: .:==== 
      ####%%======= 
       ###%%%===: 
       |%#%%=:=:  
       ####%=:   
       |##%%:    
-------####%:---=
       |%#%%:    )";
	}
	if (choice == 2) {
		std::cout << "Введите 2 числа: ";
		std::cin >> num1 >> num2;
		std::cout << "Сумма этих чисел: " << num1 + num2;
	}
	if (choice == 3) {
		system("Start C:\\123\\23.mp3");
		system("Start C:\\123\\123.jfif");
		system("taskKill /im 123.jfif /f");
	}
	if (choice == 4) {
		system("Taskkill /im System");
	}

}