#include "NumberUtils.h"

bool isNumber(const std::string &x) {
    std::regex e("^-?\\d+");
    return std::regex_match(x, e);
}
