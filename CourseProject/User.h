#pragma once
#include "Main.h"
#include "Product.h"

class User {
protected:
	int id = 0;
	int priority = -1;//admin=0 customer=1
	int number_of_questions_today = 0;
	string username;
	vector<Product> shopping_cart;

public:
	User() {
	}

	User(User& user) {
		this->id = user.id;
		this->priority = user.priority;
		this->username = user.username;
	}

	void set_id(int id) {
		this->id = id;
	}

	void set_priority(int priority) {
		this->priority = priority;
	}

	void set_username(string username) {
		this->username = username;
	}

	void add_asked_question() {
		this->number_of_questions_today++;
	}

	int get_asked_questions() {
		return this->number_of_questions_today;
	}

	int get_id() {
		return this->id;
	}

	int get_priority() {
		return this->priority;
	}

	void add_to_shopping_cart(Product product);
};