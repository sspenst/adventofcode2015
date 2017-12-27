#include "days.h"

#define SECRET_KEY "bgvyzdsv"

void day04() {
    unsigned char digest[MD5_DIGEST_LENGTH];
    unsigned num = 1;
    bool five_zeros = false;

    while (true) {
        string str(SECRET_KEY + to_string(num));
        
        MD5((unsigned char *)str.c_str(), str.length(), (unsigned char *)&digest);

        unsigned a = digest[0];
        unsigned b = digest[1];
        unsigned c = digest[2];

        if (!five_zeros && a == 0 && b == 0 && c < 16) {
            cout << "Part 1: " << num << endl;
            five_zeros = true;
        }

        if (a == 0 && b == 0 && c == 0) {
            cout << "Part 2: " << num << endl;
            break;
        }

        num += 1;
    }
}
