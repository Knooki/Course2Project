#include "Main.h"

int input_check() {
	int sw;
	while (!(wcin >> sw) || wcin.peek() != L'\n') {
		wcin.clear();
		wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
		error_message(L"�� ������ ������ ������ �����");
	}
	return sw;
}

int switch_sort() {
	system("cls");
	wcout << L"�������� �����:" << endl;
	wcout << L"1)� ���������� �������//�� ������������." << endl;
	wcout << L"2)�� � ���������� �������//�� ��������." << endl;
	wcout << L"3)�����." << endl;
	return input_check();
}

void error_message(wstring message) {
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	wcout << message << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

void complete_message(wstring message) {
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	wcout << message << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

bool check_date(wstring str, wstring type) {
	if (str.size() != 10) {
		error_message(L"���� ����� ���� ������ 10 ��������.");
		return false;
	}
	if (str[2] != L'.' || str[5] != L'.')
	{
		error_message(L"�������� ������ ����.");
		return false;
	}
	for (register int i = 0; i < 10; i++)
		if (!isdigit(str[i]) && str[i] != L'.')
		{
			error_message(L"� ���� ����� ���� ������ ����� � �����.");
			return false;
		}
	wstring date, month, year;
	date = str.substr(0, 2);
	month = str.substr(3, 2);
	year = str.substr(6, 4);
	int da, mo, ye;
	da = stoi(date);
	mo = stoi(month);
	ye = stoi(year);
	int flag = 0;
	time_t now = time(0);
	struct tm local;
	localtime_s(&local, &now);
	while (1) {
		if (ye < 1950) {
			error_message(L"��� �� ����� ���� ������ ������ ��� 1950");
			flag++;
			break;
		}
		if (type == L"stud")
			if (ye > local.tm_year + 1900 - 15)
			{
				error_message(L"������� �� ����� ���� ��������� �����.");
				flag++;
				break;
			}
		if (mo > 12 || mo == 0) {
			error_message(L"�������� ���������� �������.");
			flag++;
			break;
		}
		if (da > 31 || da == 0) {
			error_message(L"�������� ���������� ����.");
			flag++;
			break;
		}
		if (ye > local.tm_year + 1900)
		{
			error_message(L"��� ���� ��� �� ���������.");
			flag++;
			break;
		}
		if (ye == local.tm_year + 1900)
			if (mo > local.tm_mon + 1)
			{
				error_message(L"��� ���� ��� �� ���������.");
				flag++;
				break;
			}
		if (ye == local.tm_year + 1900)
			if (mo == local.tm_mon + 1)
				if (da > local.tm_mday)
				{
					error_message(L"��� ���� ��� �� ���������.");
					flag++;
					break;
				}
		if (ye % 4 == 0)
			if (mo == 2)
				if (da > 29 || da == 0)
				{
					error_message(L"� ���������� ��� � ������� �������� 29 �����.");
					flag++;
					break;
				}
		if (ye % 4 != 0)
			if (mo == 2)
				if (da > 28 || da == 0)
				{
					error_message(L"� �� ���������� ��� � ������� �������� 28 �����.");
					flag++;
					break;
				}
		if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
			if (da > 30) {
				error_message(L"�������� ���������� ����. � ���� ������ �������� 30 ����.");
				flag++;
				break;
			}
		break;
	}
	if (flag == 0) return true;
	else return false;
}

bool is_russian_alpha(wchar_t c) {
	return (c >= L'�' && c <= L'�' || c == L' ' || c == L'�' || c == L'�');
}

bool is_repeat_operation() {
	wcout << L"����� ���������� � ���� 2-�� ������ ������� ����� �������." << endl;
	wcout << L"����� ��������� � ���� ������� ������ ������� esc." << endl;
	return(_getwch() != 27);
}

wstring s_to_ws(const std::string& s)
{
	wstring ws;
	std::wstring wsTmp(s.begin(), s.end());

	ws = wsTmp;

	return ws;
}

string ws_to_s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}