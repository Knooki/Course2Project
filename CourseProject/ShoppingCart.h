#pragma once
#include "Main.h"
#include "Admin.h"
#include "Customer.h"
#include "Product.h"

class ShoppingCart {
	vector<Product> shopping_cart;
	User* user;

	void add_item(Product product);
	void delete_item(Product product);

public:
	ShoppingCart(User* user) {
		this->user = user;
	}

	void logic();
};