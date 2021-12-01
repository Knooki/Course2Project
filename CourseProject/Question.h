#pragma once

#include "Main.h"
#include "Admin.h"
#include "Customer.h"
#include "User.h"

class Question {
	User* user;

	const string main_query = "select q_id, q.username, question, question_date, a.username, answer, answer_date from questions left outer join users as q on cust_id=q.id left outer join users as a on adm_id = a.id";

	vector<vector<string>> questions;

	void ask_question();
	void answer_question();
	void delete_question();
	void show_questions();

	int menu_admin();
	int menu_customer();
public:
	Question(User* user) {
		this->user = user;
	}

	void logic();
};