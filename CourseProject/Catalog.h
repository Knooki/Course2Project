#pragma once
#include "Main.h"
#include "Product.h"
#include "ShoppingCart.h"

class Catalog {
	User* user;

	int catalog_menu();

public:
	Catalog(User* user) {
		this->user = user;
	}
	void logic();
};