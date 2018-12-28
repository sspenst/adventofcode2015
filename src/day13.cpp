#include "days.h"

void combinations(vector<string> & vec, unsigned r) {
    unsigned n = vec.size();
    vector<bool> v(n);
    fill(v.begin(), v.begin() + r, true);

    do {
        for (unsigned i = 0; i < n; ++i) {
            if (v[i]) {
                std::cout << vec[i] << " ";
            }
        }
        std::cout << "\n";
    } while (std::prev_permutation(v.begin(), v.end()));
}

void day13() {
    ifstream infile("input/day13.in");
    string line;
    map<pair<string, string>, int> happiness;
    vector<string> names;

    while (getline(infile, line)) {
        vector<string> words = split(line, " ");
        string last = split(words[words.size() - 1], ".")[0];
        if (find(names.begin(), names.end(), last) == names.end())
            names.push_back(last);

        int units = stoi(words[3]);
        if (words[2] == "lose")
            units *= -1;

        happiness[make_pair(words[0], last)] = units;
    }

    combinations(names, 2);

    cout << happiness.size() << endl;
}
