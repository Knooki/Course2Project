#pragma once
#include "Product.h"
#include "Main.h"
#include "User.h"

class Souvenir : protected Product {
	User* user;

	vector<vector<string>> souvenirs;

	virtual void show_items();
	virtual void add_items();
	virtual void delete_items();
	virtual void buy_item();
	virtual int item_menu();
public:
	Souvenir(User* user) {
		this->user = user;
	}

	void logic();
};