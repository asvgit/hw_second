#pragma once

#include <string>
#include <vector>

typedef std::string string;
typedef std::vector<string> StringVector;
typedef std::vector<int> IntVector;

namespace str {

StringVector split(const string &str, const char d);

}
