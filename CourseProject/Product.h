#pragma once
#include "Main.h"

class Product {
	int id = 0;
	int type_id = 0;
	string type = "";
	int age = 0;
	int quantity = 0;
	float price = 0;
	float discount = 1;

	vector<vector<wstring>> products;

	void update_quantity(int q) {
		this->quantity = q;
	}
	void update_price(float p) {
		this->price = p;
	}
	void update_discount(float d) {
		this->discount = d;
	}

	virtual void show_items();
	virtual void add_items();
	virtual void delete_items();
	virtual void buy_item();
	virtual int item_menu();

public:
	Product() {
	}
	Product(Product& product) {
		this->products = product.products;
	}

	void show_discounts();
};