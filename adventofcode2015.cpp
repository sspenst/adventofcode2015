#include "src/days.h"

vector<day_fn> day_fns = { day01, day02 };

int main(int argc, char* argv[]) {
	// set the day to be executed
	unsigned day = 2;
	if (argc == 2)
		day = atoi(argv[1]);

	// call the corresponding day
	if (day <= 0 || day > day_fns.size())
		cout << "Invalid day specified." << endl;

	day_fns[day - 1]();
	return 0;
}
