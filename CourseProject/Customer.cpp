#include "Main.h"
#include "MySQL.h"
#include "Customer.h"

void Customer::logic() {
	wcout << L"Customer logic!";
}

void Customer::customer_data_filling() {
}

//void Customer::add_to_shopping_cart(�����) {}

int Customer::menu() {
	wcout << L"�������� �����:" << endl;
	wcout << L"1)������� �������." << endl;
	wcout << L"2)�������� � ������." << endl;
	wcout << L"3)������" << endl;
	wcout << L"4)��������" << endl;
	wcout << L"5)����� ������." << endl;
	wcout << L"6)����� � ���� ������� ������." << endl;
	return (input_check());
}