#include "Main.h"
#include "Authentication.h"
#include "MySQL.h"
#include "Customer.h"
#include "Admin.h"

#define ID 0
#define PRIORITY 1
#define LOGIN 2
#define PASSWORD 3

User Authentication::identification(User user) {
	MySQL db;
	this->auth_data = db.db_connection(L"Select * from users");

	switch (auth_menu()) {
	case 1:
		user = log_in(user);
		return user;
		system("pause");

	case 2:
		user = sign_up(user);
		return user;
		system("pause");

	case 3:
		user.set_priority(2);
		return user;
	default: error_message(L"Вы ввели неизвестную опцию.");
		system("pause");
		return user;
		break;
	}
}

int Authentication::auth_menu() {
	system("cls");
	wcout << L"1)Вход.\n2)Регистрация\n3)Вернуться назад." << endl;
	return (input_check());
}

User Authentication::log_in(User user) {
	int amount = 0;
	do {
		system("cls");

		wcout << L"Введите логин." << endl;
		rewind(stdin);
		getline(wcin, login, L'\n');

		wcout << L"Введите пароль." << endl;

		password_entry();

		login = s_to_ws(sha1(ws_to_s(login)));
		password = s_to_ws(sha1(ws_to_s(password)));

		for (register int i = 0; i < auth_data.size(); i++)
			if (login == auth_data[i][LOGIN] && password == auth_data[i][PASSWORD])
			{
				user.set_id(stoi(auth_data[i][ID]));
				user.set_priority(stoi(auth_data[i][PRIORITY]));
				return user;
			}

		error_message(L"Вы ввели неверный логин или пароль.");

		amount++;

		if (amount == 3)
		{
			amount = 0;
			for (register int i = 30; i > 0; i--) {
				Sleep(1000);

				system("cls");
				wcout << L"Программа приостановлена из-за превышения попыток ввода." << endl;
				wcout << L"До возобновления программы осталось: " << i << L" с" << endl;
			}
			system("cls");
		}
	} while (is_repeat_operation());

	return user;
}

User Authentication::sign_up(User user) {
	while (1) {
		system("cls");

		wcout << L"Введите новый логин." << endl;
		rewind(stdin);
		getline(wcin, login, L'\n');

		login = s_to_ws(sha1(ws_to_s(login)));

		int i = 0;
		while (i < auth_data.size()) {
			if (login == auth_data[i][LOGIN])
			{
				error_message(L"Этот логин уже занят.");
				if (is_repeat_operation())
					break;
				else {
					i = auth_data.size() + 1;
					break;
				}
			}
			i++;
		}
		if (i > auth_data.size()) {
			user.set_priority(2);
			return user;
		}
		if (i == auth_data.size()) break;
	}
	wcout << L"Введите пароль." << endl;
	password_entry();

	password = s_to_ws(sha1(ws_to_s(password)));

	wcout << L"Пожалуйста, введите данные о себе." << endl;

	Customer new_customer(user);
	new_customer.customer_data_filling();

	MySQL db;
	wstring query = L"insert into users values(0, 1, " + login + L", " + password + L")";
	db.db_connection(query);

	complete_message(L"Вы успешно зарегестрировались.");
	if (is_repeat_operation())
		user.set_id(-1);

	return user;
}

void Authentication::password_entry() {
	do {
		wint_t p = _getwch();

		if (p == 13) break;
		if (p == L'\b' && !this->password.empty())
		{
			wcout << L'\b';
			wcout << L' ';
			wcout << L'\b';
			this->password.pop_back();
			continue;
		}
		if (p != L'\b')
			wcout << L'*';
		this->password.push_back(p);
	} while (1);

	wcout << L'\n';
}