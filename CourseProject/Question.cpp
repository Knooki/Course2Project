#include "Main.h"
#include "Admin.h"
#include "Customer.h"
#include "User.h"
#include "Question.h"

#define Q_ID 0
#define CUSTOMER 1
#define	QUESTION 2
#define Q_DATE 3
#define ADMIN 4
#define ANSWER 5
#define A_DATE 6

void Question::logic() {
	MySQL db;

	questions = db.db_connection(main_query);

	system("cls");

	if (this->user->get_priority() == -1)
	{
		cout << "Чтобы самостоятельно задать вопрос, зарегистрируйтесь" << endl;
		show_questions();
	}
	else if (this->user->get_priority() == 0)
		do {
			system("cls");
			switch (menu_admin()) {
			case 1:
				show_questions();
				break;
			case 2:
				answer_question();
				break;
			case 3:
				delete_question();
				break;
			case 4: return;
			}
		} while (is_repeat_operation());
	else
		do {
			system("cls");
			switch (menu_customer()) {
			case 1:
				show_questions();
				break;
			case 2:
				ask_question();
				break;
			case 3:
				return;
			}
		} while (is_repeat_operation());
		system("pause");
}

void Question::show_questions() {
	for (register int i = 0; i < questions.size(); i++) {
		cout << "Пользователь: " << grey_cl << questions[i][CUSTOMER] << endl
			<< white_cl << "Вопрос:" << endl << grey_cl << questions[i][QUESTION] << endl
			<< white_cl << "Дата вопроса: " << grey_cl << questions[i][Q_DATE] << white_cl << endl;
		if (questions[i][ANSWER] != "") {
			cout << "Администратор: " << grey_cl << questions[i][ADMIN] << endl
				<< white_cl << "Ответ: " << endl << grey_cl << questions[i][ANSWER] << endl
				<< white_cl << "Дата ответа: " << grey_cl << questions[i][A_DATE] << endl << white_cl << endl << endl;
		}
		else {
			cout << "Ответа пока нет." << endl << endl;
		}
	}
}

int Question::menu_customer() {
	cout << "Выберите опцию:" << endl;
	cout << "1)Посмотреть вопросы пользователей" << endl;
	cout << "2)Задать вопрос" << endl;
	cout << "3)Назад на главную" << endl;
	return input_check();
}

int Question::menu_admin() {
	cout << "Выберите опцию:" << endl;
	cout << "1)Посмотреть вопросы пользователей" << endl;
	cout << "2)Ответь на вопрос пользователя" << endl;
	cout << "3)Удалить вопрос пользователя" << endl;
	cout << "4)Назад на главную" << endl;
	return input_check();
}

void Question::answer_question() {
	MySQL db;
	show_questions();
	do {
		cout << "Введите номер вопроса, на который хотите ответить" << endl;
		int i = input_check();
		i--;
		if (i < questions.size()) {
			string answer;
			if (questions[i][ANSWER].size() == 0)
			{
				cout << "Напишите ответ: " << endl;
				rewind(stdin);
				getline(cin, answer, '\n');
				db.db_connection("Update questions set answer=\"" + answer + "\", answer_date=\"" + current_date() + "\", adm_id=" + to_string(user->get_id()) + " where q_id=" + questions[i][Q_ID]);
			}
			else error_message("Ответ к этому вопросу уже есть");
		}
		else error_message("Вы ввели несуществующий номер вопроса");
	} while (is_repeat_operation());
}

void Question::ask_question() {
	MySQL db;
	show_questions();
	if (user->get_asked_questions() < 6) {
		wcout << "Введите вопрос, который хотите спросить" << endl;
		string question;
		getline(cin, question, '\n');

		db.db_connection("insert into questions values (0, " + to_string(user->get_id()) + ", 0, \"" + question + "\", \"\", \"" + current_date() + "\", NULL)");
		user->add_asked_question();
	}
	else cout << "Вы уже задали 5 вопросов, на этом всё)" << endl;
	system("pause");
}

void Question::delete_question() {
	MySQL db;
	show_questions();
	do {
		cout << "Введите номер вопроса, который хотите удалить" << endl;
		int i = input_check() - 1;

		if (i < questions.size()) {
			db.db_connection("delete from questions where q_id=" + questions[i][Q_ID]);
			this->questions = db.db_connection(main_query);
		}
		else error_message("Вы ввели несуществующий номер вопроса");
	} while (is_repeat_operation());
}