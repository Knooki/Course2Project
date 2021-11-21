#include "Main.h"
#include "User.h"
#include "HomePage.h"
#include "Admin.h"
#include "Customer.h"

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	HomePage enter;
	enter.logic();

	return(0);
}