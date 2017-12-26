#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef void(*day_fn)(void);

void day01();
void day02();

vector<string> split(const string &, char);
