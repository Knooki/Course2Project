#include "Main.h"

int input_check() {
	int sw;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("Вы можете ввести только цифры");
	}
	return sw;
}

int switch_sort() {
	system("cls");
	cout << "Выбериет опцию:" << endl;
	cout << "1)В алфавитном порядке//по возврастанию." << endl;
	cout << "2)Не в алфавитном порядке//по убыванию." << endl;
	cout << "3)Выход." << endl;
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
		error_message("Дата дожна быть длиной 10 символов.");
		return false;
	}
	if (str[4] != '-' || str[7] != '-')
	{
		error_message("Неверный формат даты.");
		return false;
	}
	for (register int i = 0; i < 10; i++)
		if (!isdigit(str[i]) && str[i] != '-')
		{
			error_message("В дате могут быть только цифры и тире.");
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
		error_message("Неверное количество месяцев.");
		return false;
	}
	if (da > 31 || da == 0) {
		error_message("Неверное количество дней.");
		return false;
	}
	if (ye % 4 == 0)
		if (mo == 2)
			if (da > 29 || da == 0)
			{
				error_message("В високосный год в феврале максимум 29 чисел.");
				return false;
			}
	if (ye % 4 != 0)
		if (mo == 2)
			if (da > 28 || da == 0)
			{
				error_message("В не високосный год в феврале максимум 28 чисел.");
				return false;
			}
	if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
		if (da > 30) {
			error_message("Неверное количество дней. В этом месяце максимум 30 дней.");
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
	return (c >= 'А' && c <= 'я' || c == ' ' || c == 'Ё' || c == 'ё');
}

bool is_repeat_operation() {
	cout << "Чтобы продолжить в этом окне нажмите любую клавишу." << endl;
	cout << "Чтобы вернуться в меню Назад нажмите esc." << endl;
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