#include "Main.h"
#include "Product.h"
#include "User.h"
#include "Promotion.h"
#include "MySQL.h"

#define ID 0
#define BEG_DATE 1
#define	END_DATE 2
#define PROM 3

void Promotion::logic() {
	if (this->user->get_priority() == 1 || this->user->get_priority() == -1)
		show_promotions();
	else
		switch (admin_menu()) {
		case 1:
			add_promotion();
			break;
		case 2:
			change_promotion();
			break;
		case 3:
			delete_promotion();
			break;
		case 4:
			show_promotions();
			break;
		case 5:
			return;
		}
}

void Promotion::show_promotions() {
	for (register int i = 0; i < promotions.size(); i++) {
		cout << "АКЦИЯ ➤" << grey_cl << promotions[i][PROM] << endl
			<< white_cl << "НАЧАЛО ➤" << grey_cl << promotions[i][BEG_DATE] << endl
			<< white_cl << "КОНЕЦ ➤" << grey_cl << promotions[i][END_DATE] << white_cl << endl << endl;
	}
}

void Promotion::delete_expired() {
	MySQL db;
	this->promotions = db.db_connection("SELECT * FROM promotions");
	for (register int i = 0; i < promotions.size(); i++) {
		if (is_expired_date(promotions[i][END_DATE]))
			db.db_connection("DELETE FROM promotions WHERE id=" + promotions[i][ID]);
	}
}

void Promotion::add_promotion() {
	int flag = 0;
	cout << "Ведите акцию" << endl;
	while (1)
	{
		rewind(stdin);
		getline(cin, prom, '\n');
		for (register int i = 0; i < prom.size(); i++)
			if (!is_russian_alpha(prom[i])) {
				error_message("Пожaлуйста, используйте только русские буквы.");
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			continue;
		}
		break;
	}
	cout << "Введите дату начала акции:" << endl;
	while (1)
	{
		rewind(stdin);
		getline(cin, beg_date, '\n');
		if (is_expired_date(beg_date)) {
			error_message("Нельзя вводить уже наступившую дату для новой акции");
			continue;
		}
		break;
	}
	cout << "Введите дату конца акции:" << endl;
	while (1)
	{
		rewind(stdin);
		getline(cin, end_date, '\n');
		if (is_expired_date(end_date)) {
			error_message("Нельзя вводить уже наступившую дату для новой акции");
			continue;
		}
		if (beg_date > end_date) {
			error_message("Дата конца акции должна быть позже чем дата начала акции");
			continue;
		}
		break;
	}
	MySQL db;
	db.db_connection("INSERT INTO promotions VALUES (0, \"" + beg_date + "\", \"" + end_date + "\", \"" + prom + "\")");
}

void Promotion::change_promotion() {
	show_promotions();
	cout << "Введите порядковый номер акции, которую хотите изменить" << endl;
	int number = input_check();
	if (number > promotions.size())
		error_message("Вы ввели слишком большое число");
	else {
		int flag = 0;
		cout << "Ведите акцию" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, prom, '\n');
			for (register int i = 0; i < prom.size(); i++)
				if (!is_russian_alpha(prom[i])) {
					error_message("Пожaлуйста, используйте только русские буквы.");
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			break;
		}
		if (!is_expired_date(promotions[number][BEG_DATE])) {
			cout << "Введите дату начала акции:" << endl;
			while (1)
			{
				rewind(stdin);
				getline(cin, beg_date, '\n');
				if (is_expired_date(beg_date)) {
					error_message("Нельзя вводить уже наступившую дату для начала акции");
					continue;
				}
				break;
			}
		}
		else beg_date = promotions[number][BEG_DATE];
		cout << "Введите дату конца акции:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, end_date, '\n');
			if (is_expired_date(end_date)) {
				error_message("Нельзя вводить уже наступившую дату для конца акции");
				continue;
			}
			if (beg_date > end_date) {
				error_message("Дата конца акции должна быть позже чем дата начала акции");
				continue;
			}
			break;
		}
		MySQL db;
		db.db_connection("UPDATE promotions SET beg_date=\"" + beg_date + "\", end_date=\"" + end_date + "\", prom=\"" + prom + "\" WHERE id=" + promotions[number][ID]);
	}
}

void Promotion::delete_promotion() {
	show_promotions();
	cout << "Введите порядковый номер акции, которую хотите изменить" << endl;
	int number = input_check();
	if (number > promotions.size())
		error_message("Вы ввели слишком большое число");
	else {
		MySQL db;
		db.db_connection("DELETE FROM promotions WHERE id=\"" + promotions[number][ID] + "\"");
	}
}

int Promotion::admin_menu() {
	cout << "Выберите опцию:" << endl;
	cout << "1)Добавление акции." << endl;
	cout << "2)Редактирование акции." << endl;
	cout << "3)Удаление акции." << endl;
	cout << "4)Показать акции." << endl;
	cout << "5)Вернуться на главную страницу." << endl;
	return(input_check());
}