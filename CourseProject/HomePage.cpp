#pragma once
#include "Main.h"
#include "HomePage.h"
#include "Admin.h"
#include "User.h"
#include "Customer.h"
#include "Authentication.h"

int HomePage::entr_menu() {
	system("cls");
	wcout << L"Добро пожаловать в Книжный магазин!" << endl;

	wcout << L"Выберите опцию." << endl;

	wcout << L"1)Каталог товаров" << endl;
	wcout << L"2)Акции" << endl;
	wcout << L"3)Доставка/оплата" << endl;
	wcout << L"4)Как сделать заказ?" << endl;
	wcout << L"5)Контакты" << endl;
	if (this->id != 0 && this->priority != -1)
		wcout << L"6)Личный кабинет" << endl;
	else wcout << L"6)Регистрация/вход" << endl;
	wcout << L"7)Выход" << endl;
	return (input_check())//можно добавить комментарии, или страницу q&a пользователи задают вопросы админы отвечают
}

void HomePage::logic() {
	Authentication auth;
	while (1) {
		user = auth.identification(user);
		switch (user.get_priority())
		{
		case 0:
		{
			Admin admin(user);
			break; }
		case 1: {
			Customer customer(user);
			break; }
		case -1:
			continue;
		case 2:
			return;
		}
	}
}