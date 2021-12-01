#pragma once
#include "Main.h"
#include "Product.h"
#include "User.h"

class Promotion {
	User* user;

	string beg_date; // dates in mysql format "2003-02-25"
	string end_date;
	string prom;     // promotion itself

	vector<vector<string>> promotions;

	int admin_menu();
	void show_promotions();
	void add_promotion();
	void delete_promotion();
	void change_promotion();

public:
	Promotion(User* user) {
		this->user = user;
	}
	void delete_expired();
	void logic();
};