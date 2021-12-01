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
	cout << "Каталог товаров:" << endl;

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
	cout << "Выберите категорию:" << endl;
	cout << "1)Книги" << endl;
	cout << "2)Настольные игры" << endl;
	cout << "3)Игры и игрушки" << endl;
	cout << "4)Сувениры" << endl;
	cout << "5)Товары для творчества" << endl;
	cout << "6)Назад на главную страницу" << endl;
	return(input_check());
}