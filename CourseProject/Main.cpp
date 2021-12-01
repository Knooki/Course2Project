#include "Main.h"
#include "User.h"
#include "HomePage.h"
#include "Admin.h"
#include "Customer.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	User user;

	HomePage enter(&user);
	enter.logic();

	return(0);
}