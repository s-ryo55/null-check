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
	Player(std::shared_ptr<Weapon> weapon1)
		: weapon(std::move(weapon1)) {
		std::cout << weapon.use_count() << std::endl;
		std::cout << weapon1.use_count() << std::endl;

	}

	void Attack() {
		weapon->Use();
	}
};

int main() {
	auto wp = std::make_shared<Weapon>();

	Player p(wp);

	Player q(std::move(wp));
	return 0;

}
