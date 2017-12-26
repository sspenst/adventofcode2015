#include "days.h"

void day01() {
	ifstream infile("input/day01.in");
	string text{ istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };

	int floor = 0;
	bool increment_pos = true;
	int pos = 0;

	for (char & c : text) {
		// part 1: floor counting
		if (c == '(') floor += 1;
		else if (c == ')') floor -= 1;
		
		// part 2: increment until total falls below 0
		if (increment_pos) pos += 1;
		if (floor < 0) increment_pos = false;
	}

	cout << "Part 1: " << floor << endl;
	cout << "Part 2: " << pos << endl;
}
