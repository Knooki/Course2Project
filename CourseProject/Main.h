#pragma once
#include <iostream>
#include <cstdlib>

#include <conio.h>
#include <cctype>
#include <cwchar>

#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include <cstdio>
#include <locale.h>
#include <ctime>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <stdlib.h>

#include <algorithm>
#include "C:\Users\user\source\repos\Coursach\Coursach\sha1.h"

#define NOMINMAX
#include <Windows.h>

using namespace std;
static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

int input_check();

void error_message(string message);

void complete_message(string message);

int switch_sort();

bool check_date(string str);
bool is_expired_date(string str);
string current_date();

bool is_russian_alpha(char c);
bool is_repeat_operation();
//wstring s_to_ws(const string& s);
//string ws_to_s(const std::wstring& wstr);

ostream& grey_cl(ostream& stream);

ostream& white_cl(ostream& stream);