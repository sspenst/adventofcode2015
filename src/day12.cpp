#include "days.h"

int sum_obj(json &, bool);

int sum_val(json & val, bool red) {
    int total = 0;

    if (val.is_number_integer()) {
        total += (int)val;
    } else if (val.is_array()) {
        for (unsigned i = 0; i < val.size(); i++) {
            total += sum_val(val[i], red);
        }
    } else if (val.is_object()) {
        total += sum_obj(val, red);
    }

    return total;
}

int sum_obj(json & j, bool red) {
    int total = 0;

    for (json::iterator it = j.begin(); it != j.end(); ++it) {
        if (!red && it.value().is_string() && it.value() == "red")
            return 0;
        total += sum_val(it.value(), red);
    }

    return total;
}

void day12() {
    ifstream infile("input/day12.in");
    string text{ istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };
    json j = json::parse(text);

    cout << "Part 1: " << sum_obj(j, true) << endl;
    cout << "Part 2: " << sum_obj(j, false) << endl;
}
