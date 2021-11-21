#pragma once
#include "Main.h"
#include "User.h"

class Customer : protected User {
	//vector<�����> Shopping_kart; ��� ��� �� home page

public:
	Customer(User user) {
		this->id = user.get_id();
	}

	void logic();
	void customer_data_filling();
	void add_to_shopping_cart();
	int menu();
};