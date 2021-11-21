#include "Main.h"
#include "MySQL.h"
#include "Customer.h"

void Customer::logic() {
	wcout << L"Customer logic!";
}

void Customer::customer_data_filling() {
}

//void Customer::add_to_shopping_cart(Товар) {}

int Customer::menu() {
	wcout << L"Выберите опцию:" << endl;
	wcout << L"1)Каталог товаров." << endl;
	wcout << L"2)Доставка и оплата." << endl;
	wcout << L"3)Скидки" << endl;
	wcout << L"4)Контакты" << endl;
	wcout << L"5)Смена пароля." << endl;
	wcout << L"6)Выход в меню первого уровня." << endl;
	return (input_check());
}