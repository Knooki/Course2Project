#include "Main.h"
#include "MySQL.h"

//admin
//knooki venia11let
//
//customer
//ksusha 12345

vector<vector<wstring>> MySQL::db_connection(wstring query)
{
	vector<vector<wstring>> result;

	// �������� ���������� ����������
	this->conn = mysql_init(NULL);

	if (this->conn == NULL)
	{
		// ���� ���������� �� ������� � ������� ��������� �� ������
		wcout << stderr << L" Error: can'tcreate MySQL-descriptor\n";
		//exit(1); //���� ������������ ������� ����������
	}
	// ������������ � �������
	if (!mysql_real_connect(this->conn, "localhost", "root", "venia11let", "course_project", NULL, NULL, 0))
	{
		// ���� ��� ����������� ���������� ���������� � ��������
		// ���� ������ ������� ��������� �� ������
		wcout << stderr << L" Error: can'tconnecttodatabase %s\n" << mysql_error(this->conn) << endl;
	}

	mysql_set_character_set(this->conn, "utf8");
	string que = ws_to_s(query);
	mysql_query(this->conn, que.c_str()); //������ ������ � �������

	vector<wstring> row_;

	if (this->res = mysql_store_result(this->conn)) {
		for (register int i = 0; this->row = mysql_fetch_row(this->res); i++) {
			for (register int j = 0; j < mysql_num_fields(this->res); j++) {
				string item = row[j];
				row_.push_back(s_to_ws(item));
			}
			result.push_back(row_);
			row_.clear();
		}
	}
	else wcout << stderr << L"%s\n" << mysql_error(this->conn);

	// ��������� ���������� � �������� ���� ������
	mysql_close(this->conn);

	/*for (register int i = 0; i < result.size(); i++)
	{
		for (register int j = 0; j < result[i].size(); j++)
			wcout << result[i][j] << L" ";
		wcout << endl;
	}*/

	return result;
}