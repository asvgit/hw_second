#include <iostream>
#include "lib.h"

namespace str {

StringVector split(const string &str, const char d) {
    StringVector r;

    string::size_type start = 0;
    string::size_type stop = str.find_first_of(d);
    while(stop != string::npos) {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

}
