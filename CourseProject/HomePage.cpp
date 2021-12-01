#pragma once
#include "Main.h"
#include "HomePage.h"
#include "Admin.h"
#include "User.h"
#include "Customer.h"
#include "Authentication.h"
#include "ShoppingCart.h"
#include "Catalog.h"
#include "Promotion.h"
#include "Question.h"

int HomePage::entr_menu() {
	system("cls");
	cout << "����� ���������� � ������� �������!" << endl;

	cout << "�������� �����." << endl;

	cout << "1)������� �������" << endl;
	cout << "2)�����" << endl;
	cout << "3)������" << endl;
	cout << "4)������� �������" << endl;
	cout << "5)��������/������" << endl;
	cout << "6)��� ������� �����?" << endl;
	cout << "7)��������" << endl;
	cout << "8)������� �������������" << endl;
	if (this->user->get_id() != 0 && this->user->get_priority() != -1)
		cout << "9)������ �������" << endl;
	else cout << "9)�����������/����" << endl;
	cout << "10)�����" << endl;
	return (input_check());//����� �������� �����������, ��� �������� q&a ������������ ������ ������� ������ ��������
}

void HomePage::logic() {
	ShoppingCart shopping_cart(user);
	Promotion promotion(user);
	promotion.delete_expired();
	while (1) {
		switch (entr_menu()) {
		case 1: {
			Catalog catalog(user);
			catalog.logic(); }
			  break;
		case 2:
			promotion.logic();//DONE
			break;
		case 3: {
			Product product;
			product.show_discounts();
		}
			  break;
		case 4:
			shopping_cart.logic();
			break;
		case 5:
			info_delivery_payment();
			break;
		case 6:
			info_how_to_order();
			break;
		case 7:
			contacts(); // DONE
			break;
		case 8: {
			Question question(user);//DONE
			question.logic(); }
			  break;
		case 9:
			if (this->user->get_priority() == -1) {
				Authentication auth(user);
				user = auth.identification();//DONE
			}
			else if (this->user->get_priority() == 0) {
				Admin admin(user);
				admin.logic();
			}
			else if (this->user->get_priority() == 1) {
				Customer customer(user);
				customer.logic();
			}
			break;
		case 10:
			return;
		}
	}
}

void HomePage::contacts() {
	system("cls");
	cout << "��������:" << endl;
	cout << "������� 073603 ������: ����� ������� ���������" << endl;
	cout << "VK: vk.com/knooki" << endl;
	cout << "���������� �����: +375447642273" << endl;
	cout << "Email: aliaksei.aheyeu@gmail.com" << endl;
	system("pause");
}

void HomePage::info_how_to_order() {
}

void HomePage::info_delivery_payment() {
}