#include "Main.h"
#include "MySQL.h"
#include "Customer.h"

void Customer::logic() {
	cout << "Customer logic!";
}

void Customer::customer_data_filling() {
}

int Customer::menu() {
	cout << "Выберите опцию:" << endl;
	cout << "1)Изменить личную информацию" << endl;
	cout << "2)Смена пароля" << endl;
	cout << "3)Корзина покупок" << endl;
	cout << "4)История заказов" << endl;
	cout << "5)Обратно на главную страницу" << endl;
	return (input_check());
}