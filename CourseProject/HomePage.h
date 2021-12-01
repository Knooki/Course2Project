#pragma once
#include "Main.h"
#include "User.h"

class HomePage : protected User { // default id = 0 prior = -1 => user не может купить что-то
	User* user;

	int entr_menu();
	void info_delivery_payment();
	void info_how_to_order();
	void contacts();
	void show_shopping_cart();
public:
	HomePage(User* user) {
		this->user = user;
	}

	void logic();
};