#include "Main.h"
#include "Authentication.h"
#include "MySQL.h"
#include "Customer.h"
#include "Admin.h"

#define ID 0
#define PRIORITY 1
#define LOGIN 2
#define PASSWORD 3
#define USERNAME 4

//knooki venia11let

User* Authentication::identification() {
	MySQL db;
	this->auth_data = db.db_connection("Select auth.id, priority, login, password, username from authentication auth, users WHERE auth.id=users.id");

	switch (auth_menu()) {
	case 1:
		log_in();
		return user;
		system("pause");

	case 2:
		sign_up();
		return user;
		system("pause");

	case 3:
		user->set_priority(2);
		return user;
	default: error_message("Вы ввели неизвестную опцию.");
		system("pause");
		return user;
		break;
	}
}

int Authentication::auth_menu() {
	system("cls");
	cout << "1)Вход.\n2)Регистрация\n3)Вернуться назад." << endl;
	return (input_check());
}

void Authentication::log_in() {
	int amount = 0;
	do {
		system("cls");

		cout << "Введите логин." << endl;
		rewind(stdin);
		getline(cin, login, '\n');

		cout << "Введите пароль." << endl;

		password_entry();

		login = sha1(login);
		password = sha1(password);

		for (register int i = 0; i < auth_data.size(); i++)
			if (login == auth_data[i][LOGIN] && password == auth_data[i][PASSWORD])
			{
				user->set_id(stoi(auth_data[i][ID]));
				user->set_priority(stoi(auth_data[i][PRIORITY]));
				user->set_username(auth_data[i][USERNAME]);
				return;
			}

		error_message("Вы ввели неверный логин или пароль.");

		amount++;

		if (amount == 3)
		{
			amount = 0;
			for (register int i = 30; i > 0; i--) {
				Sleep(1000);

				system("cls");
				cout << "Программа приостановлена из-за превышения попыток ввода." << endl;
				cout << "До возобновления программы осталось: " << i << " с" << endl;
			}
			system("cls");
		}
	} while (is_repeat_operation());
}

void Authentication::sign_up() {
	while (1) {
		system("cls");

		cout << "Введите новый логин." << endl;
		rewind(stdin);
		getline(cin, login, '\n');

		login = sha1(login);

		int i = 0;
		while (i < auth_data.size()) {
			if (login == auth_data[i][LOGIN])
			{
				error_message("Этот логин уже занят.");
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
			user->set_priority(2);
		}
		if (i == auth_data.size()) break;
	}

	cout << "Введите пароль." << endl;
	password_entry();

	password = sha1(password);

	cout << "Пожалуйста, введите данные о себе." << endl;

	int flag = 0;

	while (1) {
		cout << "Введите свой никнейм:" << endl;

		rewind(stdin);
		getline(cin, username, '\n');

		for (register int i = 0; i < auth_data.size(); i++)
			if (username == auth_data[i][USERNAME]) {
				error_message("Такой ник уже занят");
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			continue;
		}
		else {
			user->set_username(username);
			break;
		}
	}

	Customer new_customer(user);
	new_customer.customer_data_filling();

	MySQL db;
	db.db_connection("insert into authentication values(0, 1, " + login + ", " + password + ")");
	this->auth_data = db.db_connection("Select auth.id, priority, login, password, username from authentication auth, users WHERE auth.id=users.id");
	db.db_connection("insert into users values(" + auth_data[-1][ID] + ", " + username + ")");

	complete_message("Вы успешно зарегестрировались.");
	if (is_repeat_operation())
		user->set_id(-1);
}

void Authentication::password_entry() {
	do {
		int p = _getch();

		if (p == 13) break;
		if (p == '\b' && !this->password.empty())
		{
			cout << '\b';
			cout << ' ';
			cout << '\b';
			this->password.pop_back();
			continue;
		}
		if (p != '\b')
			cout << '*';
		this->password.push_back(p);
	} while (1);

	cout << '\n';
}

User* Authentication::change_password() {
	MySQL db;
	this->auth_data = db.db_connection("Select * from authentication");
	int i = 0;
	while (i < auth_data.size()) {
		if (to_string(user->get_id()) == auth_data[i][ID]) {
			password_entry();
			password = sha1(password);

			if (password == auth_data[i][PASSWORD])
			{
				cout << "Введите новый пароль." << endl;
				password_entry();

				password = sha1(password);

				db.db_connection("UPDATE authentication SET password=" + password + " WHERE id=" + to_string(user->get_id()));

				complete_message("Вы успешно изменили пароль.");
				system("pause");
				return user;
			}
			else {
				error_message("Вы ввели неверный пароль.");
				user->set_id(0);
				user->set_priority(-1);
				return user;
				system("pause");
			}
			break;
		}
		i++;
	}
	if (i == auth_data.size()) {
		error_message("Произошла ошибка в изменении пароля.");
		return user;
	}
}