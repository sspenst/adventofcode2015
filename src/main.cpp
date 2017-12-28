#include "days.h"

// run the specified day and return the elapsed time
double run_day(unsigned day) {
	// time the execution of the specified day
	auto start_time = chrono::high_resolution_clock::now();
	day_fns[day - 1]();
	auto finish_time = chrono::high_resolution_clock::now();

	// calculate the elapsed time
	chrono::duration<double> elapsed = finish_time - start_time;
	cout << "Elapsed time: " << elapsed.count() << "s" << endl;
	return elapsed.count();
}

int main(int argc, char* argv[]) {
	// set the day to be executed
	unsigned day = 0;
	if (argc == 2)
		day = atoi(argv[1]);

	// if day is unspecified or 0, run all days
	if (day == 0) {
		double total_time = 0;

		for (unsigned d = 1; d <= day_fns.size(); d++) {
			cout << "Day " << d << ":" << endl;
			total_time += run_day(d);
			cout << endl;
		}

		cout << "Average time: " << total_time / day_fns.size() << "s" << endl;
		cout << "  Total time: " << total_time << "s" << endl;
		return 0;
	}

	// check for a valid day value
	if (day > day_fns.size()) {
		cout << "Invalid day specified." << endl;
		return 1;
	}

	run_day(day);

	return 0;
}
