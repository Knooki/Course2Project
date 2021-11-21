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

#include <algorithm>
#include "C:\Users\user\source\repos\Coursach\Coursach\sha1.h"

#define NOMINMAX
#include <Windows.h>

using namespace std;
static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

int input_check();

void error_message(wstring message);

void complete_message(wstring message);

int switch_sort();

bool check_date(wstring str, wstring type);
bool is_russian_alpha(wchar_t c);
bool is_repeat_operation();
wstring s_to_ws(const string& s);
string ws_to_s(const std::wstring& wstr);