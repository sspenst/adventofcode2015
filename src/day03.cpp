#include "days.h"

unsigned part1(string input) {
	int x = 0, y = 0;
	set<tuple<int, int>> locations;

	locations.insert(make_tuple(x, y));

	for (char & c : input) {
		switch (c) {
		case '^':
			y += 1;
			break;
		case '>':
			x += 1;
			break;
		case 'v':
			y -= 1;
			break;
		case '<':
			x -= 1;
			break;
		}
		locations.insert(make_tuple(x, y));
	}

	return locations.size();
}

unsigned part2(string input) {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	bool robo_santa = false;
	set<tuple<int, int>> locations;

	locations.insert(make_tuple(x1, y1));

	for (char & c : input) {
		int x = 0;
		int y = 0;

		switch (c) {
		case '^':
			y += 1;
			break;
		case '>':
			x += 1;
			break;
		case 'v':
			y -= 1;
			break;
		case '<':
			x -= 1;
			break;
		}

		if (!robo_santa) {
			x1 += x;
			y1 += y;
			locations.insert(make_tuple(x1, y1));
		} else {
			x2 += x;
			y2 += y;
			locations.insert(make_tuple(x2, y2));
		}

		robo_santa ^= true;
	}

	return locations.size();
}

void day03() {
	ifstream infile("input/day03.in");
	string input{ istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };

	cout << "Part 1: " << part1(input) << endl;
	cout << "Part 2: " << part2(input) << endl;
}
