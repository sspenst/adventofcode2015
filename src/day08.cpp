#include "days.h"

unsigned extra_decode_chars(string & code) {
    unsigned extra = 2;

    for (unsigned i = 1; i < code.length() - 1; i++) {
        if (code.at(i) == '\\') {
            if (code.at(i+1) == 'x') {
                extra += 3;
                i += 3;
            } else {
                extra++;
                i++;
            }
        }
    }

    return extra;
}

unsigned extra_encode_chars(string & code) {
    unsigned extra = 4;

    for (unsigned i = 1; i < code.length() - 1; i++) {
        if (code.at(i) == '\\' || code.at(i) == '\"') {
            extra++;
        }
    }

    return extra;
}

void day08() {
    ifstream infile("input/day08.in");
    string line;
    unsigned decode_chars = 0;
    unsigned encode_chars = 0;

    while (getline(infile, line)) {
        strip(line);
        decode_chars += extra_decode_chars(line);
        encode_chars += extra_encode_chars(line);
    }

    cout << "Part 1: " << decode_chars << endl;
    cout << "Part 2: " << encode_chars << endl;
}
