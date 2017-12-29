#include "days.h"

pair<unsigned, unsigned> min_max_dist(
        map<pair<string, string>, unsigned> & loc_dist,
        set<string> & locs,
        vector<string> & visited) {
    if (visited.size() == locs.size())
        return make_pair(0, 0);

    unsigned min = UINT_MAX;
    unsigned max = 0;

    for (string loc : locs) {
        // check if we haven't yet visited loc
        if (find(visited.begin(), visited.end(), loc) == visited.end()) {
            // store the last visited element
            visited.push_back(loc);
            
            // calculate the total distance recursively
            auto dists = min_max_dist(loc_dist, locs, visited);
            if (visited.size() > 1) {
                unsigned d = loc_dist[make_pair(visited[visited.size() - 2], loc)];
                dists.first += d;
                dists.second += d;
            }

            // erase the last visited element
            visited.erase(visited.begin() + visited.size() - 1);

            if (dists.first < min) {
                min = dists.first;
            }

            if (dists.second > max) {
                max = dists.second;
            }
        }
    }

    return make_pair(min, max);
}

void day09() {
    ifstream infile("input/day09.in");
    string line;
    map<pair<string, string>, unsigned> loc_dist;
    set<string> locs;
    vector<string> visited;

    while (getline(infile, line)) {
        vector<string> strs = split(line, " = ");
        vector<string> loc = split(strs[0], " to ");

        // keep track of all locations
        locs.insert(loc[0]);
        locs.insert(loc[1]);

        // keep track of all distances between locations
        unsigned dist = stoi(strs[1]);
        loc_dist[make_pair(loc[0], loc[1])] = dist;
        loc_dist[make_pair(loc[1], loc[0])] = dist;
    }

    auto dists = min_max_dist(loc_dist, locs, visited);

    cout << "Part 1: " << dists.first << endl;
    cout << "Part 2: " << dists.second << endl;
}
