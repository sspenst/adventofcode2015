#include "days.h"

bool valid_pass(char pass[]) {
    bool straight = false;
    char repeat = 0;

    for (unsigned i = 0; i < 8; i++) {
        if (pass[i] == 'i' ||
            pass[i] == 'o' ||
            pass[i] == 'l')
            return false;
    }

    // check for straight
    for (unsigned i = 2; i < 8; i++) {
        if (pass[i-2] + 1 == pass[i-1] &&
            pass[i-1] + 1 == pass[i])
            straight = true;
    }

    if (straight == false)
        return false;

    // check for two pairs of letters
    for (unsigned i = 0; i < 7; i++) {
        if (pass[i] == pass[i+1]) {
            if (repeat == 0)
                repeat = pass[i];
            else if (repeat != pass[i])
                return true;
            i++;
        }
    }

    return false;
}

void increment_pass(char pass[]) {
    for (unsigned i = 0; i < 8; i++) {
        if (pass[7-i] == 'z') {
            pass[7-i] = 'a';
        } else {
            pass[7-i]++;
            return;
        }
    }
}

void day11() {
    char pass[9] = "hepxcrrq";

    while (!valid_pass(pass)) {
        increment_pass(pass);
    }

    cout << "Part 1: " << pass << endl;

    increment_pass(pass);

    while (!valid_pass(pass)) {
        increment_pass(pass);
    }

    cout << "Part 2: " << pass << endl;
}
