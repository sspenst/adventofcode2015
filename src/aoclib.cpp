#include "days.h"

vector<day_fn> day_fns = {
    day01,
    day02,
    day03,
    day04,
    day05,
    day06
};

template<typename Out>
void split(const string &s, char delim, Out result) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}
