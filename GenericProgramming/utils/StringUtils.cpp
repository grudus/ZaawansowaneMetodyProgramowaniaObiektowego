#include "StringUtils.h"


std::vector<std::string> split(std::string &string, const std::string &regexString) {
    std::regex regex(regexString);

    std::sregex_token_iterator
            first{string.begin(), string.end(), regex, -1},
            last;

    return {first, last};
}

void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

