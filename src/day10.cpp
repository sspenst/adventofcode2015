#include "days.h"

vector<char> look_and_say(vector<char> & s) {
    char cur = s[0];
    unsigned count = 1;
    vector<char> res;

    for (unsigned i = 1; i < s.size(); i++) {
        char next = s[i];
        if (next == cur) {
            count++;
        } else {
            res.push_back('0' + count);
            res.push_back(cur);
            cur = next;
            count = 1;
        }
    }

    res.push_back('0' + count);
    res.push_back(cur);
    return res;
}

void day10() {
    string in = "1113122113";
    vector<char> input(in.begin(), in.end());

    for (unsigned i = 0; i < 40; i++) {
        input = look_and_say(input);
    }

    cout << "Part 1: " << input.size() << endl;

    for (unsigned i = 0; i < 10; i++) {
        input = look_and_say(input);
    }

    cout << "Part 2: " << input.size() << endl;
}
