#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <openssl/md5.h>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;

typedef void(*day_fn)(void);

void day01();
void day02();
void day03();
void day04();
void day05();

vector<string> split(const string &, char);
