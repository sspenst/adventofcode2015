#include "days.h"

vector<string> naughty_strs = {"ab", "cd", "pq", "xy"};
vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

bool nice1(string str) {
    unsigned vowel_count = 0;
    char prev = '.';
    char next;
    bool repeat = false;

    // check for naughty strings
    for (string s : naughty_strs) {
        if (str.find(s) != string::npos)
            return false;
    }

    // check if there are at least three vowels
    for (char c : str) {
        if (find(vowels.begin(), vowels.end(), c) != vowels.end()) {
            vowel_count++;
        }
    }

    if (vowel_count < 3)
        return false;

    // check for repeating letters
    for (char c : str) {
        next = c;
        if (prev == next) {
            repeat = true;
            break;
        }
        prev = next;
    }

    return repeat;
}

bool nice2(string str) {
    bool pair = false;
    bool repeat = false;

    for (unsigned i = 2; i < str.length(); i++) {
        // check for pairs of two letters
        string sub = str.substr(i-2, 2);
        string end = str.substr(i, str.length() - i);
        if (end.find(sub) != string::npos)
            pair = true;

        // check for matching chars
        if (str.at(i) == str.at(i-2))
            repeat = true;
    }

    return pair && repeat;
}

void day05() {
    ifstream infile("input/day05.in");
    string line;
    unsigned nice_strs1 = 0;
    unsigned nice_strs2 = 0;

    while (getline(infile, line)) {
        if (nice1(line))
            nice_strs1++;
        if (nice2(line))
            nice_strs2++;
    }

    cout << "Part 1: " << nice_strs1 << endl;
    cout << "Part 2: " << nice_strs2 << endl;
}
