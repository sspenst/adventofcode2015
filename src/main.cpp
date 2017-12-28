#include "days.h"

vector<day_fn> day_fns = {
	day01,
	day02,
	day03,
	day04,
	day05
};

int main(int argc, char* argv[]) {
	// set the day to be executed
	unsigned day = 0;
	if (argc == 2)
		day = atoi(argv[1]);

	// if day is unspecified or 0, run all days
	if (day == 0) {
		for (unsigned i = 1; i <= day_fns.size(); i++) {
			cout << "Day " << i << ":" << endl;
			day_fns[i - 1]();
			if (i != day_fns.size())
				cout << endl;
		}
		return 0;
	}

	// check for a valid day value
	if (day > day_fns.size()) {
		cout << "Invalid day specified." << endl;
		return 1;
	}

	// run the corresponding day
	day_fns[day - 1]();

	return 0;
}
