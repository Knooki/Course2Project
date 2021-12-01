#pragma once
#include "Main.h"
#include "User.h"

class Customer : protected User {
	User* user;

	vector<vector<string>> customers;

public:
	Customer(User* user) {
		this->user = user;
	}

	void logic();
	void customer_data_filling();
	int menu();
};