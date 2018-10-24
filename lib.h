#pragma once

#include <string>
#include <vector>

using vectop = std::vector<std::string>;
using string = std::string;
using StringVector = std::vector<string>;

namespace str {

StringVector split(const string &str, const char d);

}
