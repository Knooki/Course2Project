#pragma once
#include "Main.h"
#include "User.h"

class Authentication {
private:
	wstring login = L"";
	wstring password = L"";

	void password_entry();
	vector<vector<wstring>> auth_data;
	int auth_menu();
	User log_in(User user);
	User sign_up(User user);
public:
	User identification(User user);
};