#pragma once
#include "Main.h"
#include "HomePage.h"
#include "Admin.h"
#include "User.h"
#include "Customer.h"
#include "Authentication.h"

int HomePage::entr_menu() {
	system("cls");
	wcout << L"����� ���������� � ������� �������!" << endl;

	wcout << L"�������� �����." << endl;

	wcout << L"1)������� �������" << endl;
	wcout << L"2)�����" << endl;
	wcout << L"3)��������/������" << endl;
	wcout << L"4)��� ������� �����?" << endl;
	wcout << L"5)��������" << endl;
	if (this->id != 0 && this->priority != -1)
		wcout << L"6)������ �������" << endl;
	else wcout << L"6)�����������/����" << endl;
	wcout << L"7)�����" << endl;
	return (input_check())//����� �������� �����������, ��� �������� q&a ������������ ������ ������� ������ ��������
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