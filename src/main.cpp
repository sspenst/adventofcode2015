#include "days.h"

vector<day_fn> day_fns = {
	day01,
	day02,
	day03,
	day04
};

int main(int argc, char* argv[]) {
	// set the day to be executed
	unsigned day = 1;
	if (argc == 2)
		day = atoi(argv[1]);

	// check for a valid day value
	if (day <= 0 || day > day_fns.size()) {
		cout << "Invalid day specified." << endl;
		return 1;
	}

	// run the corresponding day
	day_fns[day - 1]();

	return 0;
}
