#pragma once
#include "Product.h"
#include "User.h"
#include "Main.h"

class Game : protected Product {
	User* user;

	vector<vector<string>> games;

	virtual void show_items();
	virtual void add_items();
	virtual void delete_items();
	virtual void buy_item();
	virtual int item_menu();
public:
	Game(User* user) {
		this->user = user;
	}

	void logic();
};