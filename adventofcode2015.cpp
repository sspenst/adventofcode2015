// adventofcode2015.cpp : Defines the entry point for the console application.

#include "src/days.h"

day_fn day_fns[] = { day01 };

int main(int argc, char* argv[])
{
	// set the day to be executed
	int day = 1;
	if (argc == 2) day = atoi(argv[1]);

	// call the corresponding day
	day_fns[day - 1]();
	return 0;
}
