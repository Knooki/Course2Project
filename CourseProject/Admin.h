#pragma once
#include "User.h"
#include "Main.h"
#include "MySQL.h"

class Admin : protected User {
	User* user;

	int admin_menu();

public:
	Admin(User* user) {
		this->user = user;
	}

	void logic();
};