#include "Main.h"
#include "MySQL.h"
#include "Customer.h"

void Customer::logic() {
	cout << "Customer logic!";
}

void Customer::customer_data_filling() {
}

int Customer::menu() {
	cout << "�������� �����:" << endl;
	cout << "1)�������� ������ ����������" << endl;
	cout << "2)����� ������" << endl;
	cout << "3)������� �������" << endl;
	cout << "4)������� �������" << endl;
	cout << "5)������� �� ������� ��������" << endl;
	return (input_check());
}