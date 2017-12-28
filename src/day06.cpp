#include "days.h"

void apply_inst(bool lights1[][1000], unsigned lights2[][1000], string inst) {
    vector<string> words = split(inst, " ");
    unsigned i = 0;
    unsigned op = 0; // 0 is turn off, 1 is turn on, 2 is toggle
    unsigned x1, y1, x2, y2;

    // get operation to perform
    if (words[i++] == "turn") {
        if (words[i++] == "on") {
            op = 1;
        }
    } else {
        op = 2;
    }

    // get start coords
    vector<string> start = split(words[i++], ",");
    x1 = stoi(start[0]);
    y1 = stoi(start[1]);

    // get finish coords
    vector<string> finish = split(words[++i], ",");
    x2 = stoi(finish[0]);
    y2 = stoi(finish[1]);

    // apply lighting
    for (unsigned y = y1; y <= y2; y++) {
        for (unsigned x = x1; x <= x2; x++) {
            switch (op) {
            case 0:
                lights1[y][x] = false;
                if (lights2[y][x] > 0)
                    lights2[y][x]--;
                break;
            case 1:
                lights1[y][x] = true;
                lights2[y][x]++;
                break;
            case 2:
                lights1[y][x] ^= true;
                lights2[y][x] += 2;
                break;
            }
        }       
    }
}

void day06() {
    ifstream infile("input/day06.in");
    string line;
    bool lights1[1000][1000] = {0};
    unsigned lights2[1000][1000] = {0};
    unsigned on_lights1 = 0;
    unsigned on_lights2 = 0;

    while (getline(infile, line)) {
        apply_inst(lights1, lights2, line);
    }

    for (unsigned y = 0; y < 1000; y++) {
        for (unsigned x = 0; x < 1000; x++) {
            on_lights1 += lights1[y][x];
            on_lights2 += lights2[y][x];
        }
    }

    cout << "Part 1: " << on_lights1 << endl;
    cout << "Part 2: " << on_lights2 << endl;
}
