// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//


#include <iostream>
#include<assert.h>


class Weapon {
public:
	void Use() {}
};

class Player {
	std::shared_ptr<Weapon> weapon;
public:
	Player(std::shared_ptr<Weapon> weapon1): weapon(weapon1) {
		std::cout << weapon.use_count() << std::endl;
		std::cout << weapon1.use_count() << std::endl;

	}

	void Attack() {
		weapon->Use();
	}
};


int main() {
	
	auto a = std::make_shared<Player>(std::make_shared<Weapon>());

	std::cout << "a:" << a.use_count() << std::endl;

	auto b = a;

	std::cout << "a:" << a.use_count() << std::endl;
	std::cout << "b:" << b.use_count() << std::endl;

	auto c = std::move(a);


	std::cout << "a:" <<a.use_count() << std::endl;
	std::cout << "b:" << b.use_count() << std::endl;
	std::cout << "c:" << c.use_count() << std::endl;


	assert(a != nullptr);
	a->Attack();

}
