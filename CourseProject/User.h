#pragma once
#include "Main.h"

class User {
protected:
	int id = 0;
	int priority = -1;//admin=0 customer=1

public:
	User() {
	}

	User(User& user) {
		this->id = user.id;
		this->priority = user.priority;
	}

	void set_id(int id) {
		this->id = id;
	}

	void set_priority(int priority) {
		this->priority = priority;
	}

	int get_id() {
		return this->id;
	}

	int get_priority() {
		return this->priority;
	}
};