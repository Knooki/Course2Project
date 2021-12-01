#pragma once
#include "Main.h"
#include "Product.h"
#include "Catalog.h"
#include "Book.h"
#include "BoardGame.h"
#include "Game.h"
#include "CreativeGood.h"
#include "Souvenir.h"

void Catalog::logic() {
	cout << "������� �������:" << endl;

	switch (catalog_menu()) {
	case 1: {
		Book book(user);
		book.logic();
	}
		  break;
	case 2: {
		BoardGame board_game(user);
		board_game.logic();
	}
		  break;
	case 3: {
		Game game(user);
		game.logic();
	}
		  break;
	case 4: {
		Souvenir souvenir(user);
		souvenir.logic();
	}
		  break;
	case 5: {
		CreativeGood creative_good(user);
		creative_good.logic();
	}
		  break;
	case 6:
		return;
	}
}

int Catalog::catalog_menu() {
	cout << "�������� ���������:" << endl;
	cout << "1)�����" << endl;
	cout << "2)���������� ����" << endl;
	cout << "3)���� � �������" << endl;
	cout << "4)��������" << endl;
	cout << "5)������ ��� ����������" << endl;
	cout << "6)����� �� ������� ��������" << endl;
	return(input_check());
}