#pragma once
#include "Product.h"
#include "User.h"
#include "Main.h"

class CreativeGood : protected Product {
	User* user;
	vector<vector<string>> creatie_goods;

	virtual void show_items();
	virtual void add_items();
	virtual void delete_items();
	virtual void buy_item();
	virtual int item_menu();

public:
	CreativeGood(User* user) {
		this->user = user;
	}

	void logic();
};