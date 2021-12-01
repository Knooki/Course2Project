#pragma once
#include "Main.h"
#include "User.h"

class Authentication {
private:
	User* user;

	string login = "";
	string password = "";
	string username = "";

	void password_entry();
	vector<vector<string>> auth_data;
	int auth_menu();
	void log_in();
	void sign_up();
public:
	Authentication(User* user) {
		this->user = user;
	}

	User* identification();
	User* change_password();
};