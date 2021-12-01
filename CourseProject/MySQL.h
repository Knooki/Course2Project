#pragma once
#include "Main.h"
#include <mysql.h>

class MySQL {
	MYSQL* conn, mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;

public:

	vector<vector<string>> db_connection(string query);
};
