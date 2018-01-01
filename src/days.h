#include <algorithm>
#include <chrono>
#include <climits>
#include <fstream>
#include <iostream>
#include <iterator>
#include <json/src/json.hpp>
#include <map>
#include <openssl/md5.h>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <typeinfo>
#include <tuple>
#include <vector>

using namespace std;
using json = nlohmann::json;

typedef void(*day_fn)(void);

void day01();
void day02();
void day03();
void day04();
void day05();
void day06();
void day07();
void day08();
void day09();
void day10();
void day11();
void day12();
void day13();
void day14();
void day15();
void day16();
void day17();
void day18();
void day19();
void day20();
void day21();
void day22();
void day23();
void day24();
void day25();

vector<string> split(string, string);
string strip(string &);

extern vector<day_fn> day_fns;
