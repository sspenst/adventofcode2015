#include "days.h"

vector<day_fn> day_fns = {
    day01,
    day02,
    day03,
    day04,
    day05,
    day06,
    day07,
    day08,
    day09,
    day10,
    day11
};

vector<string> split(string s, string delim) {
    vector<string> tokens;
    size_t delim_len = delim.length();
    size_t pos = 0;

    while ((pos = s.find(delim)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delim_len);
    }

    tokens.push_back(s);

    return tokens;
}

string strip(string & s) {
    // ascii values corresponding to whitespace
    vector<unsigned> whitespace = {9, 10, 11, 12, 13, 32};

    // erase whitespace from the beginning of the string
    unsigned i = 0;
    while (find(whitespace.begin(), whitespace.end(), (unsigned)s.at(i))
            != whitespace.end()) {
        s.erase(i, 1);
    }

    // erase whitespace from the end of the string
    i = s.length() - 1;
    while (find(whitespace.begin(), whitespace.end(), (unsigned)s.at(i))
            != whitespace.end()) {
        s.erase(i, 1);
        i--;
    }

    return s;
}
