#pragma once
#include "User.h"
#include "Main.h"
#include "MySQL.h"

class Admin : protected User {
public:
	Admin(User user) {
		this->id = user.get_id();
	}

	void logic();
};