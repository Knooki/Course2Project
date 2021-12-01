#pragma once
#include "Main.h"
#include "Product.h"
#include "User.h"

class Book : protected Product {
	User* user;

	string type;
	int type_id;
	int product_id;
	string title;
	string author;
	string author_id;
	string category;
	int publish_year;
	float average_raging;
	int num_pages;
	int ratings_count;

	vector<vector<string>> books;

	virtual void show_items();
	virtual void add_items();
	virtual void delete_items();
	virtual void buy_item();
	virtual int item_menu();

public:
	Book(User* user) {
		this->user = user;
	}

	void logic();
};