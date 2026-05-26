#include <iostream>
#include <string>
#include <vector>
class Robot{
int x_,y_;
public:
Robot():x_(0),y_(0){};
void vivod(){
    std::cout << "Я " << this << " и вот мои координаты: " << x_ << ";" << y_ << "\n";
}
void move(int amount_of_kuda){
bool is_x = rand() % 2;
is_x ? x_ += amount_of_kuda : y_ += amount_of_kuda;
std::cout << "Мне сказали сдвинуться на " << amount_of_kuda << ", но не сказали куда, я выбрал координату " << (is_x ? "x" : "y") << "\n";
}
void move(int x, int y){
    std::cout << this << " Сказали переместится на эти координаты: " << x<<";"<<y << '\n';
    x_ = x;
    y_ = y;
}
void move(std::string object_to_move){
    if(!object_to_move.empty()&& object_to_move != "стена"&&object_to_move!="мяч"&&object_to_move!="коробка")
        std::cout << "Просите, я не знаю как двигать " << object_to_move << "\n";
    if(object_to_move == "стена"){
        std::cout << "Простите, я не могу двигать стены" << '\n';
    }
    if(object_to_move == "мяч"){
        std::cout << "Мне сказали двинуть мяч. Предупреждаю: он может укатиться\n";
    }
    if(object_to_move == "коробка"){
        std::cout << "Мне сказали двинуть кробку. это я могу\n";
    }    
}   
};

int main(){
srand(static_cast<int>(time(0)));
Robot robot;
robot.vivod();
robot.move(4);
robot.vivod();
robot.move(-2222, 4);
robot.vivod();
robot.move("коробка");
robot.move("мяч");
robot.move("стена");
robot.move("дом");
robot.move("воздух");
robot.vivod();
}