#include "MySQL.h"
#include "Main.h"
#include "Admin.h"

void Admin::logic() {
	system("cls");
	cout << "Личный кабинет администратора" << endl;
	while (1) {
		switch (admin_menu()) {
		case 1:

			break;
		}
	}
}

int Admin::admin_menu() {
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	return input_check();
}