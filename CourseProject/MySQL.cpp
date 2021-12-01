#include "Main.h"
#include "MySQL.h"

//admin
//knooki venia11let
//
//customer
//ksusha 12345

vector<vector<string>> MySQL::db_connection(string query)
{
	vector<vector<string>> result;

	// Получаем дескриптор соединения

	this->conn = mysql_init(&mysql);
	mysql_options(this->conn, MYSQL_SET_CHARSET_NAME, "cp1251");
	mysql_options(this->conn, MYSQL_INIT_COMMAND, "SET NAMES cp1251");

	if (this->conn == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		cout << stderr << " Error: can'tcreate MySQL-descriptor\n";
		//exit(1); //Если используется оконное приложение
	}

	//mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	//mysql_options(&mysql, MYSQL_INIT_COMMAND, "SET NAMES utf8");

	// Подключаемся к серверу
	if (!mysql_real_connect(this->conn, "localhost", "root", "venia11let", "course_project", NULL, NULL, 0))
	{
		// Если нет возможности установить соединение с сервером
		// базы данных выводим сообщение об ошибке
		cout << stderr << " Error: can'tconnecttodatabase %s\n" << mysql_error(this->conn) << endl;
	}

	//cout << "connectioncharacterset: " << mysql_character_set_name(this->conn) << endl;

	mysql_query(conn, query.c_str()); //Делаем запрос к таблице

	vector<string> row_;

	string item;
	char* ch = nullptr;

	if (this->res = mysql_store_result(this->conn)) {
		while (this->row = mysql_fetch_row(this->res)) {
			for (register int j = 0; j < mysql_num_fields(this->res); j++) {
				ch = new char[sizeof(row[j]) + 1];
				ch = row[j];
				if (ch == nullptr)
				{
					ch = new char[1];
					*ch = '\0';
				}
				item = string(ch);
				row_.push_back(item);
			}
			result.push_back(row_);
			row_.clear();
		}
	}
	else cout << stderr << mysql_error(conn);

	// Закрываем соединение с сервером базы данных
	mysql_close(this->conn);

	return result;
}