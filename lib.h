#pragma once

#include <string>
#include <vector>

typedef std::string string;
typedef std::vector<string> StringVector;

namespace str {

StringVector split(const string &str, const char d);

}
