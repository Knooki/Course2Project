#pragma once
#include "Main.h"
#include "User.h"

class HomePage : protected User { // default id = 0 prior = -1 => user не может купить что-то
	User user;
	int entr_menu();
	void info_delivery_payment();
	void info_how_to_order();
public:
	void logic();
};