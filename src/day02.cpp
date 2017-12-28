#include "days.h"

void day02() {
	ifstream infile("input/day02.in");
	string line;
	unsigned paper = 0;
	unsigned ribbon = 0;

	while (getline(infile, line)) {
		vector<string> dimensions = split(line, "x");
		unsigned l = stoi(dimensions[0]);
		unsigned w = stoi(dimensions[1]);
		unsigned h = stoi(dimensions[2]);

		unsigned sa = 2 * l * w + 2 * w * h + 2 * h * l;
		sa += min({ l*w, w*h, h*l });
		paper += sa;

		unsigned r = l*w*h;
		r += min({ 2 * (l + w), 2 * (w + h), 2 * (h + l) });
		ribbon += r;
	}

	cout << "Part 1: " << paper << endl;
	cout << "Part 2: " << ribbon << endl;
}
