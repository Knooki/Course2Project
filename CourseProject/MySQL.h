#pragma once
#include "Main.h"
#include <mysql.h>

class MySQL {
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;

	string query;
public:

	vector<vector<wstring>> db_connection(wstring query);
};
