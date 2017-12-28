#include "days.h"

#define INVALID 65536

class Gate {
    string wire_a;
    string wire_b;
    string wire_c;
    string op;

    public:
    Gate(vector<string>, string);
    bool issue(map<string, unsigned> &);
    static unsigned get_wire_val(map<string, unsigned> &, string);
};

Gate::Gate(vector<string> strs, string dest) {
    // parse the input vector into wires and an operation
    if (strs.size() == 1) {
        wire_a = strs[0];
        op = "IS";
    } else if (strs.size() == 2) {
        op = strs[0];
        wire_a = strs[1];
    } else {
        wire_a = strs[0];
        op = strs[1];
        wire_b = strs[2];
    }

    wire_c = dest;
}

bool Gate::issue(map<string, unsigned> & wires) {
    // check if the gate takes 1 or 2 wires, then retrieve
    // the wire values and execute the corresponding operation
    if (op == "NOT" || op == "IS") {
        unsigned a = get_wire_val(wires, wire_a);
        if (a == INVALID)
            return false;
        
        if (op == "NOT")
            wires[wire_c] = 65535 - a;
        else
            wires[wire_c] = a;
    } else {
        unsigned a = get_wire_val(wires, wire_a);
        unsigned b = get_wire_val(wires, wire_b);
        if (a == INVALID || b == INVALID)
            return false;

        if (op == "AND")
            wires[wire_c] = a & b;
        else if (op == "OR")
            wires[wire_c] = a | b;
        else if (op == "LSHIFT")
            wires[wire_c] = a << b;
        else if (op == "RSHIFT")
            wires[wire_c] = a >> b;
    }

    return true;
}

unsigned Gate::get_wire_val(map<string, unsigned> & wires, string wire) {
    try {
        // if the wire is just a number, return it
        return stoi(wire);
    } catch (const invalid_argument&) {
        // attempt to return the value of the wire
        if (wires.find(wire) != wires.end()) {
            return wires[wire];
        } else {
            return INVALID;
        }
    }
}

void resolve_wires(map<string, unsigned> & wires, vector<Gate> & gates) {
    while (gates.size() > 0) {
        for (unsigned i = 0; i < gates.size(); i++) {
            if (gates[i].issue(wires)) {
                gates.erase(gates.begin() + i);
                i--;
            }
        }
    }
}

void day07() {
    ifstream infile("input/day07.in");
    string line;
    map<string, unsigned> wires1;
    map<string, unsigned> wires2;
    vector<Gate> gates1;
    vector<Gate> gates2;

    // create a Gate for each line in the file, unless the line is an assignment
    while (getline(infile, line)) {
        vector<string> words = split(strip(line), " -> ");
        vector<string> strs = split(words[0], " ");

        if (strs.size() == 1) {
            try {
                unsigned val = stoi(words[0]);
                wires1[words[1]] = val;
            } catch (const invalid_argument&) {
                gates1.push_back(Gate(strs, words[1]));
            }
        } else {
            gates1.push_back(Gate(strs, words[1]));
        }
    }

    // store the initial wire and gate states for part 2
    wires2 = wires1;
    gates2 = gates1;

    // execute part 1
    resolve_wires(wires1, gates1);
    cout << "Part 1: " << wires1["a"] << endl;

    // execute part 2
    wires2["b"] = wires1["a"];
    resolve_wires(wires2, gates2);
    cout << "Part 2: " << wires2["a"] << endl;
}
