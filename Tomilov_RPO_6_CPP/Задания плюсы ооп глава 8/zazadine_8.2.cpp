#include <iostream>
#include <string>
#include <vector>
class Enemy{
std::string name_;
int health_, damage_;
static double multiplier_;
public:
Enemy():health_((rand()%9+2)*multiplier_),damage_((rand()%5+1)*multiplier_){
std::vector<std::string> names{"МАКС","Афанасий","Волк","Кирилл"};
std::vector<std::string> surenames{"Мессенджер","Хулиган","Электросамокатчик","Амбассадор"};
name_ = names.at(rand()&(names.size()-1)) + " " + surenames.at(rand()%(surenames.size()-1));
}
void vivoEnemy(){
    std::cout << "Имя врага - " << name_ << '\n';
    std::cout << "Хп врага: " << health_ << "\n";
    std::cout << "Урон врага: " << damage_ << "\n";
}
static void editMultiplier(double value){
    multiplier_ = value;
}
static double getMultiplier(){
return multiplier_;
}
};
double Enemy::multiplier_ = 1;
int main(){
srand (static_cast<int> (time(0)));
std::vector<Enemy> enemies(4);
std::cout << Enemy::getMultiplier() << '\n';
for(int i = 0; i< enemies.size(); i++) enemies.at(i).vivoEnemy();
enemies.clear();
Enemy::editMultiplier(5.5);
for(int i = 0; i < 5; i++)enemies.push_back(Enemy());
std::cout << Enemy::getMultiplier() << '\n';
for(int i = 0; i< enemies.size(); i++) enemies.at(i).vivoEnemy();
}