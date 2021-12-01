#include "Main.h"

int input_check() {
	int sw;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("�� ������ ������ ������ �����");
	}
	return sw;
}

int switch_sort() {
	system("cls");
	cout << "�������� �����:" << endl;
	cout << "1)� ���������� �������//�� ������������." << endl;
	cout << "2)�� � ���������� �������//�� ��������." << endl;
	cout << "3)�����." << endl;
	return input_check();
}

void error_message(string message) {
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	cout << message << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

void complete_message(string message) {
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	cout << message << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

bool check_date(string str) {
	if (str.size() != 10) {
		error_message("���� ����� ���� ������ 10 ��������.");
		return false;
	}
	if (str[4] != '-' || str[7] != '-')
	{
		error_message("�������� ������ ����.");
		return false;
	}
	for (register int i = 0; i < 10; i++)
		if (!isdigit(str[i]) && str[i] != '-')
		{
			error_message("� ���� ����� ���� ������ ����� � ����.");
			return false;
		}
	string date, month, year;
	date = str.substr(8, 2);
	month = str.substr(5, 2);
	year = str.substr(0, 4);

	int da, mo, ye;
	da = stoi(date);
	mo = stoi(month);
	ye = stoi(year);

	int flag = 0;
	time_t now = time(0);
	struct tm local;
	localtime_s(&local, &now);

	if (mo > 12 || mo == 0) {
		error_message("�������� ���������� �������.");
		return false;
	}
	if (da > 31 || da == 0) {
		error_message("�������� ���������� ����.");
		return false;
	}
	if (ye % 4 == 0)
		if (mo == 2)
			if (da > 29 || da == 0)
			{
				error_message("� ���������� ��� � ������� �������� 29 �����.");
				return false;
			}
	if (ye % 4 != 0)
		if (mo == 2)
			if (da > 28 || da == 0)
			{
				error_message("� �� ���������� ��� � ������� �������� 28 �����.");
				return false;
			}
	if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
		if (da > 30) {
			error_message("�������� ���������� ����. � ���� ������ �������� 30 ����.");
			return false;
		}
	return true;
}

bool is_expired_date(string str) { //true if expired
	if (check_date(str))
	{
		time_t now = time(0);
		struct tm local;
		localtime_s(&local, &now);

		string date, month, year;
		date = str.substr(8, 2);
		month = str.substr(5, 2);
		year = str.substr(0, 4);
		int da, mo, ye;
		da = stoi(date);
		mo = stoi(month);
		ye = stoi(year);

		if (ye > local.tm_year) return true;
		else if (ye < local.tm_year) return false;
		else {
			if (mo > local.tm_mon) return true;
			else if (mo < local.tm_mon) return false;
			else
				return (da > local.tm_mday) ? true : false;
		}
	}
	else
		return false;
}

bool is_russian_alpha(char c) {
	return (c >= '�' && c <= '�' || c == ' ' || c == '�' || c == '�');
}

bool is_repeat_operation() {
	cout << "����� ���������� � ���� ���� ������� ����� �������." << endl;
	cout << "����� ��������� � ���� ����� ������� esc." << endl;
	return(_getch() != 27);
}

string current_date() {
	string cur_date;

	time_t now = time(0);
	struct tm local;
	localtime_s(&local, &now);

	cur_date = to_string(local.tm_year + 1900) + "-" + to_string(local.tm_mon) + "-" + to_string(local.tm_mday);

	return cur_date;
}

//
//wstring s_to_ws(const std::string& s)
//{
//	std::wstring ws(s.begin(), s.end());
//
//	return ws;
//}
//
//string ws_to_s(const std::wstring& wstr)
//{
//	using convert_typeX = std::codecvt_utf8<wchar_t>;
//	std::wstring_convert<convert_typeX, wchar_t> converterX;
//
//	return converterX.to_bytes(wstr);
//}

ostream& grey_cl(ostream& stream) {
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
	return stream;
}

ostream& white_cl(ostream& stream) {
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	return stream;
}