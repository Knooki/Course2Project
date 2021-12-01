#pragma once
#include "Main.h"
#include "Product.h"
#include "User.h"

class BoardGame : protected Product {
	User* user;
	vector<vector<string>> board_games;

	virtual void show_items();
	virtual void add_items();
	virtual void delete_items();
	virtual void buy_item();
	virtual int item_menu();

public:
	BoardGame(User* user) {
		this->user = user;
	}

	void logic();
};